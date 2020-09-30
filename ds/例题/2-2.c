#include<stdio.h>
#define MaxSize 100
typedef struct Student
{
	long number;
	char name[10];
	char sex[3];
	int age;
}StudentType;

typedef StudentType DataType;
#include "SeqList.h"

int main(void)
{
	SeqList myList;
	int i;
	StudentType x[3] = {{2000001,"张三","男",20},{2000002,"李四","男",21},{2000003,"王五","女",22}};
	StudentType s;
	ListInitiate(&myList);
	ListInsert(&myList,0,x[0]);
	ListInsert(&myList,1,x[1]);
	ListInsert(&myList,2,x[2]);

	for(i = 0; i < ListLength(myList); i++)
	{
		ListGet(myList, i, &s);
		printf("%d	%s	%s	%d\n",s.number,s.name,s.sex,s.age);
	}
	
}



