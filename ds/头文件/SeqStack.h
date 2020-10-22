//顺序堆栈定义
typedef struct
{
DataType stack[MaxStackSize];
int top;
}SeqStack;

//初始化
void StackInitiate(SeqStack *S)
{
S->top=0;
}

//非空否
int StackNotEmpty(SeqStack S)
{
if(S.top<=0) return 0;
else return 1;
}

//入栈
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

//出栈
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

//取栈顶元素
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