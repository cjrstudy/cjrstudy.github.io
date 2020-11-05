  
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
typedef int DataType;
#include "LinStack.h"
int PostExp(char str[])
{
	DataType x, x1, x2;
	int i;
	LSNode *head;
	StackInitiate(&head);
	for(i=0; str[i] != '#'; i++)
	{
		if(isdigit(str[i]))
		{
			x = (int)(str[i] - 48);
			StackPush(head, x);
		}
		else
		{
			StackPop(head, &x2);
			StackPop(head, &x1);
			switch(str[i])
			{
				case '+': {x1 += x2; break;}
				case '-': {x1 -= x2; break;}
				case '*': {x1 *= x2; break;}
				case '/': 
					if(x2 == 0)
					{
						printf("除数为0错！\n");
						exit(0);
					}
					else
					{
						x1 /= x2;
						break;
					}
			}
			StackPush(head, x1);
		}
	}
	StackPop(head, &x);
	return x;
}

void main()
{
	char str[] = "3642/-5*+#";
	int result;
	result = PostExp(str);
	printf("后缀算术表达式计算结果为：%d", result);
}