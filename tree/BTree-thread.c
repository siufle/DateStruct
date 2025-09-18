//二叉树线索化  基于中序遍历

//#include<stdio.h>
//#include<stdlib.h>
//
////定义二叉线索树的节点
//typedef struct BTNode {
//	char data;
//	struct BTNode* lch;
//	struct BTNode* rch;
//	//用于记录指针指向的是前驱后继还是孩子
//	//1 表示前驱或后继   0 表示孩子
//	int lflag;
//	int rflag;
//}BTNode, *BTree;
////用于记录前一个访问的节点
//BTNode* pre = NULL;
//
////初始化二叉线索树
//BTree InitBTree(char r)
//{
//	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//	if (root == NULL)
//	{
//		printf("初始化失败");
//		return NULL;
//	}
//	root->data = r;
//	root->lch = NULL;
//	root->rch = NULL;
//	root->lflag = 0;
//	root->rflag = 0;
//	return root;
//}
//
////查找节点
//BTNode* Find(BTree root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	BTNode* ans = NULL;
//	if (root->lch != NULL && root->lflag == 0)
//	{
//		//存在左子树且左孩子指针指向的就是左子树
//		ans = Find(root->lch, px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	if (root->rch != NULL && root->rflag == 0)
//	{
//		//存在右子树且右孩子指针指向的就是右子树
//		ans = Find(root->rch, px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	return NULL;
//}
//
////插入节点
//BTree Insert(BTree root, char x, char px, int flag)
//{
//	BTNode* parent = Find(root, px);
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return root;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	s->lflag = 0;
//	s->rflag = 0;
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
////将节点线索化
//void Visit(BTNode* p)
//{
//	if (p->lflag == 0 && p->lch == NULL)
//	{
//		p->lch = pre;
//		p->lflag = 1;
//	}
//	if (pre != NULL && pre->rflag == 0 && pre->rch == NULL)
//	{
//		pre->rch = p;
//		pre->rflag = 1;
//	}
//	pre = p;
//}
//
////中序遍历
//void InOrder(BTree root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	if (root->lflag == 0)
//	{
//		InOrder(root->lch);
//	}
//	Visit(root);
//	if (root->rflag == 0)
//	{
//		InOrder(root->rch);
//	}
//}
//
//int main()
//{
//	BTree root = NULL;
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	root = InitBTree(r);
//	char x;
//	char px;
//	int flag;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c ", &px);
//		scanf_s("%d", &flag);
//		root = Insert(root, x, px, flag);
//	}
//	//通过中序遍历将二叉树线索化
//	InOrder(root);
//	getchar();
//	scanf_s("%c", &x);
//	BTNode* p = Find(root, x);
//	//找前驱
//	if (p->lflag == 1)
//	{
//		if (p->lch == NULL)
//		{
//			printf("没前驱\n");
//		}
//		else 
//		{
//			printf("前驱是%c\n", p->lch->data);
//		}
//	}
//	else
//	{
//		//有左子树没记录前驱 左子树的最右端节点就是前驱
//		BTNode* q = p->lch;
//		while (q->rch != NULL && q->rflag == 0)
//		{
//			q = q->rch;
//		}
//		printf("前驱是%c\n", q->data);
//	}
//	//找后继
//	if (p->rflag == 1)
//	{
//		printf("后继是%c\n", p->rch->data);
//	}
//	else
//	{
//		//有右子树没记录后继 右子树的最左端节点就是后继
//		BTNode* q = p->rch;
//		while (q != NULL && q->lch != NULL && q->lflag == 0)
//		{
//			q = q->lch;
//		}
//		if (q != NULL)
//		{
//			printf("后继是%c\n", q->data);
//		}
//		else
//		{
//			printf("没后继\n");
//		}
//	}
//	return 0;
//}

/*
9
A
B A 0
E A 1
C B 1
D C 0
F E 1
G F 0
H G 0
K G 1
*/