#include<stdio.h>
#include<malloc.h>
typedef int DataType;
#include "LinList.h"

void LinListInsert(SLNode *head, DataType x)
{
	SLNode *curr, *pre, *q;
	curr = head->next;
	pre = head;
	while (curr != NULL && curr->data <= x)
	{
		pre = curr;
		curr = curr->next;
	}
	q = (SLNode *)malloc(sizeof(SLNode));
	q->data = x;
	q->next = pre->next;
	pre->next = q;
}

void main()
{
	SLNode *head;
	int a[5] = { 1, 3, 5, 7, 9 };
	int i, x, b[3];
	ListInitiate(&head);
	for (i = 0; i < 5; i++)
	{
		ListInsert(head, i, a[i]);
	}
	printf("请输入你要插入的数据元素：");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &b[i]);
		LinListInsert(head, b[i]);
	}
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d  ", x);
	}
}