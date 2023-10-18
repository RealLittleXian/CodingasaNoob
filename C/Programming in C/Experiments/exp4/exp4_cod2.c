/*
4002 孪生素数

实验内容
相差2的两个素数称为孪生素数。例如，3与5,41和43都是孪生素数。
请编写程序，计算指定区间[c,d]的所有孪生素数对，并统计这些孪生素数对的数量。
输入：
一行，区间[c,d]的下限值c和上限值d，c>2 ，中间用”,”隔开
输出：
两行，第一行是素数对，第二行是素数对的个数
输入样例：
3,100
输出样例：
(3,5)(5,7)(11,13)(17,19)(29,31)(41,43)(59,61)(71,73)
8
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int d)
{
    if (n > d)
    {
        return false;
    }

    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void findTwinPrimes(int c, int d)
{
    int twinCount = 0;

    for (int i = c; i < d; i++)
    {
        if (isPrime(i, d) && isPrime(i + 2, d))
        {
            printf("(%d,%d)", i, i + 2);
            twinCount++;
        }
    }

    printf("\n%d\n", twinCount);
}

int main()
{
    int c, d;
    scanf("%d,%d", &c, &d);
    findTwinPrimes(c, d);
    return 0;
}