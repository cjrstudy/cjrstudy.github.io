#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include "SeqList.h"

int ListMoreDataDelete(SeqList *L, DataType x)
{
	int i, j;
	int tag = 0;
	for(i=0; i<L->size;i++)
	{
		if(x == L->list[i])
		{
			for(j=i; j<L->size-1;j++)
				L->list[j] = L->list[j+1];
			L->size --;
			i--;
			tag = 1;
		}
	}
	return tag;
}

void main()
{


	SeqList mylist;
	int i, x, y;
	int a[10] = {1,2,3,3,4,5,6,3,5,9};
	ListInitiate(&mylist);
	for(i=0; i<10; i++)
		ListInsert(&mylist, i, a[i]);
	printf("��������Ҫɾ��������Ԫ��:");
	scanf("%d",&x);
	if(ListMoreDataDelete(&mylist, x)==0)
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