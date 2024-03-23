#include <iostream>
using namespace std;
int main()
{
    int a, n = 0;
    cin >> a;

    while (a != 1)
    {
        a = a / 2;
        n++;
    }
    cout << n + 1;
    return 0;
}