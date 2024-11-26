/*
2002 判断能否被3/5/7整除
实验内容 给定一个整数，判断它能否被3,5,7整除，并输出以下信息：
能同时被3,5,7整除，输出3 5 7，每个数中间一个空格；
只能被其中两个数整除，输出两个数，小数在前，大数在后，中间用空格分隔；
只能被其中一个数整除，输出这个数；
不能被任何数整除，输出小写字符n
【输入】 一行，包含一个整数
【输出】 一行，按照描述要求给出整数被3,5,7整除的情况
【输入示例】
105
【输出示例】
3 5 7
*/

#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int div3 = (num % 3 == 0);
    int div5 = (num % 5 == 0);
    int div7 = (num % 7 == 0);

    if (div3 && div5 && div7) {
        printf("3 5 7\n");
    } else if (div3 && div5) {
        printf("3 5\n");
    } else if (div3 && div7) {
        printf("3 7\n");
    } else if (div5 && div7) {
        printf("5 7\n");
    } else if (div3) {
        printf("3\n");
    } else if (div5) {
        printf("5\n");
    } else if (div7) {
        printf("7\n");
    } else {
        printf("n\n");
    }

    return 0;
}