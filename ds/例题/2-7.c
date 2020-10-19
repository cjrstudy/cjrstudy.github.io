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
	ListInitiate(&head);	//��ʼ��
	for (i = 0; i < 4; i++)	//��������
	{
		ListInsert(head, i, a[i]);
	}
	LinListSort(head);	//�Ե������е����ݽ��е�������
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d   ", x);
	}
}

