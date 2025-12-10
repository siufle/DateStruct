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

//-----------------------------删除---------------------------------------

//找到节点所在位置
RBTNode* Find(RBTree root, int k)
{
	if (root == NULL) return NULL;
	if (root->data == k) return root;
	else if (root->data > k) return Find(root->left, k);
	else return Find(root->right, k);
}

//删除后调整 删除前p是y的父亲 删除后p是x的父亲
RBTree De_FixUp(RBTree root, RBTNode* x, RBTNode* p)
{
	//x可能是根节点 则直接将x的颜色改为黑色即可
	//y黑 x红：一定破坏"黑路同" 将x的颜色改为黑色即可 可以和x为根节点的情况一起处理
	//讨论x为黑色的情况即可
	RBTNode* w = NULL;//删除前y的兄弟x的叔叔 删除后x的兄弟
	//由于w没有红色孩子的情况需要循环向上调整 因此要套在循环中 直到x为根节点或x的父亲为黑色结束
	while (x != root && (x == NULL || (x != NULL && x->color == BLACK)))
	{//x不是根节点 p一定存在
		if (x == p->right)
		{//x是p的右孩子
			w = p->left;
			//w是红色的情况几步操作后可以转化为w是黑色的情况
			if (w != NULL && w->color == RED)
			{
				//w变黑 p变红
				w->color = BLACK;
				p->color = RED;
				//对p右旋
				root = RightRotate(root, p);
				w = p->left;
			}
			//w两个孩子都是黑
			if ((w->left == NULL ||  w->left->color == BLACK) &&
				(w->right == NULL ||  w->right->color == BLACK))
			{
				//w褪去黑色变红 将褪去的黑色给父亲p
				w->color = RED;
				//p成为了新的要调整的节点x
				x = p;
				p = x->pa;
			}
			else
			{//至少有一个孩子是红色
				RBTNode* red = NULL;//指向红色的孩子
				if (w->left == NULL || (w->left != NULL && w->left->color == BLACK))
				{//左孩子不是红色且右孩子是红色 此时相当于LR
					red = w->right;
					//对w左旋
					root = LeftRotate(root, w);
					//将red变黑w变红
					red->color = BLACK;
					w->color = RED;
					//交换red和w的指针
					RBTNode* t = red;
					red = w;
					w = t;
				}
				//此时相当于LL
				red = w->left;
				//将w变成p的颜色
				w->color = p->color;
				//对p右旋
				root = RightRotate(root, p);
				//将red和p变黑
				red->color = BLACK;
				p->color = BLACK;
				break;
			}
		}
		else
		{//x是p的左孩子 w是p的右孩子
			w = p->right;
			//w是红色的情况几步操作后可以转化为w是黑色的情况
			if (w != NULL && w->color == RED)
			{
				//w变黑 p变红
				w->color = BLACK;
				p->color = RED;
				//对p左旋
				root = LeftRotate(root, p);
				w = p->right;
			}
			//w两个孩子都是黑
			if ((w->left == NULL || w->left->color == BLACK) &&
				(w->right == NULL || w->right->color == BLACK))
			{
				//w褪去黑色变红 将褪去的黑色给父亲p
				w->color = RED;
				//p成为了新的要调整的节点x
				x = p;
				p = x->pa;
			}
			else
			{//至少有一个孩子是红色
				RBTNode* red = NULL;//指向红色的孩子
				if (w->right == NULL || (w->right != NULL && w->right->color == BLACK))
				{//右孩子不是红色且左孩子是红色 此时相当于RL
					red = w->right;
					//对w右旋
					root = RightRotate(root, w);
					//将red变黑w变红
					red->color = BLACK;
					w->color = RED;
					//交换red和w的指针
					RBTNode* t = red;
					red = w;
					w = t;
				}
				//此时相当于LL
				red = w->right;
				//将w变成p的颜色
				w->color = p->color;
				//对p左旋
				root = LeftRotate(root, p);
				//将red和p变黑
				red->color = BLACK;
				p->color = BLACK;
				break;
			}
		}
	}
	if (x != NULL) x->color = BLACK;
	return root;
}

//删除
RBTree Delete(RBTree root, int k)
{
	if (root == NULL)
	{
		printf("红黑树为空，无法删除\n");
		return root;
	}
	//先找到删除节点所在位置
	RBTNode* y = Find(root, k);
	if (y == NULL) 
	{
		printf("未找到要删除的节点\n");
		return root;
	}
	//判断y的度为几
	if (y->left != NULL && y->right != NULL)
	{//度为2 先找后继
		RBTNode* next = y->right;
		while (next->left != NULL) next = next->left;
		//将后继与要删除节点交换数据
		int temp = next->data;
		next->data = y->data;
		y->data = temp;
		y = next;
	}
	RBTNode* x = NULL;//y的孩子
	if (y->left != NULL) x = y->left;
	else x = y->right;
	//删除y 并由x继承y的所有关系
	RBTNode* p = y->pa;
	if(x != NULL) x->pa = p;
	if (p == NULL)
	{//y为根节点
		root = x;
	}
	else if (y == p->left)
	{//y不为根节点且y是其父亲节点的左孩子
		p->left = x;
	}
	else
	{//y不为根节点且y是其父亲节点的右孩子
		p->right = x;
	}
	int yc = y->color;//提前记录y的颜色 y为黑色才会破坏红黑规则
	free(y);
	y = NULL;
	if (root == NULL) return NULL;
	if (yc == BLACK)
	{
		root = De_FixUp(root, x, p);
	}
	return root;
}

//-----------------------------删除---------------------------------------

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
	int k;
	while (1)
	{
		printf("-------------------------\n");
		scanf_s("%d", &k);
		if (k == -1)
		{
			break;
		}
		root = Delete(root, k);
		InOrder(root);
	}
	return 0;
}

/*
9
10 40 30 60 90 70 20 50 80
*/