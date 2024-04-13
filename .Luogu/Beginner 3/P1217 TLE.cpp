// cannot solve TLE

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n);
bool isPalindrome(long long n);
int main()
{
    long long a, b;
    cin >> a >> b;
    if (a % 2 == 0)
    {
        for (long long i = a + 1; i <= b; i += 2)
        {
            if (isPrime(i) && isPalindrome(i))
                cout << i << endl;
        }
    }
    if (a % 2 != 0)
        for (long long i = a; i <= b; i += 2)
        {
            if (isPrime(i) && isPalindrome(i))
                cout << i << endl;
        }
    return 0;
}

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPalindrome(long long n)
{
    long long original_num = n;
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    if (rev_num == original_num)
    {
        return true;
    }
    return false;
}