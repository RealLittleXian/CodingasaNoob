#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 1, countMax = 1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i]+1 == arr[i + 1])
        {
            count++;
        }
        if (countMax < count)
        {
            countMax = count;
        }
        if(arr[i] + 1 != arr[i + 1])
        {
            count = 1;
        }

    }
    cout << countMax << endl;
    return 0;
}