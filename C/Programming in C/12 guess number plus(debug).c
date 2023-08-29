//p176
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int maxinum=100;
const int mininum=1;
int mkn_number;

int makenum(void);
int guessnumber(int mkn_number);


int main(void)
{
char re[4];

Y:

    srand(time(0));

int c=guessnumber(mkn_number);
    printf("\ncongratulations! u've tried %d times.",c);
    printf("\ntry again? enter 'y' to replay. ");
    scanf("%s",&re);
    printf("\n");
    if (re[0]=='y')
    goto Y;

    return 0;
}

int makenum(void){
    mkn_number=(rand()%(maxinum-mininum+1)+mininum);
    printf("random num = %d\n",mkn_number);
    return mkn_number;
}

int guessnumber(int mkn_number){
    int guess;
int count=0;
int num=makenum();

printf("guess the number here(%d < the num < %d): ",mininum,maxinum);
scanf("%d",&guess);
getchar();
do{

    if (guess<num){
        count++;
        printf("\ntoo small. try again. ");
scanf("%d",&guess);
getchar();
    }
    else if (guess>num){
        count++;
        printf("\ntoo big. try again. ");
scanf("%d",&guess);
getchar();
    }
    else {
        count++;
    break;
    }

}
while (guess!=num);

return count;
}