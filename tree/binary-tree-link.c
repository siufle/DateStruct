//二叉树的链式表示法

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct BTNode
//{
//	char data;
//	//指向左孩子
//	struct BTNode* lch;
//	//指向右孩子
//	struct BTNode* rch;
//}BTNode,*LinkBTree;
//
////表示插入的节点是左孩子还是右孩子
////0表示左孩子  1表示右孩子
//int flag;
//
//LinkBTree InitRoot(char r)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("初始化失败\n");
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
//		printf("新节点创建失败\n");
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
//		printf("%c的左孩子是%c\n", x, p->lch->data);
//	}
//	else
//	{
//		printf("%c没有左孩子\n", x);
//	}
//	if (p->rch != NULL)
//	{
//		printf("%c的右孩子是%c\n", x, p->rch->data);
//	}
//	else
//	{
//		printf("%c没有右孩子\n", x);
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