#include<stdio.h>

void to_binary(unsigned long n);

int main(void){
    unsigned long num;
    printf("enter an integer, or 'q' to quit:");

    while ( (scanf("%ul",&num)) == 1)
    {        printf("binary equivalent:");
        to_binary(num);
        putchar('\n');
        printf("enter another integer, or 'q' to quit:");
    }
    printf("done.");

    return 0;
}

void to_binary(unsigned long n){
    int b;
    b=n%2;
    if(n>=2){
        to_binary(n/2);
    }
    putchar('0'+b);
    return;
}