<<<<<<< HEAD
/*对一个数组内所有元素求和*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int sum_array(int ar[],int n);
int sum_pointer(int *start,int *end);

int main(void){

    /*一个简单的数组输入接口
    
    int input;
    char ch;
    printf("enter one number every time and then 'enter'");
    
    for(int i=0;i<SIZE;i++){

    while (scanf("%d",&input)!=1){
        while ( (ch=getchar()) =='\n'){
            putchar(ch);
        }
        printf(" is not an integer.\n"
        "please enter an integer value.");
    }
    marbles[i]=input;
    } 
    */
   
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};

    unsigned long answer_array = sum_array(marbles,SIZE);

    printf("the size of marbles[%d] is %u.\n",SIZE,sizeof marbles[SIZE]);
    printf("the size of marbles[] is %u.\n",sizeof marbles);
    printf("the total number is %d, calculated by array.\n",answer_array);

    system("pause");

    unsigned long answer_pointer = sum_pointer(marbles,marbles + SIZE);

    printf("the total number is %u, calculated by pointer.\n",sizeof marbles);
}

int sum_array(int ar[],int n){
    int total=0,i;
    for(i=0;i<SIZE;i++){
        total += ar[i];
    }
    printf("the size of ar[] is %u.\n",sizeof total);
    return total;
}

int sum_pointer(int *start,int *end )
    /*这里表明指针和数组的一致性，指针可以指向数组中某个元素，也可以进行大小比较*/
{
    int total=0;
    while(start<end)
    {
        total += *start;
        start++;
    }
    return total;
=======
/*对一个数组内所有元素求和*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int sum_array(int ar[],int n);
int sum_pointer(int *start,int *end);

int main(void){

    /*一个简单的数组输入接口
    
    int input;
    char ch;
    printf("enter one number every time and then 'enter'");
    
    for(int i=0;i<SIZE;i++){

    while (scanf("%d",&input)!=1){
        while ( (ch=getchar()) =='\n'){
            putchar(ch);
        }
        printf(" is not an integer.\n"
        "please enter an integer value.");
    }
    marbles[i]=input;
    } 
    */
   
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};

    unsigned long answer_array = sum_array(marbles,SIZE);

    printf("the size of marbles[%d] is %u.\n",SIZE,sizeof marbles[SIZE]);
    printf("the size of marbles[] is %u.\n",sizeof marbles);
    printf("the total number is %d, calculated by array.\n",answer_array);

    system("pause");

    unsigned long answer_pointer = sum_pointer(marbles,marbles + SIZE);

    printf("the total number is %u, calculated by pointer.\n",sizeof marbles);
}

int sum_array(int ar[],int n){
    int total=0,i;
    for(i=0;i<SIZE;i++){
        total += ar[i];
    }
    printf("the size of ar[] is %u.\n",sizeof total);
    return total;
}

int sum_pointer(int *start,int *end )
    /*这里表明指针和数组的一致性，指针可以指向数组中某个元素，也可以进行大小比较*/
{
    int total=0;
    while(start<end)
    {
        total += *start;
        start++;
    }
    return total;
>>>>>>> 8f99d6b39af58b12a2fe353bc574525d2d1d2e0e
}