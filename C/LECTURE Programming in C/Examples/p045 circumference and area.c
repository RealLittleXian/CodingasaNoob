#include <stdio.h>
#define pi 3.14159  //p031宏常量
int main(void)
{
    double r;

    printf("Input r:");
    scanf("%lf",&r);        //p046 scanf()用法
    double c=2*pi*r,s=pi*r*r;
    printf("the circumference is %f\n",c);
    printf("the area is %f\n",s);


    /*  p014,p043
    %d
    %f
    %c
    */
   
    printf("\n\nprintf 域宽，精度\n");
    printf("the circumference is %7.2f, the area is %7.2f\n",c,s);

    //p045
    return 0;
}
