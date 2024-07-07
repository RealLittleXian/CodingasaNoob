#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, k;
    cin >> n;
    n = n / 52 / 7; // n=(7*x+21*k)/7
    for (k = 1;; k++)
    {
        for (x = 100; x >= 1; x--)
        {
            if (n == x + 3 * k)
            {
                cout << x << endl
                     << k;
                return 0;
            }
        }
    }

    return 0;
}