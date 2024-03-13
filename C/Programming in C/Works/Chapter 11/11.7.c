#include <stdio.h>
#include <stdlib.h>
void Input(int *p, int m, int n);
int Max(int *p, int m, int n, int *pRow, int *pCol);

int main()
{
    int *pScore, m, n, max, row, col;
    printf("input m,n:");
    scanf("%d,%d", &m, &n);
    pScore = (int *)calloc(m * n, sizeof(int));
    if (pScore == NULL)
    {
        printf("fatel error.");
        exit(0);
    }
    Input(pScore, m, n);
    max = Max(pScore, m, n, &row, &col);
    printf("max=%d\tclass=%d\tnumber=%d\n", max, row + 1, col + 1);
    free(pScore);
    return 0;
}
void Input(int *p, int m, int n)
{
    int i, j;
    printf("input scores:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; i < n; i++)
        {
            scanf("%d", &p[i * n + j]);
        }
    }
}
int Max(int *p, int m, int n, int *pRow, int *pCol)
{
    int i, j, max = p[0];
    *pRow = 0;
    *pCol = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i * n + j] > max)
            {
                max = p[i * n + j];
                *pRow = i;
                *pCol = j;
            }
        }
    }
    return max;
}