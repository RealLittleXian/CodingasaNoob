#include <stdio.h>
#define N 10

void Transpose1(int a1[][N], int n);
void Transpose2(int (*a2)[N], int n);
void Transpose3(int *a3, int n) 

void main() {
    int n, matrix[N][N];
    printf("input n:");
    do
    {
        scanf("%d", n);
    } while (n <= N);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            scanf("%d", matrix[i][j]);
            getchar();
        }
    }
    Transpose1(matrix, n);
    Transpose2(matrix, n);
    Transpose3(matrix, n);
}