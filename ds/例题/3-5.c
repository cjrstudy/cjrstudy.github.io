#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "PrintTaskManager.h"

void main()
{
	char ch = '0';
	int tid = 0;
	char *text = "��ӡ����";
	Queue Q;
	InitaskManager(&Q);
	while(ch != 'q')
	{
		printf("1 ����");
		printf("\t2 ���");
		printf("\t3 ���");
		printf("\t4 ���");
		printf("\tq �˳�");
		printf("\nPlease enter:");
		ch = getchar();
		getchar();
		switch(ch)
		{
			case '1':
				tid = tid + 1;
				AppendPrintTask(&Q, tid, text);
				break;
			case '2':
				PrintFirstTask(&Q);
				break;
			case '3':
				PrintAllTask(&Q);
				break;
			case '4':
				ClearPrintTask(&Q);
				break;
			case 'q':
				return;
 		}
	}
}