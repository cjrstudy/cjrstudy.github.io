#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "DString.h"

void main()
{
	DString myString1, myString2, myString3;
	int i, max1 = 5, max2 = 9, max3 = 0;
	Initiate(&myString1, max1, "Data");
	Initiate(&myString2, max2, "Structure");
	Initiate(&myString3, max3, " ");
	printf("��ʼmyString2��:			");
	for(i = 0; i < myString2.lenth; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	lenth = %d\n", myString2.lenth);
	Insert(&myString2, 0, myString1);
	printf("�����Ӵ���myString2��:	\n");
	for(i = 0; i < myString2.lenth; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	lenth = %d\n", myString2.lenth);
	Delete(&myString2, 0, 5);
	printf("ɾ���Ӵ���myString2��:	\n");
	for(i = 0; i < myString2.lenth; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	lenth = %d\n", myString2.lenth);
	SubString(&myString2, 0, 5, &myString3);
	printf("ȡ�Ӵ���myString3��:		\n");
	for(i = 0; i < myString3.lenth; i++)
		printf("%c", myString3.str[i]);
	printf("	maxLength = %d", myString3.maxLength);
	printf("	lenth = %d\n", myString3.lenth);
	Destroy(&myString1);
	Destroy(&myString2);
	Destroy(&myString3);
}
