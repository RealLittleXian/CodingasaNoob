#include <stdio.h>
#include <istream>
#include <iostream>
using namespace std;
int main02(void)
{
	int a,b,c,d,s;
	printf("input:");
	cin >> a;
	b = a / 100;
	c = (a - b*100) / 10;
	d = a % 10;
	s = b + c + d;
	printf("the sum is:");
		cout << s;
	return 0;
}
