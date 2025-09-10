//孩子表示法

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 20
//
//typedef struct ChNode
//{
//	//数据域 存储孩子节点的索引
//	int chi;
//	struct ChNode* next;
//}ChNode;
//
////存储树的长度
//int len = 0;
//
//struct Tree
//{
//	char data;
//	//存储孩子节点索引的链表
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
//		printf("新节点创建失败");
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
//		printf("%c是叶子节点", x);
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