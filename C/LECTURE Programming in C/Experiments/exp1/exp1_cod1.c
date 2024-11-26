#include<stdio.h>

int main(){
    int a;
    short int b;
    char c;
    float d;
    double e;

        printf("input int = ");
        scanf("%d",&a);
        printf("\nint a = %d, size of int a = %ld\n",a,sizeof(a));

        printf("input short int = ");
        scanf("%d",&b);
        printf("\nshort int b = %d, size of short int b = %ld\n",b,sizeof(b));
        getchar();

        printf("input char = ");
        scanf("%c",&c);
        printf("\nchar c = %c, size of char c = %ld\n",c,sizeof(c));

        printf("input float = ");
        scanf("%f",&d);
        printf("\nfloat d = %f, size of float d = %ld\n",d,sizeof(d));

        printf("input double = ");
        scanf("%lf",&e);
        printf("\ndouble e = %lf, size of double e = %ld\n",e,sizeof(e));

        return 0;
}