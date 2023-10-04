#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自定义的字符串处理函数，用于删除中文字符
void removeChineseCharacters(char* str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((unsigned char)str[i] < 128) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// 自定义的字符串处理函数，用于按指定分隔符分割字符串为单词列表
void splitString(char* str, char delimiter, char** result, int* resultSize) {
    char* token = strtok(str, &delimiter);
    *resultSize = 0;
    while (token != NULL) {
        result[*resultSize] = token;
        (*resultSize)++;
        token = strtok(NULL, &delimiter);
    }
}

// 自定义的拼写纠正函数，基于Levenshtein编辑距离算法
void correctSpelling(char* word, char** dictionary, int dictionarySize, char* correctedWord) {
    strcpy(correctedWord, word);
    int minDistance = strlen(word);
    for (int i = 0; i < dictionarySize; i++) {
        int distance = 0;
        for (int j = 0; j < strlen(word); j++) {
            if (word[j] != dictionary[i][j]) {
                distance++;
            }
        }
        if (distance < minDistance) {
            minDistance = distance;
            strcpy(correctedWord, dictionary[i]);
        }
    }
}

int main() {
    FILE* vocabularyFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/vocabulary.txt", "r");
    if (vocabularyFile == NULL) {
        printf("Unable to open vocabulary file.\n");
        return 1;
    }

    char** dictionary = NULL;
    int dictionarySize = 0;
    char line[256];
    while (fgets(line, sizeof(line), vocabularyFile)) {
        line[strcspn(line, "\n")] = '\0'; // 删除换行符
        dictionary = realloc(dictionary, (dictionarySize + 1) * sizeof(char*));
        dictionary[dictionarySize] = malloc(strlen(line) + 1);
        strcpy(dictionary[dictionarySize], line);
        dictionarySize++;
    }
    fclose(vocabularyFile);

    FILE* wordsFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/words.txt", "r");
    if (wordsFile == NULL) {
        printf("Unable to open words file.\n");
        return 1;
    }

    FILE* outputFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/words_correct.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open output file.\n");
        return 1;
    }

    int lineNumber = 1;
    while (fgets(line, sizeof(line), wordsFile)) {
        line[strcspn(line, "\n")] = '\0'; // 删除换行符
        char cleanedLine[256];
        strcpy(cleanedLine, line);
        removeChineseCharacters(cleanedLine);

        char* tokens[256];
        int tokenCount;
        splitString(cleanedLine, ' ', tokens, &tokenCount);

        char correctedWords[256][256];
        char corrections[256];
        corrections[0] = '\0';

        for (int i = 0; i < tokenCount; i++) {
            correctSpelling(tokens[i], dictionary, dictionarySize, correctedWords[i]);
            if (strcmp(correctedWords[i], tokens[i]) != 0) {
                strcat(corrections, "/");
                strcat(corrections, correctedWords[i]);
            }
        }

        fprintf(outputFile, "%d", lineNumber);
        for (int i = 0; i < tokenCount; i++) {
            fprintf(outputFile, " %s", correctedWords[i]);
        }
        if (strlen(corrections) > 0) {
            fprintf(outputFile, "%s", corrections);
        }
        fprintf(outputFile, "\n");

        lineNumber++;
    }

    fclose(wordsFile);
    fclose(outputFile);

    printf("Correction completed. Please check words_correct.txt for the corrected words.\n");

    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}
