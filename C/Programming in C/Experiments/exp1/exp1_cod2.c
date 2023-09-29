#include<stdio.h>
int main(){
    int i,j,k;
    for ( i = 1; i <= 9; i++){
        printf("%3d",i);
    }
    printf("\n");
    for ( i = 1; i <= 9; i++){
    printf("  -");
    }
    printf("\n");
    for ( j = 1; j <= 9; j++){
        for ( k = 1; k <= j; k++){
            printf("%3d",k*j);
        }
        printf("\n");
    }
    return 0;
}