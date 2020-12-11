//ǰ�����
void PreOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		visit(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}

//�������
void InOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		InOrder(root ->leftChild, visit);
		visit(root->data);
		InOrder(root->rightChild,visit);
	}
}

//�������
void PostOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{
		PostOrder(root->leftChild, visit);
		PostOrder(root->rightChild, visit);
		visit(root->data);
	}
}

//����������
void Destroy(BiTreeNode **root)
{
	if((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);
	if((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);
	free(*root);
}
