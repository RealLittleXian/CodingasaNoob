#include <stdio.h>
#define ROW 7

//返回组合数C(n, k)的值
int combination(int n, int k) {
    if (k == 0 || n == k)   //参数n表示总共有多少个元素，参数k表示要选择多少个元素
        return 1;
    else
        return combination(n-1, k-1) + combination(n-1, k); 
}

int main() {
    int rows = ROW;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            int num = combination(i, j);
            printf("%6d", num);
        }
        printf("\n");
    }

    return 0;
}
