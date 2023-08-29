#include <stdio.h>
int main(void)
{
	char a, b;
	int c;
	scanf_s("%c%c%d",&a,&b,&c);
	printf("%-2c,%-2c,%d\n", a, b,c);
	return 0;
}