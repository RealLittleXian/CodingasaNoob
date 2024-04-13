#include <iostream>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    int arr[n+1], judge[n+1] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j && arr[i] + arr[j] == arr[k] && judge[k] ==0)
                {
                    count++;
                    judge[k] = -1;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}