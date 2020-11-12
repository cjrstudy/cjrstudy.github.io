//����
typedef struct
{
	char *str;
	int maxLength;
	int length;
} DString;

//��ʼ��
void Initiate(DString *S, int max, char *string)
{
	int i;
	S->str = (char *)malloc(sizeof(char)*max);
	S->maxLength = max;
	S->length = strlen(string);
	for(i = 0; i < S->length; i++)
		S->str[i] = string[i];
}

//����
int Insert(DString *S, int pos, DString T)
{
	int i;
	if(pos < 0)
	{
		printf("����pos����");
		return 0;
	}
	else
	{
		if(S->length + T.length > S->maxLength)
		{
			realloc(S->str, (S->length + T.length)*sizeof(char));
			S->maxLength = S->length + T.length;
		}
		for (i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];
		for (i = 0; i < T.length; i++)
			S->str[pos + i] = T.str[i];
		S->length += T.length;
		return 1;
	}
}

//ɾ��
int Delete(DString *S, int pos, int len)
{
	int i;
	if(S->length <= 0)
	{
		printf("������δ����ַ���Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("����pos��len���Ϸ�");
		return 0;
	}
	else
	{
		for(i = pos + len; i <= S->length-1; i++)
			S->str[i-len] = S->str[i];
		S->length = S->length - len;
		return 1;
	}
}

//ȡ�Ӵ�
int SubString(DString *S, int pos, int len, DString *T)
{
	int i;
	if(pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("����pos��len����");
		return 0;
	}
	if(len > T->maxLength)
	{
		T->str = (char *)malloc(len*sizeof(char));
		T->maxLength = len;
	}
	for(i = 0; i < len; i++)
		T->str[i] = S->str[pos + i];
	T->length = len;
	return 1;
}

//����
void Destroy(DString *S)
{
	free(S->str);
	S->maxLength = 0;
	S->length = 0;
}