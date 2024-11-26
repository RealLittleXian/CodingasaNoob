#include <stdio.h>
#define NUM 10

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectFunction(int a[], int n, int (*Compare)(int a, int b))
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*Compare)(a[k], a[j]))
                k = j;
        }
        if (k != i)
            Swap(&a[k], &a[i]);
    }
}

void AscendingSort(int k, int j)
{
    return k > j;
}

void DesendingSort(int k, int j)
{
    return k < j;
}

int Read(int score[])
{
    int i = -1;
    do
    {
        i++;
        printf("enter score:");
        scanf("%d", &score[i]);
    } while (score[i] >= 0);
    return i;
}
void Print(int score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%4d", score[i]);
    }
    printf("\n");
}

int check(void)
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1) /*未能成功读入*/
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch); // 清除缓存区的字符
        }
        printf(" is invaluable. retry.");
    }
    return input;
}

int main()
{
    printf("enter 1 for ascending sort or 2 fordesending sort:");
    int input;
    int score[NUM];
    int n = Read(score);
    do
    {
        input = check();
    } while (input != 1 && input != 2);
    if (input == 1)
    {
        SelectFunction(score, NUM, AscendingSort);
    }
    else if (input = 2)
    {
        SelectFunction(score, NUM, DesendingSort);
    }
    else
    {
        printf("unknown error.");
    }

    Print(score, n);
}