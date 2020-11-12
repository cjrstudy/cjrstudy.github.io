#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "DString.h"
int BFIndex(DString S, int start, DString T)
{
	int i = start, j = 0, v;
	while(i < S.length && j < T.length)
	{
		if(S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j == T.length)
		v = i - T.length;
	else 
		v = -1;
	return v;
}

void main()
{
	DString myString1, myString2;
	int max1 = 29, max2 = 9;
	int pos = 0;
	Initiate(&myString1, max1, "Data Structure Data Structure");
	Initiate(&myString2, max2, "Structure");

	pos = BFIndex(myString1, pos, myString2);
	printf("��һ�β���ʱ pos = %d\n", pos);
	pos = BFIndex(myString1, pos+1, myString2);
	printf("�ڶ��β���ʱ pos = %d\n", pos);
	Destroy(&myString1);
	Destroy(&myString2);
}
