#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "Today, I ate ";
    if (n == 1)
        cout << "1 apple.";
    if (n == 0)
        cout << "0 apple.";
    if (n > 1)
        cout << n << " apples.";
    return 0;
}
