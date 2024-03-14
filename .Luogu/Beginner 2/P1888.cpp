#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, q, r;
    cin >> a >> b >> c;
    q = min(a, min(b, c));
    r = max(a, max(b, c));

    cout << q / __gcd(q, r) << "/" << r / __gcd(q, r) << endl;
    return 0;
}