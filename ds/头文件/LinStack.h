//����
typedef struct snode
{
	DataType data;
	struct snode *next;
} LSNode;

//��ʼ��
void StackInitiate(LSNode **head)
{
	*head = (LSNode *)malloc(sizeof(LSNode));
	(*head)->next = NULL;
}

//�ǿշ�
int StackNotEmpty(LSNode *head)
{
	if(head->next == NULL)
		return 0;
	else
		return 1;
}

//��ջ
void StackPush(LSNode *head, DataType x)
{
	LSNode *p;
	p = (LSNode *)malloc(sizeof(LSNode));
	p->data = x;
	p->next = head->next;
	head->next = p;
}

//��ջ
int StackPop(LSNode *head, DataType *d)
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("��ջ�ѿճ���");
		return 0;
	}
	head->next = p->next;
	*d = p->data;
	free(p);
	return 1;
}

//ȡջ��Ԫ��
int StackTop(LSNode *head, DataType *d)
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("��ջ�ѿճ���");
		return 0;
	}
	*d = p->data;
	return 1;
}


//������̬����ռ�
void Destroy(LSNode *head)
{
	LSNode *p, *p1;
	p = head;
	while(p != NULL)
	{
		p1 = p;
		p = p->data;
		free(p1);
	}
}