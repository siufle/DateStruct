//���ĺ����ֵܱ�ʾ��
//�ö�������洢 

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Node
//{
//	char data;
//	//ָ����
//	struct Node* ch;
//	//ָ���ұߵ�һ���ֵ�
//	struct Node* bro;
//}Node,*TreeList;
//
//TreeList Init(TreeList root, char r)
//{
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL)
//	{
//		printf("��ʼ��ʧ��");
//		return NULL;
//	}
//	s->data = r;
//	s->ch = NULL;
//	s->bro = NULL;
//	return s;
//}
//
//Node* Find(TreeList root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	if (root->ch != NULL)
//	{
//		Node* p = Find(root->ch, px);
//		if (p != NULL)
//		{
//			return p;
//		}
//	}
//	if (root->bro != NULL)
//	{
//		Node* p = Find(root->bro, px);
//		if (p != NULL)
//		{
//			return p;
//		}
//	}
//	return NULL;
//}
//
//TreeList Insert(TreeList root, char x, char px)
//{
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL)
//	{
//		printf("�½ڵ㴴��ʧ��");
//		return root;
//	}
//	s->data = x;
//	s->bro = NULL;
//	s->ch = NULL;
//	Node* parent = Find(root, px);
//	if (parent == NULL)
//	{
//		return root;
//	}
//	if (parent->ch == NULL)
//	{
//		parent->ch = s;
//	}
//	else 
//	{
//		Node* p = parent->ch;
//		if (p->bro != NULL)
//		{
//			p = p->bro;
//		}
//		p->bro = s;
//	}
//	return root;
//}
//
//int main()
//{
//	TreeList root = NULL;
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	root = Init(root, r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c", &px);
//		root = Insert(root, x, px);
//	}
//	getchar();
//	scanf_s("%c", &x);
//	Node* p = Find(root, x);
//	if (p->ch == NULL)
//	{
//		printf("%c��Ҷ�ӽڵ�\n", x);
//	}
//	else
//	{
//		Node* child = p->ch;
//		while (child != NULL)
//		{
//			printf("%c ", child->data);
//			child = child->bro;
//		}
//	}
//	return 0;
//}

/*
13
A
B A
C A
D A
E B
F B
G C
H D
I D
J D
K E
L E
M H

*/