#include <stdio.h>
#define COUNT 40

#define MAX_DIGITS 1000 //结果的最大位数

//将 result 数组与一个乘数相乘。接收三个参数：result数组，size数组的大小（结果的位数），乘数multiplier
void multiply(int result[], int *size, int multiplier) {
    int carry = 0;  //乘后进位值
    for (int i = 0; i < *size; i++) {
        int product = result[i] * multiplier + carry;
        result[i] = product % 10;   //乘积的个位数存储到 result 数组中
        carry = product / 10;   //进位值更新为乘积的十位数
    }
    while (carry != 0) {
        result[*size] = carry % 10;
        carry /= 10;
        (*size)++;  //进位
    }
}

void factorial(int n) {
    int result[MAX_DIGITS] = {1};   //存储阶乘的结果的各位数字
    int size = 1;
    for (int i = 2; i <= n; i++) {
        multiply(result, &size, i);
    }
    printf("%d! = ", n);
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);    //逆序遍历 result 数组，输出
    }
}

int main() {
    for ( int i = 1; i <= COUNT; i++)
    {
        factorial(i);
        printf("\n");
    }
    return 0;
}

/*
这个程序使用数组来存储各位数字，计算40的阶乘。

首先，在程序中定义了一个宏 MAX_DIGITS ，用于指定结果的最大位数。
我们将使用一个整型数组 result 来存储阶乘的结果的各位数字。
result 数组的初始值为1，表示1的阶乘。

然后，定义了一个辅助函数 multiply ，用于将 result 数组与一个乘数相乘。
该函数接收三个参数：result 数组、size 数组的大小（即结果的位数），以及一个乘数 multiplier 。
在函数中，我们遍历 result 数组的每个元素，将其与 multiplier 相乘，并加上上一次的进位值 carry 。
然后，将乘积的个位数存储到 result 数组中，并将进位值更新为乘积的十位数。如果乘积的十位数不为0，
则继续将其存储到 result 数组中，并将 size 增加1，以便记录结果的位数。

接下来，定义了主函数 factorial ，用于计算阶乘并输出结果。
函数接收一个整数 n ，表示要计算的阶乘。在函数中，我们首先将 result 数组初始化为1，
并将 size 设置为1，表示阶乘的初始值为1。然后，使用一个循环从2开始，依次将阶乘的每个数字与 result 数组相乘，
最终得到阶乘的结果。最后，我们按逆序遍历 result 数组，将每个数字输出，即得到最终的阶乘结果。

在 main 函数中，我们调用 factorial 函数，并传入40作为参数。
然后，程序会计算40的阶乘，并输出结果。

需要注意的是，由于40的阶乘结果非常大，所以我们预先定义了一个足够大的数组 result 来存储结果。
如果需要计算更大的阶乘，可能需要增加数组的大小以适应结果的位数。

*该程序使用AI释义以辅助理解

*/