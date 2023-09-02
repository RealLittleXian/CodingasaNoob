#include<stdio.h>
#define COVER 200
int main(){
    int sq;
    int cans;

    printf("square per can is %d\n",COVER);
    printf("enter the number of square to be painted:");

    while(scanf("%d",&sq)==1){
        cans=sq/COVER;
        cans+=(sq%COVER==0)?0:1;
        printf("you need %d %s of paint\n",cans,(cans==1?"can":"cans"));

        printf("enter next value ('q' to quit):");
    }

    /*
    学习：利用

    while(scanf(  ,  ) == x )或while(ch = getchar() != stop ){

        *code*
    
    printf("");
    }
    进行输入检查
    
    */
return 0;
}