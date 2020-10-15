#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include "SeqList.h"

int ListDataDelete(SeqList * L, DataType x)
{
	int i, j;
	for(i=0; i<L->size; i++)
		if(x == L->list[i])
			break;
	if(i == L->size)
		return 0;
	else
	{
		for(j = i; j<L->size-1; j++)
			L->list[j] = L->list[j+1];
		L->size --;
		return 1;
	}
}

void main()
{
	SeqList mylist;
	int i, x, y;
	ListInitiate(&mylist);
	for(i=0; i<10; i++)
		ListInsert(&mylist, i, i+1);
	printf("��������Ҫɾ��������Ԫ��:");
	scanf("%d",&x);
	if(!ListDataDelete(&mylist, x))
		printf("��˳�����û��%d���Ԫ��", x);
	else
	{

		for(i=0; i<ListLength(mylist); i++)
		{
			ListGet(mylist, i, &y);
			printf("%d   ",y);
		}
	}
}