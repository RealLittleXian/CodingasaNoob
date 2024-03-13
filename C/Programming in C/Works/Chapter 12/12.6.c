#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100
typedef struct node {
int type;
union {
int ival;
double dval;
}dat;
}NodeType;
typedef struct stack {
    int top;
    NodeType items[STACK_SIZE];
} Stack;

void push(Stack *s, NodeType item) {
    if (s->top < STACK_SIZE - 1) {
        s->top++;
        s->items[s->top] = item;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

NodeType pop(Stack *s) {
    if (s->top >= 0) {
        NodeType item = s->items[s->top];
        s->top--;
        return item;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

NodeType evaluate(char *expression) {
    Stack stack;
    stack.top = -1;

    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            // 数字
            NodeType node;
            if (stack.items[stack.top].type == 0) {
                node.type = 0;
                node.dat.ival = atoi(&expression[i]);
            } else {
                node.type = 1;
                node.dat.dval = atof(&expression[i]);
            }
            push(&stack, node);

            while (isdigit(expression[i]))
                i++;
        } else if (isOperator(expression[i])) {
            // 运算符
            NodeType operand2 = pop(&stack);
            NodeType operand1 = pop(&stack);
            NodeType result;

            if (operand1.type == 0 && operand2.type == 0) {
                // 两个都是整数
                result.type = 0;
                switch (expression[i]) {
                    case '+':
                        result.dat.ival = operand1.dat.ival + operand2.dat.ival;
                        break;
                    case '-':
                        result.dat.ival = operand1.dat.ival - operand2.dat.ival;
                        break;
                    case '*':
                        result.dat.ival = operand1.dat.ival * operand2.dat.ival;
                        break;
                    case '/':
                        result.dat.ival = operand1.dat.ival / operand2.dat.ival;
                        break;
                }
            } else {
                // 至少有一个是浮点数
                double val1, val2;
                if (operand1.type == 0)
                    val1 = (double)operand1.dat.ival;
                else
                    val1 = operand1.dat.dval;
                if (operand2.type == 0)
                    val2 = (double)operand2.dat.ival;
                else
                    val2 = operand2.dat.dval;

                result.type = 1;
                switch (expression[i]) {
                    case '+':
                        result.dat.dval = val1 + val2;
                        break;
                    case '-':
                        result.dat.dval = val1 - val2;
                        break;
                    case '*':
                        result.dat.dval = val1 * val2;
                        break;
                    case '/':
                        result.dat.dval = val1 / val2;
                        break;
                }
            }

            push(&stack, result);
            i++;
        } else {
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Enter the postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    NodeType result = evaluate(expression);

    if (result.type == 0)
        printf("Result: %d\n", result.dat.ival);
    else
        printf("Result: %lf\n", result.dat.dval);

    return 0;
}