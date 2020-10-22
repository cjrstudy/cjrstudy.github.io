#include <string.h>
#include <stdio.h>
#define MaxStackSize 100
typedef char DataType;
#include "SeqStack.h"

void ExpIsCorrect(char exp[], int n)
{
	SeqStack myStack;
	int i;
	char c;
	StackInitiate(&myStack);
	for(i=0; i<n; i++)
	{
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
			StackPush(&myStack, exp[i]);
		else if(exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c== '(')
			StackPop(&myStack, &c);
		else if(exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c!= '(')
		{
			printf("×óÓÒÀ¨ºÅÅä¶Ô´ÎÐò²»ÕýÈ·!\n");
			return;
		}
		else if(exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c== '[')
			StackPop(&myStack, &c);
		else if(exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c!= '[')
		{
			printf("×óÓÒÀ¨ºÅÅä¶Ô´ÎÐò²»ÕýÈ·!\n");
			return;
		}
		else if(exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c== '{')
			StackPop(&myStack, &c);
		else if(exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c!= '{')
		{
			printf("×óÓÒÀ¨ºÅÅä¶Ô´ÎÐò²»ÕýÈ·!\n");
			return;
		}
		else if(((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) && !StackNotEmpty(myStack))
		{
			printf("ÓÒÀ¨ºÅ¶àÓÚ×óÀ¨ºÅ!\n");
			return;
		}
	}

	if(StackNotEmpty(myStack))
		printf("×óÀ¨ºÅ¶àÓÚÓÒÀ¨ºÅ!\n");
	else
		printf("×óÓÒÀ¨ºÅÆ¥ÅäÕýÈ·!\n");
}

void main()
{
	char a[] = "(())abc{[]()}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]}";
	int n1 = strlen(a);
	int n2 = strlen(b);
	int n3 = strlen(c);
	int n4 = strlen(d);
	ExpIsCorrect(a, n1);
	ExpIsCorrect(b, n2);
	ExpIsCorrect(c, n3);
	ExpIsCorrect(d, n4);
}