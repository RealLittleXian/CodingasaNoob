#include <stdio.h>
#include <stdlib.h> //p156

unsigned long fac(unsigned int n);  //fac = factorial, 阶乘
int main(void)
{
    int m,k;unsigned long c;
    do{
        printf("\ninput m,k for Combinatorial number(m,k) (m >= k > 0):");
        scanf("(%d,%d)",&m,&k);
        getchar();
        if (m<k||m<=0||k<=0)
        {
        printf("\nwrong input. retry.\n");
        }
        }
        while(m<k||m<=0||k<=0);
    c= fac(m)/(fac(k)*fac(m-k));
    printf("\nC(%d,%d) = %lu\n",m,k,c);
    return 0;
}

unsigned long fac(unsigned int n)
{
    unsigned int i,re=1;
    for(i=1;i<=n;i++)
    re*=i;
    return re;
}