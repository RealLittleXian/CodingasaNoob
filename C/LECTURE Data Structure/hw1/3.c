#include <stdio.h>

// O(n)
void Insert(int nums[], int *size, int val)
{
    int i;
    for (i = *size; (i > 0 && nums[i - 1] > val); i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[i] = val;
    (*size)++;  // n++
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int val;
    scanf("%d", &val);

    Insert(nums, &n, val);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}