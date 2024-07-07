// solved TLE
/*
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
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_palindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

bool is_prime(int n) {
    if (n < 2) return false;
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> find_palindromic_primes(int a, int b) {
    vector<int> palindromic_primes;
    for (int i = a; i <= b; i++) {
        if (is_palindrome(i) && is_prime(i)) {
            palindromic_primes.push_back(i);
        }
    }
    return palindromic_primes;
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> palindromic_primes = find_palindromic_primes(a, b);
    for (int p : palindromic_primes) {
        cout << p << endl;
    }
    return 0;
}