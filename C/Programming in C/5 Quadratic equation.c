#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define epsilon 1e-6
int main(void);
void ifelse();

int main(void)
{
    ifelse();
    system("\npause\n");
    
    return 0;
}

// p069 if & else语句
void ifelse()
{
    float a,b,c,x1,x2,delta;
    printf("enter a, b and c, for ax^2 + bx + c = 0:");
    scanf("%f%*c%f%*c%f",&a,&b,&c);
    if (fabs(a)<=epsilon)       //fabs()输出浮点数的绝对值，abs()输出整数的绝对值。
    {
        printf("it is not a quadrafic equation.\n");

        exit(0);
    }

    //Discriminant简写为disc，意为判别式

    delta =b*b-4*a*c;
    x1=(-b+sqrt(fabs(delta)))/(2*a);
    x2=(-b-sqrt(fabs(delta)))/(2*a);

    float p=-b/(2*a),q=sqrt(fabs(delta))/(2*a);

    if (fabs(delta)<=epsilon)//等价于((delta >= 1e-6)&&(delta <= -1e-6))，p076逻辑运算符
    {
        printf("x1 = x2 = %.2f\n",x1);
    }
    else
    {
        if(delta>epsilon)
        {
            printf("delta =%.2f, x1 = %.2f, x2 = %.2f, ",delta,x1,x2);
        }
        else
        {
            printf("delta =%.2f, x1 = %.2f+%.2fi, x2 = %.2f+%.2fi, ",delta,p,q,p,q);
        }
    }
}