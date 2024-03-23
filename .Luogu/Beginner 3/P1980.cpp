#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, sum = 0;
    char x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        std::string str_i = to_string(i);
        for (char ch : str_i)
        {
            if (ch == x)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}