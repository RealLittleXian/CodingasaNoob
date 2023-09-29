#include <stdio.h>
#include <stdlib.h> //p115

int main();
int random(void);
int srandom(void);

int main(void){
random();
system("pause");
srandom();
return 0;
}
int random(void){
    int max,num,gue,counter=0;
    printf("enter the maxinum:");
    scanf("%d",&max);
    num = rand()%max+1;     //事实上是伪随机，如测试数据：max=10，则num=2；max=100，则num=42
    do{
        printf("guess the number:");
        scanf("%d",&gue);
        counter++;

        if(gue > num)
        printf("too big.\n");

        else if(gue<num)
        printf("too small.\n");

        else
        printf("ur right!");

    }    while(gue!=num);
        printf("\ncounter = %d\n",counter);

    return 0;
}

int srandom(void){
    int seed,max,num,gue,counter=0;
    printf("enter the seed:");
    scanf("%d",&seed);
    printf("enter the maxinum:");
    scanf("%d",&max);

    srand(seed);        /*srand()为rand()设置随机数种子。
                        也可用srand(time(NULL));语句替代，这样就无需输入种子。*/
    num = rand()%max+1;

    do{
        printf("guess the number:");
        scanf("%d",&gue);
        counter++;

        if(gue > num)
        printf("too big.\n");

        else if(gue<num)
        printf("too small.\n");

        else
        printf("ur right!");

    }    while(gue!=num);
        printf("\ncounter = %d\n",counter);

    return 0;
}
