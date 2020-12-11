//前序遍历
void PreOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		visit(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}

//中序遍历
void InOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		InOrder(root ->leftChild, visit);
		visit(root->data);
		InOrder(root->rightChild,visit);
	}
}

//后序遍历
void PostOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		PostOrder(root->leftChild, visit);
		PostOrder(root->rightChild, visit);
		visit(root->data);
	}
}

//撤销二叉树
void Destroy(BiTreeNode **root)
{
	if((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);
	if((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);
	free(*root);
}
