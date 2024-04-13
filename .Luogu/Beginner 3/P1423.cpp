#include <bits/stdc++.h>
using namespace std;

int main()
{
    float s, l = 2.0, sum = 0;
    int i = 0;
    cin >> s;
    while (s > sum)
    {
        sum += l;
        l = l * 0.98;
        i++;
    }
    cout << i;
    return 0;
}