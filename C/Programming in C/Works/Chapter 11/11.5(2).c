#include <stdio.h>
#define N 10
#define M 10

void Transpose(int (*a)[N], int (*at)[M], int m, int n);
void Input(int (*a)[N], int m, int n);
void Print(int (*at)[M], int m, int n);

int main()
{
    int m, n, matrix[M][N], matrixt[N][M];
    printf("input m,n:");
    scanf("%d,%d", &m, &n);

    Input(matrix, m, n);
    Transpose(matrix, matrixt, m, n);

    printf("transposed matrix as following.\n");
    Print(matrixt, n, m);
    return 0;
}

void Transpose(int (*a)[N], int (*at)[M], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(*(at + j) + i) = *(*(a + i) + j);
        }
    }
}

void Input(int a[][N], int m, int n)
{
    int i, j;
    printf("input %d*%d matrix:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", *(a + i) + j);
        }
    }
}

void Print(int at[][M], int m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", *(*(at + j) + i));
        }
        printf("\n");
    }
}