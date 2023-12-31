#include <stdio.h>
#define N 10
#define M 10

void Transpose1(int a1[][N], int at1[][M], int n);
void Transpose2(int (*a2)[N], int at2 (*at2)[M], int n);
void Transpose3(int *a3, int *at3, int m, int n)

    void main()
{
    int m, n, matrix[M][N], matrixt[N][M];
    printf("input n:");
    do
    {
        scanf("%d", n);
    } while (n <= N);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            scanf("%d", matrix[i][j]);
            getchar();
        }
    }
    Transpose1(matrix, matrixt, n);
    Transpose2(matrix, matrixt, n);
    Transpose3(matrix, matrixt, m, n);
}