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
////中序遍历
//void InOrder(BSTree root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	InOrder(root->lch);
//	printf("%d ", root->data);
//	InOrder(root->rch);
//}
//
////删除节点(非递归)
//BSTree DeleteBSTNode(BSTree root, int x)
//{
//	if (root == NULL)
//	{
//		printf("树为空 无法删除\n");
//		return root;
//	}
//	BSTNode* p = root;
//	BSTNode* pre = NULL;
//	//找到要删除的节点p和他的父亲节点
//	while (p->data != x)
//	{
//		pre = p;
//		if (x < p->data)
//		{
//			p = p->lch;
//		}
//		else
//		{
//			p = p->rch;
//		}
//	}
//	//度为2 删除当前节点 找到中序序列中当前节点的后继 使其取代当前节点的位置 
//	//直接将当前节点的值改变为后继节点的值 并将后继节点删除
//	if (p->lch != NULL && p->rch != NULL)
//	{
//		BSTNode* h = p->rch;
//		BSTNode* fh = p;
//		while (h->lch != NULL)
//		{
//			fh = h;
//			h = h->lch;
//		}
//		p->data = h->data;
//		p = h;
//		pre = fh;
//	}
//	//度为1或0 删除p节点
//	BSTNode* ch = NULL;
//	if (p->lch != NULL)
//	{
//		ch = p->lch;
//	}
//	else
//	{
//		ch = p->rch;
//	}
//	//要删除的节点为根节点
//	if (pre == NULL)
//	{
//		root = ch;
//	}
//	else
//	{
//		if (p == pre->lch)
//		{
//			pre->lch = ch;
//		}
//		else
//		{
//			pre->rch = ch;
//		}
//	}
//	free(p);
//	p = NULL;
//	return root;
//}
//
////删除节点(递归)
//BSTree DeleteBSTNodeRecursion(BSTree root, int x)
//{
//	if (root == NULL)
//	{
//		printf("树为空 无法删除\n");
//		return root;
//	}
//	if (x < root->data)
//	{
//		root->lch = DeleteBSTNodeRecursion(root->lch, x);
//	}
//	else if (x > root->data)
//	{
//		root->rch = DeleteBSTNodeRecursion(root->rch, x);
//	}
//	else
//	{
//		//度为2
//		if (root->lch != NULL && root->rch != NULL)
//		{
//			//找当前节点在中序序列中的前驱
//			BSTNode* p = root->lch;
//			while (p->rch != NULL)
//			{
//				p = p->rch;
//			}
//			root->data = p->data;
//			root->lch = DeleteBSTNodeRecursion(root->lch, p->data);
//		}
//		else //度为0或1
//		{
//			BSTNode* p = root;
//			if (root->lch != NULL)
//			{
//				root = root->lch;
//			}
//			else
//			{
//				root = root->rch;
//			}
//			free(p);
//			p = NULL;
//		}
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
//	InOrder(root);
//	printf("\n");
//	scanf_s("%d", &x);
//	//DeleteBSTNode(root, x);
//	DeleteBSTNodeRecursion(root, x);
//	InOrder(root);
//	printf("\n");
//	/*BSTNode* p = SearchRecursion(root, x);
//	if (p != NULL)
//	{
//		printf("yes %d", x);
//	}
//	else
//	{
//		printf("no");
//	}*/
//	return 0;
//}
/*
9
8 3 10 1 6 14 4 7 13
*/