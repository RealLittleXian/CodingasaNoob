#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a = 3.14, b = 1e+10;
    cout << (a + b) - b << endl;
    cout << a + (b - b) << endl;
    cout << (3.14 + 1e10) - 1e10 << endl;
    cout << 3.14 + (1e10 - 1e10) << endl;
    cout << (1e20 * 1e20) << endl;
    return 0;
}