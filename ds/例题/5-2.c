#include <stdio.h>
#include <malloc.h>

int **Make2DArray(int row, int col)
{
	int **a, i;
	a = (int **)calloc(row, sizeof(int *));
	for(i = 0; i < row; i++)
		a[i] = (int *)calloc(col, sizeof(int));
	return a;
}

void Deliver2DArray(int **a, int row)
{
	int i;
	for(i = 0; i < row; i++)
		free(a[i]);
	free(a);
}

void main()
{
	int i, j, c;
	int row = 3, col = 4, **a;
	a = Make2DArray(row, col);
	c = 1;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			a[i][j] = c;
			c++;
		}
	}
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	Deliver2DArray(a, row);
}