#include<stdio.h>

int h,m,s;
void Update(void) {
    s++;
    if (s==60)
    {
        s=0;
        m++;
    }
    if(m==60) {
        m=0;
        h++;
    }
    if (h==24)
    {
        h=0;
    }
}

void Display(void) {
    printf("%d : %d : %d\n",h,m,s);
}

void Delay(void) {
    for ( int t = 0; t < 2147483647; t++)    {
        ;
    }
}

int main() {
    int i;
    for ( i = 0; i < 2147483647; i++)
    {
        Update();
        Display();
        Delay();
    }
    return 0;
}