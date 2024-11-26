#include <stdio.h>
#include <string.h>
#define N 100
void InversewithArray(char s[], char ptr[]);
void InversewithPointer(char *p);
int main()
{
    char str1[N], str2[N],copy[N];

    printf("input string:");
    gets(str1);
    strcpy(copy, str1);

    InversewithArray(str1, str2);
    printf("%s\n", str2);
    strcpy(str1, copy);
    InversewithPointer(str1);
    printf("%s\n", str1);
    return 0;
}
void InversewithArray(char s[], char ptr[])
{
    int len,i, j;
    len =strlen(s);
    for (i = 0, j=len-1;s[i]!='\0'; i++,j--)
    {
        ptr[j]=s[i];
    }
    s[j] = '\0';
}
void InversewithPointer(char *p)
{
    int len;
    char temp;
    char *pstart,*pend;
    len=strlen(p);
    for (pstart=p,pend=p+len-1; pstart<pend; pstart++,pend--)
    {
       temp=*pstart;
       *pstart=*pend;
       *pend=temp;
    }
    
}