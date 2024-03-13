#include <stdio.h>
#include <math.h>
int main()
{
    int h,r,n;
    const float Pi=314;
    scanf("%d %d",&h,&r);
    int v=Pi*r*r*h;
    n=2000000/v;
    n+=(2000000%v==0)?0:1;
        printf("%d",n);
    return 0;
}