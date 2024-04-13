#include <iostream>
using namespace std;

int main()
{
    int l, m, a, b, count = 0;
    cin >> l >> m;
    int arr[l+1] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            arr[j] = 1;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (!arr[i])
            count++;
    }
    cout << count;
    return 0;
}