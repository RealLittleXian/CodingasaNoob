#include <stdio.h>
#include <math.h>

int main(){
    int R,M,Y;
    /*复合年利率为R（0 ~ 20的整数），
      John现有总值为M的钱（100 ~ 1000000的整数），
      投资Y年（0~400）
      */

    double output;
    scanf("%d %d %d",&R,&M,&Y);
    
    output=M*pow((1+R/100.0),Y);

    printf("%d",(int)output);

    return 0;
}