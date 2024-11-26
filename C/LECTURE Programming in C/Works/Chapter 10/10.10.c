#include <stdio.h>
#include <string.h>
#define DAY 7
#define LEN 10
int main()
{
    int i, pos, sign = 0;
    char str[LEN];
    char weekday[][LEN] = {"Sunday",
                              "Monday",
                              "Tuesday",
                              "Wednesday",
                              "Thursday",
                              "Friday",
                              "Saturday"};
    printf("input string:");
    gets(str);
    for (i = 0; i < DAY && !sign; i++)
    {
        if (strcmp(str, weekday[i]) == 0)
        {
            pos = i;
            sign = 1;
        }
    }
    if (sign)
    {
        printf("%s --- %d\n", str, pos);
    }
    else
    {
        printf("not found.");
    }
}