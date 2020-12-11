#include <stdlib.h>
#include <stdio.h>
typedef char DataType;
#include "BiTree.h"
#include "BiTreeTraverse.h"

void Visit(DataType item)
{
	printf("%c ", item);
}

void PrintBiTree(BiTreeNode *root, int n)
{
	int i;
	if(root == NULL)
		return;
	PrintBiTree(root->rightChild, n+1);
	for(i = 0; i < n-1; i++)
		printf("  ");
	if(n > 0)
	{
		printf("---");
		printf("%c\n", root->data);
	}
	PrintBiTree(root->leftChild, n+1);
}

BiTreeNode *Search(BiTreeNode *root, DataType x)
{
	BiTreeNode *find = NULL;
	if(root != NULL)
	{
		if(root->data == x)
			find = root;
		else
		{
			find = Search(root->leftChild, x);
			if(find == NULL)
				find = Search(root->rightChild, x);
		}
	}

	return find;
}

void main()
{
	BiTreeNode *root, *p, *find;
	char x = 'E';
	Initiate(&root);
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	InsertLeftNode(p, 'E');
	InsertRightNode(p, 'F');
	PrintBiTree(root, 0);
	printf("前序遍历");
	PreOrder(root->leftChild, Visit);
	printf("\n中序遍历");
	InOrder(root->leftChild, Visit);
	printf("\n后序遍历");
	PostOrder(root->leftChild, Visit);
	find = Search(root, x);
	if(find != NULL)
		printf("\n数据元素%c在二叉树中", x);
	else
		printf("\n数据元素%c不在二叉树中", x);
	Destroy(&root);
}
