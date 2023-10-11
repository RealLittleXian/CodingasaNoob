#include<stdio.h>
#define PI 3.14159
#define SIZE 20000

main(){
    int h,r,barrel;
    double v;
    scanf("%d %d",&h,&r);
    v=PI*r*r*h;

    barrel=SIZE/v+1;
    printf("%d",barrel);
}