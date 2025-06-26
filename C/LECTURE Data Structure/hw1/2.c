#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *s) {
    char str[1000];
    int index = 0;

    for (int i = 0; s[i]; i++) {
        if (isalnum(s[i])) {
            str[index++] = tolower(s[i]);
        }
    }
    str[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        if (str[i] != str[index - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = 0;

    if (is_palindrome(input)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}