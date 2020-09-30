//顺序表定义
typedef struct
{DataType list[MaxSize];
 int size;
}SeqList;


//初始化
void ListInitiate(SeqList *L)
{
 L->size=0;
}


//插入
int ListInsert(SeqList *L,int i,DataType x)
{
 int j;
 if(L->size>=MaxSize)
 {
  printf("the list is full!\n");
  return 0;
 }
 else if(i<0||i>L->size)
 {
  printf("'i' is wrong!\n");
  return 0;
 }
 else
 {for(j=L->size;j>i;j--)L->list[j]=L->list[j-1];
  L->list[i]=x;
  L->size++;
  return 1;
 }
}


//删除
int ListDelete(SeqList *L,int i,DataType *x)
{int j;
 if(L->size<=0)
 {
  printf("the list is empty!\n");
  return 0;
 }
 else if(i<0||i>L->size-1)
 {
  printf("'i' is wrong!\n");
  return 0;
 }
 else
 {*x=L->list[i];
  for(j=i+1;j<=L->size-1;j++)L->list[j-1]=L->list[j];
  L->size--;
  return 1;
 }
}


//求长度
int ListLength(SeqList L)
{
 return L.size;
}


//取数
ListGet(SeqList L,int i,DataType *x)
{
 if(i<0||i>L.size-1)
 {
  printf("'i' is wrong!\n");
  return 0;
 }
 else
 {*x=L.list[i];
  return 1;
 }
}
