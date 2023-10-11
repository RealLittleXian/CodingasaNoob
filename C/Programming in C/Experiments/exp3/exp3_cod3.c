#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//find out if a number is prime or not
bool isPrime(int num) {
    if (num<2) {
        return false;
    }
    for (int i=2;i*i<=num;i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M;
    scanf("%d",&M);
    int results[M];     //set an array to save sums in order to output at once
    for (int k=0;k<M;k++) {
        int N;
        scanf("%d",&N);

        //cauculate
        int sum=0;
        for (int i=0; i<N;i++) {
            int num;
            scanf("%d",&num);

            if (isPrime(num)) {
                sum+=num;
            }
        }
        results[k] = sum;   // save sums
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", results[i]); //output
    }

    return 0;
}