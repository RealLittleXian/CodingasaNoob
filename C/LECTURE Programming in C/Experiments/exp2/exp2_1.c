/*
2001 大象喝水
实验内容
一只大象口渴了，要喝20L水才能解渴，但现在只有一个深hcm、底面半径rcm的小圆桶（h和r都是整数）。
请问大象至少要喝多少桶水才会解渴。
【输入】
一行，包含两个整数，以空格分开，分别表示小圆桶的深h和底面半径r，单位都是cm
【输出】
一行，包含一个整数，表示大象至少要喝水的桶数。
【输入示例】
23 11
【输出示例】
3
*/
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