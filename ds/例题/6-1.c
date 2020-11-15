#include <stdio.h>

long Fact(int n)
{
	int x;
	long y;
	if(n < 0)
	{
		printf("²ÎÊý´í£¡");
		return -1;
	}
	if(n == 0)
		return 1;
	else
		return n * Fact(n-1);
}

void main()
{
	long fn;
	fn = Fact(3);
	printf("%d", fn);
}
