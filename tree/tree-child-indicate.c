//���ӱ�ʾ��

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 20
//
//typedef struct ChNode
//{
//	//������ �洢���ӽڵ������
//	int chi;
//	struct ChNode* next;
//}ChNode;
//
////�洢���ĳ���
//int len = 0;
//
//struct Tree
//{
//	char data;
//	//�洢���ӽڵ�����������
//	ChNode* child;
//}t[MAX];
//
//void InitRoot(char r)
//{
//	t[0].data = r;
//	t[0].child = NULL;
//	len++;
//}
//
//int Find(char px)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (t[i].data == px)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void Insert(char x, char px)
//{
//	t[len].data = x;
//	t[len].child = NULL;
//	int parent = Find(px);
//	ChNode* s = (ChNode*)malloc(sizeof(ChNode));
//	if (s == NULL) 
//	{
//		printf("�½ڵ㴴��ʧ��");
//		return;
//	}
//	s->chi = len;
//	s->next = t[parent].child;
//	t[parent].child = s;
//	len++;
//}
//
//int main()
//{
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c", &px);
//		Insert(x, px);
//	}
//	getchar();
//	scanf_s("%c", &x);
//	int index = Find(x);
//	if (t[index].child == NULL)
//	{
//		printf("%c��Ҷ�ӽڵ�", x);
//	}
//	else
//	{
//		ChNode* p = t[index].child;
//		while (p != NULL) 
//		{
//			printf("%c ", t[p->chi].data);
//			p = p->next;
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