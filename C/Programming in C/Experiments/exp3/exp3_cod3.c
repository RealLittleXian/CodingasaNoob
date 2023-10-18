/*
3003 素数求和

有N个数（0<N<1000），求N个数中所有素数之和。
输入
第一行给出整数M（0<M<10），代表有多少组测试数据；
每组测试数据第一行为N，表示该组测试数据的数量，接下来的N个数为要测试的数据，每个数都小于1000。
输出
每组测试数据结果占一行，输出测试数据的所有素数和。
【示例】
输入：
3
5
1 2 3 4 5
8
11 12 13 14 15 16 17 18
10
21 22 23 24 25 26 27 28 29 30
输出：
10
41
52
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//find out if a number is prime or not
bool isPrime(int num) {
    if (num<2) {
        return false;
    }
    for (int i=2;i*i<=num;i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M;
    scanf("%d",&M);
    int results[M];     //set an array to save sums in order to output at once
    for (int k=0;k<M;k++) {
        int N;
        scanf("%d",&N);

        //cauculate
        int sum=0;
        for (int i=0; i<N;i++) {
            int num;
            scanf("%d",&num);

            if (isPrime(num)) {
                sum+=num;
            }
        }
        results[k] = sum;   // save sums
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", results[i]); //output
    }

    return 0;
}