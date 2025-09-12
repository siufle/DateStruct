//树的遍历方式

//1.广度遍历(层次遍历)
//借助队列实现  先将根节点入队 然后循环(直到队内无元素)将队首元素出队再将出队元素的子树入队

//2.深度遍历(先序，中序，后序遍历)

//#include<stdio.h>
//#include<stdlib.h>
//
////定义队列节点
//typedef struct QNode
//{
//	char data;
//	struct QNode* next;
//}QNode;
//
////定义队列
//typedef struct Queue
//{
//	//队首指针
//	QNode* f;
//	//队尾指针
//	QNode* r;
//}Queue;
//
////初始化队列
//Queue InitQueue()
//{
//	Queue q;
//	q.f = (QNode*)malloc(sizeof(QNode));
//	if (q.f == NULL)
//	{
//		printf("初始化失败");
//		return q;
//	}
//	q.f->next = NULL;
//	q.r = q.f;
//	return q;
//}
//
////入队
//void EnQueue(Queue* q, char x)
//{
//	QNode* s = (QNode*)malloc(sizeof(QNode));
//	if (s == NULL)
//	{
//		printf("新节点创建失败");
//		return;
//	}
//	s->data = x;
//	s->next = NULL;
//	q->r->next = s;
//	q->r = s;
//}
//
////判空
////1表示空  0表示非空
//int IsEmpty(Queue* q)
//{
//	if (q->f->next == NULL)
//	{
//		return 1;
//	}
//	return 0;
//}
//
////出队
//char DeQueue(Queue* q)
//{
//	if (IsEmpty(q) == 1)
//	{
//		printf("队空\n");
//		return ' ';
//	}
//	else 
//	{
//		QNode* p = q->f->next;
//		char c = p->data;
//		if (q->r == q->f->next)
//		{
//			q->r = q->f;
//		}
//		q->f->next = p->next;
//		free(p);
//		p = NULL;
//		return c;
//	}
//}
//
////-------------------------------------------
//
////定义二叉链表节点
//typedef struct BTNode
//{
//	char data;
//	struct BTNode* lch;
//	struct BTNode* rch;
//}BTNode,*LinkBTree;
//
//
//
////初始化
//LinkBTree InitBTree(char r)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("初始化失败");
//		return NULL;
//	}
//	s->data = r;
//	s->lch = NULL;
//	s->rch = NULL;
//	return s;
//}
//
////查找
//BTNode* Find(LinkBTree root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	if (root->lch != NULL)
//	{
//		BTNode* ans = Find(root->lch, px);
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
////插入
//LinkBTree Insert(LinkBTree root, char x, char px, int flag)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("新节点创建失败");
//		return root;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	BTNode* parent = Find(root,px);
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
////层次遍历
//void levelOrderBT(LinkBTree root)
//{
//	Queue q = InitQueue();
//	EnQueue(&q, root->data);
//	while (IsEmpty(&q) == 0)
//	{
//		char c = DeQueue(&q);
//		printf("%c ", c);
//		BTNode* p = Find(root, c);
//		if (p->lch != NULL)
//		{
//			EnQueue(&q, p->lch->data);
//		}
//		if (p->rch != NULL)
//		{
//			EnQueue(&q, p->rch->data);
//		}
//	}
//}
//
////先序遍历
//void PreOrderBT(LinkBTree root)
//{
//	//递归结束条件
//	if (root == NULL)
//	{
//		return;
//	}
//	//输出根节点数据
//	printf("%c ", root->data);
//	//遍历左子树
//	PreOrderBT(root->lch);
//	//遍历右子树
//	PreOrderBT(root->rch);
//}
//
////中序遍历
//void InOrderBT(LinkBTree root)
//{
//	//递归结束条件
//	if (root == NULL)
//	{
//		return;
//	}
//	//遍历左子树
//	PreOrderBT(root->lch);
//	//输出根节点数据
//	printf("%c ", root->data);
//	//遍历右子树
//	PreOrderBT(root->rch);
//}
//
////后序遍历
//void PostOrderBT(LinkBTree root)
//{
//	//递归结束条件
//	if (root == NULL)
//	{
//		return;
//	}
//	//遍历左子树
//	PreOrderBT(root->lch);
//	//遍历右子树
//	PreOrderBT(root->rch);
//	//输出根节点数据
//	printf("%c ", root->data);
//}
//
//int main()
//{
//	LinkBTree root = NULL;
//	//用于记录当前输入的是左孩子还是右孩子
//	int flag;
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	root = InitBTree(r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c ", &px);
//		scanf_s("%d", &flag);
//		root = Insert(root, x, px, flag);
//	}
//	//levelOrderBT(root);
//	//PreOrderBT(root);
//	//InOrderBT(root);
//	PostOrderBT(root);
//	return 0;
//}

/*
9
A
B A 0
E A 1
C B 1
F E 1
D C 0
G F 0
H G 0
K G 1
*/