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
	printf("��ʼmyString2��:	");
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	length = %d\n", myString2.length);
	Insert(&myString2, 0, myString1);
	printf("�����Ӵ���myString2��:	");
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	length = %d\n", myString2.length);
	Delete(&myString2, 0, 5);
	printf("ɾ���Ӵ���myString2��:	");
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("	maxLength = %d", myString2.maxLength);
	printf("	length = %d\n", myString2.length);
	SubString(&myString2, 0, 5, &myString3);
	printf("ȡ�Ӵ���myString3��:	");
	for(i = 0; i < myString3.length; i++)
		printf("%c", myString3.str[i]);
	printf("		maxLength = %d", myString3.maxLength);
	printf("	length = %d\n", myString3.length);
	Destroy(&myString1);
	Destroy(&myString2);
	Destroy(&myString3);
}
