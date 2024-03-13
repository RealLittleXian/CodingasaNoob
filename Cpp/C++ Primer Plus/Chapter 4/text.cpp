#include <iostream>

using namespace std;

int main()
{
    int a=5,b=0,c=1;
    bool flag;

    flag=(a-=5||b++||--c);

    cout<<flag<<endl;
    cout<<a<<" "<<b<<" "<<c;

    return 0;
}