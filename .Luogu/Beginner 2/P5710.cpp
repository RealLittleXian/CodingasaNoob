#include <iostream>
using namespace std;
int main()
{
    int n;
    bool prop1 = false, prop2 = false;
    cin >> n; // input n
    if (n % 2 == 0)
    {
        prop1 = true;
    }
    if (n > 4 && n <= 12)
    {
        prop2 = true;
    }

    if (prop1 && prop2)
        cout << "1 ";
    else
        cout << "0 ";

    if (prop1 || prop2)
        cout << "1 ";
    else
        cout << "0 ";
    if ((prop1 && !prop2) || (!prop1 && prop2))
        cout << "1 ";
    else
        cout << "0 ";
    if (!prop1 && !prop2)
        cout << "1";
    else
        cout << "0";
    return 0;
}