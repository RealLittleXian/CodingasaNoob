/*
明明想请一些同学做调查，为了客观性，先随机生成了 N个1~1000 的随机整数（N<=100），
对于重复的数字，只保留一个，相同的去掉。 不同的数对应不同的学生学号，然后把这些数从小到大排序，
按照排好的顺序去找同学做调查。请协助明明完成“去重”和“排序”工作。
【输入】
两行，第一行一个正整数，表示生成随机数的个数N；第二行有N个用空格隔开的正整数，是随机产生的随机数。
【输出】
两行，第一行一个正整数，表示不相同的随机数的个数；第二行是M个用空格隔开的正整数。
是从小到大排序好的不相同的随机数。
【示例】
输入：
10
20 40 32 67 40 20 89 300 400 15
输出：
8
15 20 32 40 67 89 300 400 
注意：最后一个数字后也有空格，最后一行无换行。
*/
#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于排序
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[n];

    // 读取随机数
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // 去重
    int uniqueNums[n];
    int uniqueCount = 0;
    int m[1001] = {0}; // 记录数字是否已经出现过

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        if (!m[num])
        {
            m[num] = 1;
            uniqueNums[uniqueCount] = num;
            uniqueCount++;
        }
    }

    // 排序
    qsort(uniqueNums, uniqueCount, sizeof(int), cmp);

    // 输出结果
    printf("%d\n", uniqueCount);
    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%d ", uniqueNums[i]);
    }
    return 0;
}
