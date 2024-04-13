// to be continued

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, sum = 0, day = 0;
    cin >> k;
    for (int i = 1; day < k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum += i;
            day++;
            if (day == k)
            {
                cout << sum << endl;
                return 0;
            }
        }
    }
    return 0;
}