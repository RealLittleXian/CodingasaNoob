#include <iostream>
using namespace std;
int main()
{
    int sign = 0, n, max = 0, p1, p2;
    for (int i = 0; i < 7; i++)
    {
        cin >> p1 >> p2;
        n = p1 + p2;
        if ((n > max) && (n > 8))
            max = n, sign = i+1;
    }
    cout << sign;
    return 0;
}