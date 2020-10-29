#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "PrintTaskManager.h"

void main()
{
	char ch = '0';
	int tid = 0;
	char *text = "打印内容";
	Queue Q;
	InitaskManager(&Q);
	while(ch != 'q')
	{
		printf("1 加入");
		printf("\t2 完成");
		printf("\t3 输出");
		printf("\t4 清空");
		printf("\tq 退出");
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
