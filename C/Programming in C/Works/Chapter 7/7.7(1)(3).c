#include <stdio.h>

int findGCDwithEM(int num1,int num2) {
    int min=(num1<num2) ? num1:num2;
    int gcd = 1;

    for (int i = 1; i <= min; i++) {
        if (num1%i==0 && num2%i==0) {
            gcd = i;
        }
    }

    return gcd;
}

int findGCDwithRM(int num1,int num2) {
    if(num1<num2){
        int min=num1;
        num1=num2;
        num2=min;
    }
    if (num2 == 0) {
        return num1;
    } else {
        return findGCDwithRM(num2, num1-num2);
    }}

int main() {
    int num1, num2;

    printf("Enter two numbers as \"num1,num2\": ");
    scanf("%d,%d",&num1,&num2);

    int gcdEM = findGCDwithEM(num1,num2);
    printf("The GCD of %d and %d is %d, calculated with exhaustion method.\n", num1, num2, gcdEM);

    int gcdRM = findGCDwithRM(num1,num2);
    printf("The GCD of %d and %d is %d, calculated with recurrence method.\n", num1, num2, gcdRM);

    return 0;
}