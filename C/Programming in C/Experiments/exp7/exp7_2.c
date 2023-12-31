#include <stdio.h>

// 构建降序数
int get_max(int num)
{
    int digits[4];
    digits[0] = num % 10;
    digits[1] = (num / 10) % 10;
    digits[2] = (num / 100) % 10;
    digits[3] = (num / 1000) % 10;

    int Max = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (digits[j] == i)
            {
                Max = Max * 10 + i;
            }
        }
    }

    return Max;
}
// 构建升序数
int get_min(int num)
{
    int digits[4];
    digits[0] = num % 10;
    digits[1] = (num / 10) % 10;
    digits[2] = (num / 100) % 10;
    digits[3] = (num / 1000) % 10;

    int Max = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (digits[j] == i)
            {
                Max = Max * 10 + i;
            }
        }
    }

    return Max;
}
// 主算法
int kaprekar_operation(int num)
{
    int count = 1;
    while (1)
    {
        int Max = get_max(num);
        int Min = get_min(num);
        num = Max - Min; // 减法结果，也是下一步的初数

        printf("[%d]:%d-%d=%d\n", count, Max, Min, num);
        count++;
        if (num == 6174)
        {
            break;
        }
    }

    return num;
}

int main()
{
    int num;
    scanf("%d", &num);
    kaprekar_operation(num);

    return 0;
}