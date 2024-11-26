/*
4003 Pell数列

Pell数列a1, a2, a3 ...的定义：a1 = 1, a2 = 2, …, an = 2 *an − 1 + an - 2 (n > 2) 
求Pell数列的第k项模32767的值（1≤k≤30）。
【输入】
第一行是测试数据的组数，后面n行是测试数据，每组测试数据占一行。
【输出】
n行，每行对应一个测试数据，非负整数。
【示例】
输入：
2
1
8
输出：
1
408
提示：
1.使用递归。
2.可以不考虑时间复杂度。
*/
#include<stdio.h>

long long Pell(int n){
    if (n==1){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else {
        return 2*Pell(n-1)+Pell(n-2);
    }
    return 0;
}

int main(){
    int textNum,n;
    scanf("%d",&textNum);
    for (int i = 0; i < textNum; i++)
    {
        int j;
        scanf("%d",&j);
        int result = Pell(j);
        printf("%d\n", result);
        fflush(stdin);
    }
    
}