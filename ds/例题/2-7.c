#include<stdio.h>
#include<malloc.h>
typedef int DataType;
#include "LinList.h"

void LinListSort(SLNode *head)
{
	SLNode *curr, *pre, *p, *q;
	p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		curr = head->next;
		pre = head;
		while (curr != NULL && curr->data <= p->data)
		{
			pre = curr;
			curr = curr->next;
		}
		q = p;
		p = p->next;
		q->next = pre->next;
		pre->next = q;
	}
}

void main()
{
	SLNode *head;
	int a[] = { 3,8,6,2 };
	int i, x;
	ListInitiate(&head);	//初始化
	for (i = 0; i < 4; i++)	//插入数据
	{
		ListInsert(head, i, a[i]);
	}
	LinListSort(head);	//对单链表中的数据进行递增排序
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d   ", x);
	}
}

