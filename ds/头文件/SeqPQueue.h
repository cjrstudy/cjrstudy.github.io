//�������Ԫ�ؽṹ��
typedef struct
{
	int priority;
	ElemType elem;
}DataType;


//�������ȼ����нṹ��
typedef struct
{
	DataType queue[MaxQueueSize];
	int size;
}SeqPQueue;

//��ʼ�����ȶ���
void QueueInitiate(SeqPQueue *Q)
{
	Q->size = 0;
}

//�ǿշ�
int QueueNoEmpty(SeqPQueue Q)
{
	if(Q.size <= 0)
		return 0;
	else
		return 1;
}

//��������Ԫ��
int QueueAppend(SeqPQueue *Q, DataType x)
{
	if(Q->size >= MaxQueueSize)
	{
		printf("���������޷����룡\n");
		return 0;
	}
	else 
	{
		Q->queue[Q->size] = x;
		Q->size ++;
		return 1;
	}
}

//ɾ������Ԫ��
int QueueDelete(SeqPQueue *Q, DataType *d)
{
	DataType min;
	int minIndex, i;
	if(Q->size <= 0)
	{
		printf("�����ѿ�������Ԫ�س����У�\n");
		return 0;
	}
	else
	{
		min = Q->queue[0];
		minIndex = 0;
		for(i = 1; i < Q->size; i++)
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}
		*d = Q->queue[minIndex];
		for(i = minIndex+1; i < Q->size; i++)
			Q->queue[i+1] = Q->queue[i];
		Q->size--;
		return 1;
	}
}

//ȡ���ȶ��������ȼ���ߵ�Ԫ��
int QueueGet(SeqPQueue *Q, DataType *d)
{
	DataType min;
	int minIndex,i;
	if(Q->size <= 0)
	{
		printf("�����ѿ�������Ԫ�ؿ�ȡ��\n");
		return 0;
	}
	else
	{
		min = Q->queue[0];
		minIndex = 0;
		for(i = 1; i < Q->size; i++)
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}
		*d = Q->queue[minIndex];
		return 1;
	}
}