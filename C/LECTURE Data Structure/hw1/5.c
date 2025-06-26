#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int data[100];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int evaluateRPN(char tokens[][20], int n) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < n; i++) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            push(&stack, atoi(tokens[i]));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            switch (tokens[i][0]) {
                case '+':
                    push(&stack, a + b);
                    break;
                case '-':
                    push(&stack, a - b);
                    break;
                case '*':
                    push(&stack, a * b);
                    break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, a / b);
                    break;
                default:
                    printf("Unknown operator: %s\n", tokens[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (stack.top != 0) {
        printf("Invalid RPN expression\n");
        exit(EXIT_FAILURE);
    }
    return pop(&stack);
}

int main() {
    int n;
    scanf("%d", &n);

    char tokens[n][20];
    for (int i = 0; i < n; i++) {
        scanf("%s", tokens[i]);
    }

    int result = evaluateRPN(tokens, n);
    printf("%d\n", result);

    return 0;
}

// part of GPT gernerated