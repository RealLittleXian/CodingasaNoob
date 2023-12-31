/*将1到9这九个数字分成三个3位数，要求第一个3位数，正好是第二个3位数的1/2，是第三个3位数的1/3。
请输出所有符合条件的3位数 (每一行数据需要按照从小到大排列且第一列数据也需要满足递增)。
【输入】
无输入
【输出】
"%d,%d,%d\n"
【示例1】
192,384,576
···(还有多组未给出数据)
注：示例仅为满足要求的数据中的一组。*/
#include <stdio.h>

int array[9];
int Calcu(int num, int *p)
{
    int *i, *j;
    for (i = p; i < p + 3; i++)
    {
        *i = num % 10;
        num /= 10;
        if ((*i) == 0)
            return 0;
        for (j = array; j < i; j++)
        {
            if ((*i) == (*j))
                return 0;
        }
    }
    return 1;
}
int main()
{
    int i;
    int count = 1;
    for (i = 123; i < 333; i++)
    {
        if (Calcu(i, array) && Calcu(2 * i, array + 3) && Calcu(3 * i, array + 6)) // 第二个数从array[3]开始存，第三个数从array[6]开始存。
        {
            printf("%d %d %d\n", i, 2 * i, 3 * i);
            count++;
        }
    }
    return 0;
}
