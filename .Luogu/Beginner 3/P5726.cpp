#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, max, min, i1;
    float sum;
    cin >> n >> i1;
    max = min = sum = i1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d;
        sum += d;
        if (d > max)
            max = d;
        if (d < min)
            min = d;
    }
    printf("%.2f", (sum - max - min) / (n - 2));
    return 0;
}