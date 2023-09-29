#include <stdio.h>

int main() {
    char num;
    printf("enter a number:");
    scanf("%c\n",&num); //scanf()的参数不用&取地址，就会提示Segmentation fault

    switch(num) {
        case '1':
            printf("Number is 1.\n");
            break;
        case '2':
            printf("Number is 2.\n");
            break;
        default:
            printf("Number is not 1 or 2.\n");
    }

    return 0;
}