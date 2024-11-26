#include<stdio.h>
#include<math.h>
int main(void)
{
    int initial,coconuts,times;
    int sign=0;
    for (initial=1; sign!=1; initial++)
    {
        coconuts=initial;
        coconuts=5*coconuts+1;

        for(times=1; times<5; times++)
        {
            if (coconuts/4.0!=floor(coconuts/4.0)){
                break;
            }
            else{
                coconuts=coconuts/4*5+1;     //之前的水手看到的椰子数
            }
 
        }
        if (times==5)
        {
            sign=1;
        }
    }
    printf("%d coconuts.\n", coconuts);
    return 0;
}