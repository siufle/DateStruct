//红黑树

#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1

//定义红黑树节点
typedef struct RBTNode
{
	int data;//数据域
	int color;//节点颜色
	struct RBTNode* left;//左孩子
	struct RBTNode* right;//右孩子
	struct RBTNode* pa;//父亲节点
}RBTNode,*RBTree;

//创建新节点
RBTNode* CreateNode(int k, RBTNode* parent)
{
	RBTNode* p = (RBTNode*)malloc(sizeof(RBTNode));
	if (p == NULL)
	{
		printf("新节点创建失败\n");
		return NULL;
	}
	p->data = k;
	p->color = RED; //新节点的颜色默认为红色
	p->left = NULL;
	p->right = NULL;
	p->pa = parent;
	return p;
}

//左旋
RBTree LeftRotate(RBTree root, RBTNode* x)
{
	//将y指向x的右孩子
	RBTNode* y = x->right;
	//将y的左孩子调整为x的右孩子
	x->right = y->left;
	if (y->left != NULL) y->left->pa = x;
	//将y的父亲节点调整为x的父亲节点
	y->pa = x->pa;
	//如果x的父亲节点不为空 将x的父亲节点的某一个子节点调整为y
	if (x->pa != NULL)
	{//x不是根节点
		if (x == x->pa->left) x->pa->left = y;
		else x->pa->right = y;
	}
	else
	{//x是根节点
		root = y;
	}
	//将x调整为y的左孩子
	y->left = x;
	x->pa = y;
	return root;
}

//右旋
RBTree RightRotate(RBTree root, RBTNode* x)
{
	//将y指向x的左孩子
	RBTNode* y = x->left;
	//将y的右孩子调整为x的左孩子
	x->left = y->right;
	if (y->right != NULL) y->right->pa = x;
	//将y的父亲节点调整为x的父亲节点
	y->pa = x->pa;
	//如果x的父亲节点不为空 将x的父亲节点的某一个子节点调整为y
	if (x->pa != NULL)
	{//x不是根节点
		if (x == x->pa->left) x->pa->left = y;
		else x->pa->right = y;
	}
	else
	{//x是根节点
		root = y;
	}
	//将x调整为y的右孩子
	y->right = x;
	x->pa = y;
	return root;
}

//调整红黑树  z为新插入节点
RBTree FixUp(RBTree root, RBTNode* z)
{//破坏了不红红
	RBTNode* p = z->pa; //指向z的父亲节点
	RBTNode* g = NULL; //指向z的爷爷节点
	RBTNode* u = NULL; //指向z的叔叔节点
	while (p != NULL && p->color != BLACK)
	{
		g = p->pa; //g节点一定不为空
		//判断当前节点是父亲节点的左孩子还是右孩子
		if (p == g->left)
		{//父亲是左孩子 叔叔就是右孩子
			u = g->right;
			//判断叔叔节点是红色还是黑色
			if (u != NULL && u->color == RED)
			{//红色
				//将叔叔和父亲都变成黑色
				p->color = BLACK;
				u->color = BLACK;
				//将爷爷变成红色
				g->color = RED;
				//以爷爷节点为新插入的节点再次进行循环
				z = g;
				p = z->pa;
			}
			else
			{//黑色 此时有两种可能 LL 和 LR
				if (z == p->right)
				{//LR
					//先将p节点左旋 将整体变成LL
					root = LeftRotate(root, p);
					//再交换z和p指针所指向的节点 然后再当作LL进行右旋
					RBTNode* temp = z;
					z = p;
					p = temp;
				}
				//LL
				//将p和g变色
				p->color = BLACK;
				g->color = RED;
				root = RightRotate(root, g);
			}
		}
		else
		{//右孩子
			u = g->left;
			//判断叔叔节点是红色还是黑色
			if (u != NULL && u->color == RED)
			{//红色
				//将叔叔和父亲都变成黑色
				p->color = BLACK;
				u->color = BLACK;
				//将爷爷变成红色
				g->color = RED;
				//以爷爷节点为新插入的节点再次进行循环
				z = g;
				p = z->pa;
			}
			else
			{//黑色 此时有两种可能 RR RL
				if (z == p->left)
				{//RL
					//先将p节点右旋 将整体变成RR
					root = RightRotate(root, p);
					//再交换z和p指针所指向的节点 然后再当作RR进行右旋
					RBTNode* temp = z;
					z = p;
					p = temp;
				}
				//RR
				//将p和g变色
				p->color = BLACK;
				g->color = RED;
				root = LeftRotate(root, g);
			}
		}
	}
	//判断根节点是红色还是黑色 若是红色则变黑
	if (root->color == RED) root->color = BLACK;
	return root;
}

//插入数据
RBTree Insert(RBTree root, int k)
{
	//判断插入的是根节点还是其他普通节点
	if (root == NULL)
	{//空插
		//创建新节点 并将其赋值给根节点
		root = CreateNode(k, NULL);
		//将节点颜色改为黑色
		root->color = BLACK;
		//直接返回根节点
		return root;
	}
	//非空插入
	//找到该插入的位置
	RBTNode* z = root;
	RBTNode* zp = NULL;//记录z节点的父亲节点
	while (z != NULL)
	{
		zp = z;
		if (k < z->data) z = z->left;
		else z = z->right;
	}
	//创建新节点
	z = CreateNode(k, zp);
	//插入
	if (z->data < zp->data) zp->left = z;
	else zp->right = z;
	//判断是否需要调整
	if (zp->color == RED)
	{//破坏了不红红
		root = FixUp(root, z);
	}
	return root;
}

//中序遍历
void InOrder(RBTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		if (root->color == RED) printf("RED ");
		else printf("BLACK  ");
		if (root->pa != NULL) printf("%d", root->pa->data);
		printf("\n");
		InOrder(root->right);
	}
}

int main()
{
	int n;//存储n个节点 n<=100
	int a[105];//存储n个节点
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//声明红黑树
	RBTree root = NULL;
	for (int i = 1; i <= n; i++)
	{
		root = Insert(root, a[i]);//插入数据
	}
	InOrder(root);
	return 0;
}

/*
9
10 40 30 60 90 70 20 50 80
*/