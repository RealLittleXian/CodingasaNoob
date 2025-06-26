#include <stdio.h>
#include <string.h>

void reverse(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseSegments(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        if (i + k <= len) {
            reverse(s, i, i + k - 1);
        } else {
            reverse(s, i, len - 1);
        }
    }
}

int main() {
    char s[100];
    int k;

    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; 

    scanf("%d", &k);

    reverseSegments(s, k);
    printf("%s", s);

    return 0;
}