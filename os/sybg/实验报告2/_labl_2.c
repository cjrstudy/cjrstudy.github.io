#include<stdio.h>
void main()
{
	int i,j,a;
	while((i=fork())==-1);
	if(i>0)
		while((j=fork())==-1);
	else 
		for(a=1; a<=50; a++)
			printf("son%d",a);
	if(j>0)
		for(a=1; a<=50; a++)
			printf("father%d",a);
	else
		for(a=1; a<=50; a++)
			printf("daughter%d",a);

}
