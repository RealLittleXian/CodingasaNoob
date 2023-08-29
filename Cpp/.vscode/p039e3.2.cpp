#include <stdio.h>
int main03(void)
{
    int x,b1,b2,b3,s;
    printf("inputx:");
    scanf_s("%d",&x);
    b1 =x/100;
    b2 = (x-b1*100)/10;
    b3 = x%10;;
    s=b1+b2*10+b3*100;
    printf("sum=%d",s);
    return 0;
}
