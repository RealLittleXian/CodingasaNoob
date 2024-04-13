#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s,k=0;
    cin >> s;
    if (s<0){
        cout<<"-";
        s=abs(s);
    }
    while(s){
        k=k*10+s%10;
        s/=10;
    }
    cout << k;
    return 0;
}