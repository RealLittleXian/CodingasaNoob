/*
n(n<=100)只小鱼最近参加了一个“比可爱”比赛，比的是每条鱼的可爱程度。
参赛的鱼被从左到右排成一排，头都朝向左边。每条鱼会有一个整数数值，表示这条鱼的可爱程度，
而且可能存在可爱程度相同的鱼。所有鱼头都朝向左边，它们心里在计算，在自己眼力范围内，有多少条鱼不如自己可爱呢？
输入：
两行，第一行输入一个正整数n，表示小鱼的数目；第二行输入 n 个正整数，用空格间隔，
依次表示从左到右每只小鱼的可爱程度ai。
输出：
一行，输出 n 个整数，用空格间隔，依次表示每只小鱼眼中有多少只鱼不如自己可爱。
输入样例：
6
4 3 0 5 1 2
输出样例：
0 0 0 3 1 2
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count;
    scanf("%d", &n);
    int cute[n + 1], fishes[n + 1];
    cute[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fishes[i]);
        count = 0;
        for (int j = 0; j < i; j++)
        {

            if (fishes[i] > fishes[j])
            {
                count++;
            }
            cute[i] = count;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", cute[i]);
    }
    printf("%d", cute[n - 1]);
    return 0;
}