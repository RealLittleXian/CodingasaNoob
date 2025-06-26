#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

bool Pair(char l, char r) {
    return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
}

bool Valid(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char cur = s[i];
        if (cur == '(' || cur == '[' || cur == '{') {
            push(cur);
        } else if (cur == ')' || cur == ']' || cur == '}') {
            if (top == -1 || !Pair(pop(), cur)) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char input[1001];
    scanf("%s", input);
    
    if (Valid(input)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}