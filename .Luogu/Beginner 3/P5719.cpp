#include <iostream>
using namespace std;
int main()
{
    int n, k, sA = 0, sB = 0, cA = 0, cB = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            sA += i;
            cA++;
        }
        else
        {
            sB += i;
            cB++;
        }
    }
    printf("%.1lf %.1lf", (double)sA / cA, (double)sB / cB);
}