#include<stdio.h>
#include<stdbool.h>

int CalcuLCM() {
    int n1,n2,LCM;
    bool sign=0;
    printf("enter two numbers as \"num1,num2\":");
    scanf("%d,%d",&n1,&n2);

    for ( LCM = 1; !sign; LCM++)
    {
        if (LCM%n1==0 && LCM%n2==0)
        {
            sign=true;
        }
    }
    return LCM-1;
}

void main(){
    printf("the LCM is %d.",CalcuLCM());
}