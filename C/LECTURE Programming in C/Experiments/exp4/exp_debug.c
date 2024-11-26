#include <stdio.h>
#include <stdlib.h>
double fact(double n);
double multi(double n);
double main()
{
    double i;
    double sum=1,item=1,eps=1e-6;
    for(i=1;item>=eps;i++)
    {
        item=fact(i)/multi(2*i+1);  // will be a minus num
        sum=sum+item;
    }
    printf("PI=%.5f\n",sum*2);
    return 0;
}

double fact(double n)
{
    double i;
    double res=1;  //set res=1
    for(i=1;i<=n;i++)
        res=res*i;
    return (double)res;
}

double multi(double n)
{
    double i;
    double res=1; 
    for(i=3;i<=n;i=i+2)
    {
         res=res*i;
    }
    return (double)res;
}
