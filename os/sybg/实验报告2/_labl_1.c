#include<stdio.h>
void main()
{
	int i;
	while((i=fork())==-1);
	printf("i=%d",i);
	if(i) printf("It is a parent process!");
	else  printf("It is a child process!");
}
