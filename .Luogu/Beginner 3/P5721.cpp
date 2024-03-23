#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, end, k = 1;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        end += i;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++, k++)
            printf("%02d", k);
        printf("\n");
    }
    return 0;
}