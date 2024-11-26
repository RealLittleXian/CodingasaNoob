#include <stdio.h>
#define N 10

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Transpose(int *a, int n);
void Input(int *a, int n);
void Print(int *a, int n);
int main()
{
    int n, matrix[N][N];
    printf("input n:");
    scanf("%d", &n);

    Input(*matrix, n);
    Transpose(*matrix, n);

    printf("transposed matrix as following.\n");
    Print(*matrix, n);
    return 0;
}

void Transpose(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Swap(&a[n * i + j], &a[n * j + i]);
        }
    }
}

void Input(int *a, int n)
{
    int i, j;
    printf("input %d*%d matrix:\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[n * i + j]);
        }
    }
}

void Print(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[n * j + i]);
        }
        printf("\n");
    }
}