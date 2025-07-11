#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 40   // 数组容量

#define PUSH 0
#define POP 1
#define GET_TOP 2
#define STACK_EMPTY 3
#define EXIT -1

typedef int DataType;
typedef struct
{
    DataType data[MaxSize];
    int top; // 栈顶指针
} Stack;     // 结构体类型名

/**
 * 初始化一个栈
 * @param S
 */
void InitStack(Stack *S)
{
    S->top = -1;
}

/**
 * 向栈插入一个元素
 * @param S 操作栈
 * @param e 操作数
 * @return 成功返回1，否则返回0
 */
bool Push(Stack *S, DataType e)
{
    if (S->top == MaxSize - 1)
    {
        return false;
    }
    else
    {
        S->data[++S->top] = e;
        return true;
    }

}

/**
 * 从栈中弹出一个元素
 * @param S 操作栈
 * @param e 接受栈弹出的值
 * @return 成功返回1，否则返回0
 */
bool Pop(Stack *S, DataType *e)
{
    if(S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}

/**
 * 获取栈顶元素，不删除该元素
 * @param S 操作栈
 * @param e 接受栈顶元素
 * @return 成功返回1，否则返回0
 */
bool GetTop(Stack S, DataType *e)
{
    if (S.top == -1)
    {
        return false;
    }
    else
    {
        *e = S.data[S.top];
        return true;
    }
}

/**
 * 判断栈是否空，为空返回1，否则返回0
 * @param S
 * @return
 */
bool StackEmpty(Stack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/**
 * 获取栈的一个数组拷贝
 * @param S 操作栈
 * @param seq 栈中元素的一个拷贝
 */
void StackToArray(Stack S, DataType *seq)
{
    int i = 0;
    for (; i <= S.top; i++)
    {
        seq[i] = S.data[S.top-i]; // 自栈顶至栈底
    }
}

/**
 * 返回栈已使用长度
 * @param S 操作栈
 * @return 返回栈的长度
 */
int StackLength(Stack S)
{
    return S.top + 1;
}


void outputStack(Stack *S)
{
    int seq[MaxSize], i = 0;
    StackToArray(*S, seq);
    printf("Stack: ");
    for (i = 0; i < StackLength(*S); i++)
    {
        printf("%d", seq[i]);
        if(i<StackLength(*S)-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    InitStack(S);
    int mode, num, e, status;
    while (scanf("%d", &mode))
    {
        if (mode == EXIT)
        {
            break;
        }
        switch (mode)
        {
        case PUSH:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                scanf("%d", &e);
                status = Push(S, e);
            }
            outputStack(S);
            break;
        case POP:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                status = Pop(S, &e);
                if(status)
                {
                    printf("Pop: %d\n", e);
                    outputStack(S);
                }
                else
                {
                    printf("Pop failed\n");
                }
            }
            break;
        case GET_TOP:
            status = GetTop(*S, &e);
            if(status)
            {
                printf("GetTop: %d\n", e);
                outputStack(S);
            }
            else
            {
                printf("GetTop failed\n");
            }
            break;
        case STACK_EMPTY:
            status = StackEmpty(*S);
            if(status)
            {
                printf("The Stack is Empty\n");
            }
            else
            {
                printf("The Stack is not Empty\n");
                outputStack(S);
            }
            break;
        default:
            break;
        }
    }
    free(S);
    return 0;
}