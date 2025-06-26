/*
note
C++使用变长数组：可以用vector<>, map<>
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, i, j, k, operation;
    cin >> n >> q;
    map<int, map<int, int>> array;
    for (int x = 0; x < q; x++)
    {
        cin >> operation >> i >> j;
        if (operation == 1)
        {
            cin >> k;
            array[i][j] = k;
        }
        if (operation == 2)
        {
            cout << array[i][j] << endl;
        }
    }
    return 0;
}