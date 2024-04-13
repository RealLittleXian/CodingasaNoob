#include <iostream>

using namespace std;
int main()
{
    int k;
    long long n = LLONG_MAX;
    double sum = 0;
    cin >> k;
    for (long long i = 1; i < n; i++)
    {
        sum += (double)(1.0 / i);
        if (sum > (double)k)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

/*

#include<cstdio>
int main() {
    int k,n=0;
    scanf("%d",&k);
    for(double Sn=0;Sn<=k;++n,Sn+=1.0/n);
    printf("%d",n);
    return 0;
}

*/