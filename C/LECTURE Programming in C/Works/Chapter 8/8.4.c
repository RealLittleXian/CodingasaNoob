#include <stdio.h>
#define MAXINUM 40

int FailStuNum(int Score[], int stunum) {
    int failednum = 0;
    for ( int i = 0; i < stunum; i++)
    {
        if(Score[i]<60) failednum++;
    }
    return failednum;
}

 int main() {
    int StuNum, i, input, failedNum, Score[MAXINUM];
    char ch;
    printf("enter number of students:");
    scanf("%d",&StuNum);
    printf("enter one score every time:");
    for(int i=0;i<StuNum;i++){
        while (scanf("%d",&input)!=1){
            while ( (ch=getchar()) =='\n'){
                putchar(ch);
            }
        printf(" is not an integer.\n"
        "please enter an integer value.");
        }
        Score[i] == input;
        fflush(stdin);
        if (input<=0)
        {
            break;
        }
    } 

    failedNum = FailStuNum(Score, StuNum);
    printf("%d failed of %d students.",failedNum,StuNum);
}