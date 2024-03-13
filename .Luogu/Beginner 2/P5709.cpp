#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, t, s, ans;
    cin >> m >> t >> s;
    if (t == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    ans = m - s / t;
    if (s % t == 0)
    {
        cout << max(0, m - s / t);
    }
    else
    {
        cout << max(0, m - s / t - 1);
    }
}