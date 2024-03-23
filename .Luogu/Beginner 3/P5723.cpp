#include <iostream>
#include <cmath>
using namespace std;
int Prime(long n);
int main()
{
    long n;
    int sum = 0, count = 0;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (Prime(i))
        {
            sum += i;
            if (sum > n)
                break;

            cout << i << endl;
            count++;
        }
    }
    cout << count;
    return 0;
}

int Prime(long n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}