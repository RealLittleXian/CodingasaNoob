#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n], result[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        for (int j = 0; j<i; j++)
        {
            if (array[i] > array[j])
            {
                result[i]++;
            }
        }
        cout << result[i] << " ";
    }
    return 0;
}