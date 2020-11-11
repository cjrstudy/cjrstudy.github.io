//����
typedef struct
{
	char *str;
	int maxLength;
	int lenth;
} DString;

//��ʼ��
void Initiate(DString *S, int max, char *string)
{
	int i;
	S->str = (char *)malloc(sizeof(char)*max);
	S->maxLength = max;
	S->lenth = strlen(string);
	for(i = 0; i < S->lenth; i++)
		S->str[i] = string[i];
}

//����
int Insert(DString *S, int pos, DString T)
{
	int i;
	if(pos < 0)
	{
		printf("����pos����\n");
		return 0;
	}
	else
	{
		if(S->lenth + T.lenth > S->maxLength)
		{
			realloc(S->str, (S->lenth + T.lenth)*sizeof(char));
			S->maxLength = S->lenth + T.lenth;
		}
		for (i = S->lenth-1; i >= pos; i--)
			S->str[i+T.lenth] = S->str[i];
		for (i = 0; i < T.lenth; i++)
			S->str[pos + i] = T.str[i];
		return 1;
	}
}

//ɾ��
int Delete(DString *S, int pos, int len)
{
	int i;
	if(S->lenth <= 0)
	{
		printf("������δ����ַ���Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos + len > S->lenth)
	{
		printf("����pos��len���Ϸ�\n");
		return 0;
	}
	else
	{
		for(i = pos + len; i <= S->lenth-1; i++)
			S->str[i-len] = S->str[i];
		S->lenth = S->lenth - len;
		return 1;
	}
}

//ȡ�Ӵ�
int SubString(DString *S, int pos, int len, DString *T)
{
	int i;
	if(pos < 0 || len < 0 || pos + len > S->lenth)
	{
		printf("����pos��len����\n");
		return 0;
	}
	if(len > T->maxLength)
	{
		T->str = (char *)malloc(len*sizeof(char));
		T->maxLength = len;
	}
	for(i = 0; i < len; i++)
		T->str[i] = S->str[pos + i];
	T->lenth = len;
	return 1;
}

//����
void Destroy(DString *S)
{
	free(S->str);
	S->maxLength = 0;
	S->lenth = 0;
}