#include <stdio.h>
#define N 10
#define M 10

void Transpose(int *a, int *at, int m, int n);
void Input(int *a, int m, int n);
void Print(int *at, int m, int n);

int main()
{
    int m, n, matrix[M][N], matrixt[N][M];
    printf("input m,n:");
    scanf("%d,%d", &m, &n);

    Input(*matrix, m, n);
    Transpose(*matrix, *matrixt, m, n);

    printf("transposed matrix as following.\n");
    Print(*matrixt, m, n);
    return 0;
}

void Transpose(int *a, int *at, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            at[m*j+i] = a[n*i+j];
        }
    }
}

void Input(int *a, int m, int n)
{
    int i, j;
    printf("input %d*%d matrix:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[m*i+j]);
        }
    }
}

void Print(int *at, int m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", at[m*i+j]);
        }
        printf("\n");
    }
}