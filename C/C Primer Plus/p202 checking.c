//计算特定范围内所有整数的平方和

#include<stdio.h>
#include<stdbool.h>

int get_int(void);
bool bad_limits(int a,int b,int low,int high);
double sum_squares(int a,int b);

int main(void){
    const int MIN = -1000;  /*下界限制*/
    const int MAX = 1000;   /*上界限制*/
    int start,stop; /*输入上下界*/
    double answer;

    printf("this program computes the sum of the squares of "
    "integers in a range.\n");
    printf("the lower bound shouldn't be less than %d and the "
    "upper bound shouldn't be more than %d.\n",MIN,MAX);
    printf("enter 0 for both limits to quit.\n");

    printf("lower limit = ");
    start = get_int();
    printf("upper limit = ");
    stop = get_int();
    
    while(start!=0||stop!=0){

        if(bad_limits(start,stop,MIN,MAX)==0    /*==fause*/)
            printf("wrong input. please try again.\n");

        else{
            answer = sum_squares(start,stop);
            printf("the sum of the integers from %d to %d is %g\n", start,stop,answer);
        }
        printf("enter new limits or 0 for both limits to quit.\n");

    printf("lower limit = ");
    start = get_int();
    printf("upper limit = ");
    stop = get_int();
    
    }

printf("done.");

return 0;
}


int get_int(void){
    int input;
    char ch;
    while(scanf("%d",&input)!=1)    /*未能成功读入*/    {
        while (( ch=getchar() ) != '\n')
        {
            putchar(ch);    //清除缓存区的字符
        }
        printf(" is not an integer.\n"
        "please enter an integer value.");  
    }
    return input;
}

bool bad_limits(int a,int b,int low,int high){

bool is_legitimate_input = true;

if (a>b){
    printf("%d is greater than %d\n",a,b);
    is_legitimate_input = false;
}
if (a<low||b<low){
    printf("values must be greater than %d\n",low);
    is_legitimate_input = false;
}
if (a>high||b>high){
    printf("values must be smaller than %d\n",high);
    is_legitimate_input = false;
}
return is_legitimate_input;
}

double sum_squares(int a,int b){
    double total = 0;
    int i;

    for (i=a;i<=b;i++)
    total +=(i*i);
    return total;
}