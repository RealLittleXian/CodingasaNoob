#include <bits/stdc++.h>
using namespace std;
/*
sto - storage
rem - remainder
bud - budget
n - *100

*/
int main()
{
    int sto = 0, rem = 0, bud, n;
    for (int i = 1; i <= 12; i++)
    {
        cin >> bud;
        rem += 300 - bud;
        if (rem >= 100)
        {
            n = (rem / 100) * 100;
            rem -= n;
            sto += n;
        }
        else if (rem < 0)
        {
            cout << -i;
            return 0;
        }
    }
    rem += sto * 1.2;
    cout << rem;
    return 0;
}