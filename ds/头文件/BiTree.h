//结点结构体的定义
typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
} BiTreeNode;

//初始化
void Initiate(BiTreeNode **root)
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//左插入结点
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

//右插入结点
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

//左删除子树
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL)
		return NULL;
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

//右删除子树
BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL)
		return NULL;
	Destroy(&curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}
