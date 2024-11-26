#include <stdio.h>
#define N 10
#define M 10

void Input(int *a, int m, int n);
int Calcu(int *p, int *prow, int *pcol, int m, int n);
int main()
{
    int m, n, matrix[M][N], row, col, max;
    printf("input m,n:");
    scanf("%d,%d", &m, &n);

    Input(*matrix, m, n);
    max = Calcu(*matrix, &row, &col, m, n);
    printf("max=%d\trow=%d\tcol=%d\n", max, row, col);

    return 0;
}

void Input(int *a, int m, int n)
{
    int i, j;
    printf("input %d*%d matrix:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[n * i + j]);
        }
    }
}

int Calcu(int *p, int *prow, int *pcol, int m, int n)
{
    int i, j, max = p[0];
    *prow = 0;
    *pcol = 0;
    for (i = 0; i < n; i++) // 行
    {
        for (j = 0; j < m; j++) // 列
        {
            if (p[i * n + j] > max)
            {
                max = p[i * n + j];
                *prow = i;
                *pcol = j;
            }
        }
    }
    return max;
}