#include<stdio.h>
int main(){
    int j,k;
    for ( j = 1; j <= 9; j++){
        for ( k = 1; k <= j; k++){
            printf("%3d",k*j);
        }
        printf("\n");
    }
    return 0;
}
