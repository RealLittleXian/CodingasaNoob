#include <stdio.h>

// 计算矩阵两条对角线上各元素之和
int diagonalSum(int n,int mat[][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i]; // 主对角线上的元素
        sum += mat[i][n - 1 - i]; // 副对角线上的元素
    }
    return sum;
}

int main() {
    int n;
    printf("enter n:");
    scanf("%d", &n);

    int mat[n][n];

    printf("enter the elements of the %d*%d matrix. \n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int sum = diagonalSum(n,mat);
    printf("sum = %d\n", sum);

    return 0;
}
