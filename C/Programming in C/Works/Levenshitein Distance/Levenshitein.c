#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

// custom string processing function to remove Chinese characters
void removeChineseCharacters(char* str) {
int j = 0;
for (int i = 0; str[i] != '\0'; i++) {
if ((unsigned char)str[i] < 128) {
str[j++] = str[i];
}
}
str[j] = '\0';
}

// function to find the minimum
int min(int a, int b, int c) {
if (a < b && a < c)
return a;
else if (b < a && b < c)
return b;
else
return c;
}

// Function to calculate the Levenshtein distance between two words
int editDistance(char* word1, char* word2) {
int m = strlen(word1);
int n = strlen(word2);
int dp[m+1][n+1];   //dynamic programming

// Initialize the first row and column of the dp matrix. dp stands for Dynamic programming.
for (int i = 0; i <= m; i++)
    dp[i][0] = i;
for (int j = 0; j <= n; j++)
    dp[0][j] = j;

// Calculate the minimum edit distance. (Core algorithm pt.1)
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (word1[i-1] == word2[j-1])
            dp[i][j] = dp[i-1][j-1];
        else
            dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
    }
}

return dp[m][n];
}

// Function to process each line of the words file
void processLine(char* line, FILE* correctWordsFile, char vocabulary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int vocabCount) {

char* token = strtok(line, " /");   // Split the line into line number and word list; then split word 1, to match the output format
fprintf(correctWordsFile, "%s ", token);
token = strtok(NULL, " /");
fprintf(correctWordsFile, "%s ", token);
token = strtok(NULL, " /");

// Process each word in the line
while (token != NULL) {
    int found = 0;  // Check if the word is in the vocabulary
    for (int i = 0; i < vocabCount; i++) {
        if (strcmp(token, vocabulary[i]) == 0) {
            found = 1;
            break;
        }
    }

    // if the word is not in the vocabulary, try to correct it
    if (!found) {
        char correctedWord[MAX_WORD_LENGTH] = " ";
        int minDistance = INT_MAX;

        // find the word in the vocabulary with the minimum edit distance.(Core algorithm pt.2)
        for (int i = 0; i < vocabCount; i++) {
            int distance = editDistance(token, vocabulary[i]);
            if (distance < minDistance) {
                minDistance = distance;
                strcpy(correctedWord, vocabulary[i]);
            }
        }

        fprintf(correctWordsFile, "%s/", correctedWord);
    } else {
        fprintf(correctWordsFile, "%s/", token);
    }

    token = strtok(NULL, " /");
}

// Remove the last slash in the line and add a new line character
fseek(correctWordsFile, 0, SEEK_END); // move to the end of the file
long size = ftell(correctWordsFile); // get file pointer position
fseek(correctWordsFile, size - 1, SEEK_SET); // move to the last character '/'
ftruncate(fileno(correctWordsFile), size - 1); // then truncate the file 

fprintf(correctWordsFile, "\n");
}

int main() {
FILE *vocabFile, *wordsFile, *correctWordsFile;
char line[MAX_LINE_LENGTH];
int lineNumber = 0;

// Open the files
vocabFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/vocabulary.txt", "r");
wordsFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/words.txt", "r");
correctWordsFile = fopen("D:/Coding/Coding/C/Programming in C/Works/Levenshitein Distance/words_correct.txt", "w");

if (vocabFile == NULL || wordsFile == NULL || correctWordsFile == NULL) {
    printf("failed to open files.\n");
    exit(1);
}

// Read the vocabulary
char vocabulary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
int vocabCount = 0;

while (fgets(line, sizeof(line), vocabFile) != NULL) {
    line[strcspn(line, "\n")] = '\0'; // Remove the newline character at the end of the line
    strcpy(vocabulary[vocabCount], line);
    vocabCount++;
}

// Process each line
while (fgets(line, sizeof(line), wordsFile) != NULL) {
    lineNumber++;
    line[strcspn(line, "\n")] = '\0'; // Remove the newline character at the end of the line
    removeChineseCharacters(line);

    processLine(line, correctWordsFile, vocabulary, vocabCount);
}

// close files
fclose(vocabFile);
fclose(wordsFile);
fclose(correctWordsFile);

printf("output successfully. check words_correct.txt.\n");

return 0;
}
