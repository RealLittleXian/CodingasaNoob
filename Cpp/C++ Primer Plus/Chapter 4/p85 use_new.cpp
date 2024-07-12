#include <bits/stdc++.h>
using namespace std;

int main() {
    int nights=1001;
    int *pt = new int;      //allocate space for an int
    *pt = 1001;             //store a value there

    cout << "nights value = " << nights << ", value location = " << &nights << endl;
    cout << "int value = " << *pt << ", value location = " << pt << endl;
    double *pd = new double;  //allocate space for a double
    *pd = 10000001.0;        //store a value there

    cout << "double value = " << *pd << ", value location = " << pd << endl;
    cout << "location of the pointer, pd = " << &pd << endl;

    delete pt;  //free the space
    delete pd;
    return 0;
}   