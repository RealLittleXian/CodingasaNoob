//p163 使用嵌套if检测一个数的约数

#include<stdio.h>
#include<stdbool.h>

bool isPrime;
unsigned long num,div;

int main(){
    printf("please enter an integer for analysis:");
    printf("(enter 'q' to quit.)");

    /*输入循环的模型：
    
    while(ch = getchar()!=STOP){
        *code
    }
    
    */
    while(scanf("%lu",&num)==1){

    for(div=2,isPrime=true;(div*div)<=num;div++){
        if(num%div==0){
            if((div*div)!=num){
            printf("%lu is divisible by %lu and %lu.\n",num,div,num/div);
            }
            else {
            printf("%lu is divisible by %lu.\n",num,div);
            }
            isPrime=false;
        }
    }
    
    if (isPrime){       //即if(isPrime = true)
        printf("%lu is a prime.\n",num);
    }
    printf("enter another integer for analysis:");
    printf("(enter 'q' to quit.)");
}
printf("end.");
}