/*
3002 整数序列元素最大跨度值

实验内容
给定一个长度为n的非负整数序列，计算序列的最大跨度值（最大跨度值=最大值-最小值）
输入：
两行，第一行为序列的个数n（1<=n<=1000），第二行为序列的n个不超过1000的非负整数，
相邻两个整数之间用单个空格隔开
输出：
一行，序列的最大跨度值
输入样例：
6
3 0 8 7 5 9
输出样例：
9
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Dynamically allocate an integer array of size n
    int* sequence = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // initialize
    int min = sequence[0];
    int max = sequence[0];

    // set min and max
    for (int i = 1; i < n; i++) {
        if (sequence[i] < min) {
            min = sequence[i];
        }
        if (sequence[i] > max) {
            max = sequence[i];
        }
    }

    int max_span = max - min;
    printf("%d\n", max_span);   //output

    // free memory of Array sequence
    free(sequence);

    return 0;
}
