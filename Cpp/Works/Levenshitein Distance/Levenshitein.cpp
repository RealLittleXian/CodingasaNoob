#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

// 自定义的字符串处理函数，用于删除中文字符
std::string removeChineseCharacters(std::string str) {
    std::string result;
    for (char c : str) {
        if (c < 0 || c > 127) {
            continue;
        }
        result += c;
    }
    return result;
}

// 自定义的字符串处理函数，用于按指定分隔符分割字符串为单词列表
std::vector<std::string> splitString(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

// 自定义的拼写纠正函数，基于Levenshtein编辑距离算法
std::string correctSpelling(std::string word, const std::vector<std::string>& dictionary) {
    std::string correctedWord = word;
    int minDistance = word.length();
    for (const std::string& dictWord : dictionary) {
        int distance = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != dictWord[i]) {
                distance++;
            }
        }
        if (distance < minDistance) {
            minDistance = distance;
            correctedWord = dictWord;
        }
    }
    return correctedWord;
}

int main() {
    std::map<int, std::vector<std::string>> words;
    std::map<int, std::string> corrections;
    std::vector<std::string> dictionary;

    // 读取单词表（vocabulary.txt）
    std::ifstream vocabularyFile("vocabulary.txt");
    if (vocabularyFile.is_open()) {
        std::string line;
        while (getline(vocabularyFile, line)) {
            dictionary.push_back(line);
        }
        vocabularyFile.close();
    }
    else {
        std::cout << "Unable to open vocabulary file." << std::endl;
        return 1;
    }

    // 读取给定文档（words.txt）
    std::ifstream wordsFile("words.txt");
    if (wordsFile.is_open()) {
        std::string line;
        int lineNumber = 1;
        while (getline(wordsFile, line)) {
            std::string cleanedLine = removeChineseCharacters(line);
            std::vector<std::string> wordList = splitString(cleanedLine, ' ');
            std::vector<std::string> correctedWords;
            for (const std::string& word : wordList) {
                std::string correctedWord = correctSpelling(word, dictionary);
                correctedWords.push_back(correctedWord);
                if (correctedWord != word) {
                    corrections[lineNumber] += (corrections[lineNumber].empty() ? "" : "/") + correctedWord;
                }
            }
            words[lineNumber] = correctedWords;
            lineNumber++;
        }
        wordsFile.close();
    }
    else {
        std::cout << "Unable to open words file." << std::endl;
        return 1;
    }

    // 写入纠正后的结果到输出文件（words_correct.txt）
    std::ofstream outputFile("words_correct.txt");
    if (outputFile.is_open()) {
        for (const auto& entry : words) {
            int lineNumber = entry.first;
            const std::vector<std::string>& wordList = entry.second;
            std::string correction = corrections[lineNumber];
            outputFile << lineNumber;
            for (const std::string& word : wordList) {
                outputFile << " " << word;
            }
            if (!correction.empty()) {
                outputFile << "/" << correction;
            }
            outputFile << std::endl;
        }
        outputFile.close();
    }
    else {
        std::cout << "Unable to open output file." << std::endl;
        return 1;
    }

    std::cout << "Correction completed. Please check words_correct.txt for the corrected words." << std::endl;

    return 0;
}