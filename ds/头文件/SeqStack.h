//˳���ջ����
typedef struct
{
DataType stack[MaxStackSize];
int top;
}SeqStack;

//��ʼ��
void StackInitiate(SeqStack *S)
{
S->top=0;
}

//�ǿշ�
int StackNotEmpty(SeqStack S)
{
if(S.top<=0) return 0;
else return 1;
}

//��ջ
int StackPush(SeqStack *S,DataType x)
{
if(S->top>=MaxStackSize){
printf("is null!");
return 0;
}
else
{
S->stack[S->top]=x;
S->top++;
return 1;
}
}

//��ջ
int StackPop(SeqStack *s,DataType *d)
{
if(s->top<=0)
{
printf("the stack is empty!\n");
return 0;
}
else
{
s->top--;
*d=s->stack[s->top];
return 1;
}
}

//ȡջ��Ԫ��
int StackTop(SeqStack S,DataType *d)
{
if(S.top<=0)
{
printf("the stack is empty!");
return 0;
}
else
{
*d=S.stack[S.top-1];
return 1;
}
}