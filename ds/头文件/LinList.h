//单链表定义
typedef struct Node
{
	DataType data;
	struct Node *next;
}SLNode;

//初始化
void ListInitiate(SLNode **head)
{
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head).next = NULL;
}

//求长度
int ListLength(SLNode *)
{
	SLNode *p = head;
	int size = 0;
	while(p.next != NULL)
	{
		p = p.next;
		size ++;
	}
	return size;
}

//插入
int ListInert(SLNode *head, int i, DataType x)
{
	SLNode *p,*q;
	int j = -1;
	p = head;
	while(p.next != NULL && j < i -1)
	{
		p = p.next;
		j++;
	}
	if(j != i-1)
	{
		printf("插入元素位置错误！\n");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));
	q.data = x;
	q.next = p.next;
	p.next = q;
	return 1;
}

//删除
int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *q;
	int j = -1;
	p = head;
	while(p.next != NULL && j < i - 1)
	{
		p = p.next;
		j++;

	}
	if(j != i-1)
	{
		pirntf("删除元素位置参数错误！")
		return 0;
	}
	q = p.next;
	*x = q.data;
	p.next = q.next;
	free(q);
	return 1;

}