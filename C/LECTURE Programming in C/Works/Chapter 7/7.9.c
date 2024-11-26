#include<stdio.h>

int cal(int n) {
    int age;
    if (n==1)
    {
        age=10;
    }
    else age=cal(n-1)+2;
    
        return age;
    }

int main() {

    printf("%d\n",cal(5));
    return 0;
}