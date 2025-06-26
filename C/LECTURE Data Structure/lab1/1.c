#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    // 将栈顶指针置为-1，表示栈为空
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

void mergeTrains(int *track1, int size1, int *track2, int size2) {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    for (int i = 0; i < size1; i++) {
        push(&stack1, track1[i]);
    }
    for (int i = 0; i < size2; i++) {
        push(&stack2, track2[i]);
    }

    int result[MAX];
    int index = 0;

    while (!isEmpty(&stack1) || !isEmpty(&stack2)) {
        int car1 = isEmpty(&stack1) ? -1 : peek(&stack1);
        int car2 = isEmpty(&stack2) ? -1 : peek(&stack2);

        if (car1 == -1) {
            result[index++] = pop(&stack2);
        } else if (car2 == -1) {
            result[index++] = pop(&stack1);
        } else if (car1 < car2) {
            result[index++] = pop(&stack1);
        } else {
            result[index++] = pop(&stack2);
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int track1[MAX], track2[MAX];
    int size1 = 0, size2 = 0;
    char line[256];

    if (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " ");
        while (token != NULL && size1 < MAX) {
            int num = atoi(token);
            if (num > 0) {
                track1[size1++] = num; 
            }
            token = strtok(NULL, " ");
        }
    }

    if (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " ");
        while (token != NULL && size2 < MAX) {
            int num = atoi(token);
            if (num > 0) {
                track2[size2++] = num; 
            }
            token = strtok(NULL, " ");
        }
    }

    mergeTrains(track1, size1, track2, size2);

    return 0;
}