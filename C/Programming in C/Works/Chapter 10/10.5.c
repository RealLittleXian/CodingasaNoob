#include <stdio.h>
#include <string.h>
#define N 100
void InversewithArray(char s[], char c);
void InversewithPointer(char *s, char c);
int main()
{
    char str[N], copy[N], ch;

    printf("input string:");
    gets(str);
    strcpy(copy, str);
    printf("input character:");
    ch = getchar();

    InversewithArray(str, ch);
    printf("%s\n", str);
    strcpy(str, copy);
    InversewithPointer(str, ch);
    printf("%s\n", str);
    return 0;
}
void InversewithArray(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}
void InversewithPointer(char *s, char c)
{
    char str[N];
    char *p = str;
    strcpy(p, s);
    for (; *p != '\0'; p++)
    {
        if (*p != c)
        {
            *s = *p;
            s++;
        }
    }
    *s = '\0';
}