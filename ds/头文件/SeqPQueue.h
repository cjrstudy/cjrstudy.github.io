//定义队列元素结构体
typedef struct
{
	int priority;
	ElemType elem;
}DataType;


//定义优先级队列结构体
typedef struct
{
	DataType queue[MaxQueueSize];
	int size;
}SeqPQueue;

//初始化优先队列
void QueueInitiate(SeqPQueue *Q)
{
	Q->size = 0;
}

//非空否
int QueueNoEmpty(SeqPQueue Q)
{
	if(Q.size <= 0)
		return 0;
	else
		return 1;
}

//插入数据元素
int QueueAppend(SeqPQueue *Q, DataType x)
{
	if(Q->size >= MaxQueueSize)
	{
		printf("队列已满无法插入！\n");
		return 0;
	}
	else 
	{
		Q->queue[Q->size] = x;
		Q->size ++;
		return 1;
	}
}

//删除数据元素
int QueueDelete(SeqPQueue *Q, DataType *d)
{
	DataType min;
	int minIndex, i;
	if(Q->size <= 0)
	{
		printf("队列已空无数据元素出队列！\n");
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

//取优先队列中优先级最高的元素
int QueueGet(SeqPQueue *Q, DataType *d)
{
	DataType min;
	int minIndex,i;
	if(Q->size <= 0)
	{
		printf("队列已空无数据元素可取！\n");
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