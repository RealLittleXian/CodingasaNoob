#include <iostream>
using namespace std;
int main()
{
    int n, m1 = 0, m2 = 0;
    cin >> n;
    m1 = 5 * n;
    m2 = 11 + 3 * n;
    if (m1 < m2)
        cout << "Local";
    else
        cout << "Luogu";
    return 0;
}
