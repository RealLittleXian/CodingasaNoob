#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = i * n + j + 1;
            if (k < 10)
                cout << "0" << k;
            else
                cout << k;
        }
        cout << endl;
    }
    cout << endl;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (k < 10)
                cout << "0" << k++;
            else
                cout << k++;
        }
        cout << endl;
    }
    return 0;
}