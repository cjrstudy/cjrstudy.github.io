#include <stdio.h>
#include <malloc.h>

void main()
{
	int *a, n = 10, i;
	a = (int *)calloc(n,sizeof(int));
	for(i = 0; i < n; i++)
		a[i] = i + 1;
	for(i = 0; i < n; i++)
		printf("%d  ", a[i]);
	free(a);
}
