#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n,int d){
    if (n>d)
    {
        return false;
    }
    
    if (n<=1)
    {
        return false;
    }
    for (int i = 2; i*i <= n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void findTwinPrimes(int c, int d) {
    int twinCount = 0;

    for (int i = c; i < d; i++) {
        if (isPrime(i,d) && isPrime(i + 2,d)) {
            printf("(%d,%d)", i, i + 2);
            twinCount++;
        }
    }

    printf("\n%d\n", twinCount);
}

int main(){
    int c,d;
    scanf("%d,%d",&c,&d);
    findTwinPrimes(c,d);
    return 0;
}