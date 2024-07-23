#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, p;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        cout << arr[p - 1] << ' ';
    }

    return 0;
}