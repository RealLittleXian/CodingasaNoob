#include <stdio.h>  //p044
int main(void)
{
    char ch;
    printf("there is A to a. enter a capital letter:");
    ch=getchar();
    ch = ch + 32;
    putchar(ch);
    printf("\n%c\n",ch);
    printf("the ascii code of %c is %d\n",ch,ch);
    return 0;
}