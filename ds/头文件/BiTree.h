//���ṹ��Ķ���
typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
} BiTreeNode;

//��ʼ��
void Initiate(BiTreeNode **root)
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//�������
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
	if(curr == NULL)
		return NULL;
	t = curr->leftChild;
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;
	s->rightChild = NULL;
	curr->leftChild = s;
	return curr->leftChild;
}

//�Ҳ�����
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
	if(curr == NULL)
		return NULL;
	t = curr->rightChild;
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;
	s->leftChild = NULL;
	curr->rightChild = s;
	return curr->rightChild;
}

//��ɾ������
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL)
		return NULL;
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

//��ɾ������
BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL)
		return NULL;
	Destroy(&curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}
