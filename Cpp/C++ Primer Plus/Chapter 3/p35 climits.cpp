#include <iostream>
#include <climits>

int main()
{
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LONG_LONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes.\n";
    cout << "short is " << sizeof(short) << " bytes.\n";
    cout << "long is " << sizeof(long) << " bytes.\n";
    cout << "long long is " << sizeof(long long) << " bytes.\n";
    cout << endl;

    cout << "Maximum values" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl
         << endl;

    cout << "Minimum int value is " << INT_MIN << endl;
    cout << "Bits per byte is " << CHAR_BIT << endl;

    return 0;
}