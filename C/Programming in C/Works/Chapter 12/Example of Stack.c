#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct stack
{
    int *data;
    struct stack *next;
} STACK;

STACK *head, *pr;
int nodeNum = 0;

STACK *createNode(int num);
STACK *pushStack(int num);
int popStack(void);

int main()
{

    int popNum[N], pushNum[N], i;
    for (i = 0; i < N; i++)
    {
        pushNum[i] = i + 1;
    }

    for (i = 0; i < N; i++)
    {
        pushStack(pushNum[i]);
        printf("push #%d data\t%d\n", i + 1, pushNum[i]);
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        popNum[i] = popStack();
        printf("pop #%d data\t%d\n", N - i, popNum[i]);
    }
}

STACK *createNode(int num)
{
    STACK *p;
    p = (int *)malloc(sizeof(STACK));
    if (p == NULL)
    {
        printf("fatal error.");
        exit(0);
    }
    p->next = NULL;
    p->data = num;
    return p;
}
STACK *pushStack(int num)
{
    if (nodeNum == 0)
    {
        head = createNode(num);
        pr = head;
        nodeNum++;
    }
    else
    {
        pr->next = createNode(num);
        pr = pr->next;
        nodeNum++;
    }
    return pr;
}
int popStack(void)
{
    STACK *p = head;
    int result;
    while (1)
    {
        if (p->next == NULL)
        {
            break;
        }
        else
        {
            pr = p;
            p = p->next;
            nodeNum--;
        }
    }
    pr->next = NULL;
    result = p->data;
    free(p);
    return result;
}