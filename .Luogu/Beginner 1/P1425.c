#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d,p;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    p=(c-a)*60+(d-b);
    printf("%d %d",p/60,p%60);
    return 0;
}