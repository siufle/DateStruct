//����������ʽ��ʾ��

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct BTNode
//{
//	char data;
//	//ָ������
//	struct BTNode* lch;
//	//ָ���Һ���
//	struct BTNode* rch;
//}BTNode,*LinkBTree;
//
////��ʾ����Ľڵ������ӻ����Һ���
////0��ʾ����  1��ʾ�Һ���
//int flag;
//
//LinkBTree InitRoot(char r)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("��ʼ��ʧ��\n");
//		return NULL;
//	}
//	s->data = r;
//	s->lch = NULL;
//	s->rch = NULL;
//	return s;
//}
//
//BTNode* Find(LinkBTree root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	if (root->lch != NULL)
//	{
//		BTNode* ans = Find(root->lch,px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	if (root->rch != NULL)
//	{
//		BTNode* ans = Find(root->rch, px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	return NULL;
//}
//
//LinkBTree Insert(LinkBTree root, char x, char px)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("�½ڵ㴴��ʧ��\n");
//		return root;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	BTNode* parent = Find(root, px);
//	if (flag == 0)
//	{
//		parent->lch = s;
//	}
//	else
//	{
//		parent->rch = s;
//	}
//	return root;
//}
//
//int main()
//{
//	LinkBTree root = NULL;
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	root = InitRoot(r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c ", &px);
//		scanf_s("%d", &flag);
//		root = Insert(root, x, px);
//	}
//	getchar();
//	scanf_s("%c", &x);
//	BTNode* p = Find(root, x);
//	if (p->lch != NULL)
//	{
//		printf("%c��������%c\n", x, p->lch->data);
//	}
//	else
//	{
//		printf("%cû������\n", x);
//	}
//	if (p->rch != NULL)
//	{
//		printf("%c���Һ�����%c\n", x, p->rch->data);
//	}
//	else
//	{
//		printf("%cû���Һ���\n", x);
//	}
//	return 0;
//}

/*
7
a
b a 0
c a 1
d b 0
e b 1
f e 0
g e 1

*/