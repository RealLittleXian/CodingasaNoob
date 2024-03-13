#include <stdio.h>
#include <math.h>
int main()
{
    int s, v, t, gotime, hh, mm;
    scanf("%d %d", &s, &v);
    if (s % v == 0)
        t = s / v;
    else
        t = s / v + 1;
    gotime = (470 + 2880 - t) % 1440; // +2880,从而让gotime恒大于0
    hh = gotime / 60;
    mm = gotime % 60;
    if (hh < 10 && mm < 10)
        printf("0%d:0%d", hh, mm);
    else if (hh < 10 && mm >= 10)
        printf("0%d:%d", hh, mm);
    else if (hh >= 10 && mm < 10)
        printf("%d:0%d", hh, mm);
    else
        printf("%d:%d", hh, mm);

    return 0;
}