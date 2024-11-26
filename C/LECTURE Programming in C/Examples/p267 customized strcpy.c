#include <stdio.h>
#define N 100

void StrcpywithArray(char dstStr[], char srcStr[])
{
    // SRC表示的是源(source)地址, DST代表目的(destination)地址
    int i = 0;
    while (srcStr[i] != '\0')
    {
        dstStr[i] = srcStr[i];
        i++;
    }
    dstStr[i] = '\0';
}
void StrcpywithPointer(char *dstStr, char *srcStr)
{
    while (*srcStr != '\0')
    {
        *dstStr = *srcStr;
        dstStr++;
        srcStr++;
    }
    *dstStr = '\0';
}

int main()
{
    char a[N], b[N];
    printf("input array[] u want to copy:");
    gets(a);

    StrcpywithArray(b, a);
    printf("the copy with array:");
    puts(b);

    StrcpywithArray(b, a);
    printf("the copy with pointer:");
    puts(b);
}