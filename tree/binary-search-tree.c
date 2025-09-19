//二叉搜索树/二叉排序树
//左子树 < 根节点 < 右子树

//#include<stdio.h>
//#include<stdlib.h>
//
////定义二叉搜索树节点
//typedef struct BSTNode {
//	int data;
//	struct BSTNode* lch;
//	struct BSTNode* rch;
//}BSTNode,*BSTree;
//
////搜索节点(非递归)
//BSTNode* Search(BSTree root, int x)
//{
//	BSTNode* p = root;
//	while (p != NULL && p->data != x)
//	{
//		if (x < p->data)
//		{//在左子树
//			p = p->lch;
//		}
//		else
//		{//在右子树
//			p = p->rch;
//		}
//	}
//	return p;
//}
//
////搜索节点(递归)
//BSTNode* SearchRecursion(BSTree root, int x)
//{
//	if (root == NULL || root->data == x)
//	{
//		return root;
//	}
//	if (x < root->data)
//	{
//		return SearchRecursion(root->lch, x);
//	}
//	else
//	{
//		return SearchRecursion(root->rch, x);
//	}
//}
//
////创建新节点
//BSTNode* CreateNode(char x)
//{
//	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
//	if (s == NULL)
//	{
//		printf("新节点创建失败");
//		return NULL;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	return s;
//}
//
////插入数据(非递归)
//BSTree Insert(BSTree root, int x)
//{
//	if (root == NULL)
//	{//空树
//		root = CreateNode(x);
//		return root;
//	}
//	BSTNode* s = CreateNode(x);
//	BSTNode* p = root;
//	BSTNode* pre = NULL;
//	while (p != NULL)
//	{
//		if (x < p->data)
//		{
//			pre = p;
//			p = p->lch;
//		}
//		else
//		{
//			pre = p;
//			p = p->rch;
//		}
//	}
//	if (x < pre->data)
//	{
//		pre->lch = s;
//	}
//	else
//	{
//		pre->rch = s;
//	}
//	return root;
//}
//
////插入数据(递归)
//BSTree InsertRecursion(BSTree root, int x)
//{
//	if (root == NULL)
//	{
//		BSTNode* s = CreateNode(x);
//		return s;
//	}
//	if (x < root->data)
//	{
//		root->lch = InsertRecursion(root->lch, x);
//	}
//	else
//	{
//		root->rch = InsertRecursion(root->rch, x);
//	}
//	return root;
//}
//
//int main()
//{
//	BSTree root = NULL;
//	int n;
//	int x;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &x);
//		//root = Insert(root, x);
//		root = InsertRecursion(root, x);
//	}
//	scanf_s("%d", &x);
//	BSTNode* p = SearchRecursion(root, x);
//	if (p != NULL)
//	{
//		printf("yes %d", x);
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}
/*
9
8 3 10 1 6 14 4 7 13
*/