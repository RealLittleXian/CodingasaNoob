#include <stdio.h>
#include <string.h>

int isSubstring(char *str, char *subStr) {
    int i, j;
    int strLen = strlen(str);
    int subStrLen = strlen(subStr);

    for (i = 0; i <= strLen - subStrLen; i++) {
        for (j = 0; j < subStrLen; j++) {
            if (str[i + j] != subStr[j])
                break;
        }
        if (j == subStrLen)
            return 1; // 子串匹配成功
    }
    return 0; // 子串未匹配成功
}

int main() {
    char strA[80];
    char strB[80];

    fgets(strA, sizeof(strA), stdin);
    strA[strlen(strA) - 1] = '\0';
    
    fgets(strB, sizeof(strB), stdin);
    strB[strlen(strB) - 1] = '\0';

    if (isSubstring(strA, strB))
        printf("Yes");
    else
        printf("No");

    return 0;
}