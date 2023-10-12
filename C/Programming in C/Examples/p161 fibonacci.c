#include <stdio.h>
#include <stdlib.h> //p161
long count;
long fib(int n);
int main()
{
    int i,n,x;
    printf("input n:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
    count=0;
    x=fib(i);
    printf("fib(%d) = %d, count = %d\n",i,x,count);
}
    return 0;
}

long fib(int n)
{
    count++;
    if (n==1)return 1;
    if (n==2)return 1;
    else return (fib(n-1)+fib(n-2));
}

//经测试，至多输入fib(46)