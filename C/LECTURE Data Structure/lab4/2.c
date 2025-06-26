#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize - 1; // 从右上角开始
    
    while (row < matrixRowSize && col >= 0) {
        int current = matrix[row][col];
        if (current == target) {
            return true;
        } else if (current > target) {
            col--; // 当前列不可能存在目标值，左移一列
        } else {
            row++; // 当前行不可能存在目标值，下移一行
        }
    }
    return false;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    // 动态分配二维数组
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int target;
        scanf("%d", &target);
        
        bool found = searchMatrix(matrix, m, n, target);
        printf("%s\n", found ? "true" : "false");
    }
    
    // 释放内存
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}