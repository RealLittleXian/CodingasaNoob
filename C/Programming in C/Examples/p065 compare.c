#include <stdio.h>//p064
#include <stdlib.h>
int main(void)
{
    int a,b,max;
    printf("enter 2 numbers (divided by space):");
    scanf("%d%*c%d",&a,&b);
    if (a>b)
    {
        printf("%d > %d",a,b);
    }
    else
    {
        printf("%d < %d\n\n",a,b);
    }

    system("pause");

    max = a>b?a:b;      //p065条件控制
    printf("\nmax = %d\n",max);         /*利用条件运算符，更简易的写法是：
    
                                        max = (a > b) ? a ; b ;
                                        
                                        */
    
    return 0;
}