#include<stdio.h>

long long Pell(int n){
    if (n==1){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else {
        return 2*Pell(n-1)+Pell(n-2);
    }
    return 0;
}

int main(){
    int textNum,n;
    scanf("%d",&textNum);
    for (int i = 0; i < textNum; i++)
    {
        int j;
        scanf("%d",&j);
        int result = Pell(j);
        printf("%d\n", result);
        fflush(stdin);
    }
    
}