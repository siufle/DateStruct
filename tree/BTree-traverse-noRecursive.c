//树的深度遍历(非递归)
//利用栈 循环实现

//#include<stdio.h>
//#include<stdlib.h>
//
////二叉树节点
//typedef struct BTNode
//{
//	char data;
//	struct BTNode* lch;
//	struct BTNode* rch;
//}BTNode, *LinkBTree;
//
////栈节点
//typedef struct SNode
//{
//	struct BTNode* data;
//	struct SNode* next;
//}SNode,*LinkStack;
//
////初始化栈
//LinkStack InitStack()
//{
//	SNode* h = (SNode*)malloc(sizeof(SNode));
//	if (h == NULL)
//	{
//		printf("初始化失败");
//		return NULL;
//	}
//	h->next = NULL;
//	return h;
//}
//
////入栈
//void Push(LinkStack s ,BTNode* k)
//{
//	SNode* p = (SNode*)malloc(sizeof(SNode));
//	if (p == NULL)
//	{
//		printf("新节点创建失败");
//		return;
//	}
//	p->data = k;
//	p->next = s->next;
//	s->next = p;
//}
//
////判空
//int IsEmpty(LinkStack s)
//{
//	if (s->next == NULL)
//	{
//		return 1;//空
//	}
//	return 0;//非空
//}
//
////出栈
//BTNode* Pop(LinkStack s)
//{
//	if (IsEmpty(s) == 1)
//	{
//		printf("栈空");
//		return NULL;
//	}
//	SNode* p = s->next;
//	s->next = p->next;
//	BTNode* k = p->data;
//	free(p);
//	p = NULL;
//	return k;
//}
//
////获得栈顶元素
//BTNode* Get(LinkStack s)
//{
//	if (IsEmpty(s) == 1)
//	{
//		printf("栈空");
//		return NULL;
//	}
//	BTNode* k = s->next->data;
//	return k;
//}
//
////-------------------------------------------
////二叉树
////初始化二叉树
//LinkBTree InitBTree(char r)
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
//	return root;
//}
//
////查找二叉树节点
//BTNode* Find(LinkBTree root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	if (root->lch != NULL)
//	{
//		BTNode* res = Find(root->lch, px);
//		if (res != NULL)
//		{
//			return res;
//		}
//	}
//	if (root->rch != NULL)
//	{
//		BTNode* res = Find(root->rch, px);
//		if (res != NULL)
//		{
//			return res;
//		}
//	}
//	return NULL;
//}
//
////插入元素
//void Insert(LinkBTree root, char x, char px, int flag)
//{
//	BTNode* k = (BTNode*)malloc(sizeof(BTNode));
//	if (k == NULL)
//	{
//		printf("新节点创建失败");
//		return NULL;
//	}
//	k->data = x;
//	k->lch = NULL;
//	k->rch = NULL;
//	BTNode* p = Find(root, px);
//	if (flag == 0)
//	{
//		p->lch = k;
//	}
//	else
//	{
//		p->rch = k;
//	}
//}
////----------------------------------------------
//void Visit(BTNode* k)
//{
//	printf("%c ",k->data);
//}
//
////遍历
////先序遍历
////先从根节点开始遍历 引入一个指针p指向根节点 只要p非空或者栈非空则说明还有节点没访问
////循环: 如果p非空 要访问以p为根的子树 访问p(输出p的数据) p入栈 然后访问p的左子树
////		如果p为空 说明左子树访问完了 将栈顶元素出栈 然后访问栈顶元素右子树
//void PreOrder(LinkBTree root)
//{
//	if (root == NULL)
//	{
//		printf("空树");
//		return;
//	}
//	LinkStack stack = InitStack();
//	BTNode* p = root;
//	BTNode* f = NULL;
//	while (p != NULL || IsEmpty(stack) == 0)
//	{
//		if (p == NULL)
//		{
//			f = Pop(stack);
//			p = f->rch;
//		}
//		else
//		{
//			Visit(p);
//			Push(stack, p);
//			p = p->lch;
//		}
//	}
//	printf("\n");
//}
//
////中序遍历
////先从根节点开始遍历 引入一个指针p指向根节点 只要p非空或者栈非空则说明还有节点没访问
////循环: 如果p非空 要访问以p为根的子树 将p入栈 然后访问p的左子树
////		如果p为空 说明左子树访问完了 将栈顶元素出栈 访问栈顶元素(输出栈顶元素的数据) 然后访问栈顶元素右子树
//void InOrder(LinkBTree root)
//{
//	if (root == NULL)
//	{
//		printf("空树");
//		return;
//	}
//	LinkStack stack = InitStack();
//	BTNode* p = root;
//	BTNode* f = NULL;
//	while (p != NULL || IsEmpty(stack) == 0)
//	{
//		if (p == NULL)
//		{
//			f = Pop(stack);
//			Visit(f);
//			p = f->rch;
//		}
//		else
//		{
//			Push(stack, p);
//			p = p->lch;
//		}
//	}
//	printf("\n");
//}

//后序遍历
//先从根节点开始遍历 引入一个指针p指向根节点 引入一个pre指针指向前一个访问的节点
// 只要p非空或者栈非空则说明还有节点没访问
//循环: 如果p非空 要访问以p为根的子树 将p入栈 然后访问p的左子树
//		如果p为空 栈非空 则说明栈顶的某一子树访问完了 
//				  判断是左子树访问完还是右子树访问完 get栈顶元素k
//				  如果k的存在右孩子且有孩子的值不等于pre 此时右孩子还没访问 则访问右孩子
//				  否则直接将栈顶元素出栈 访问栈顶元素(输出栈顶元素的数据) 令pre=k
void PostOrder(LinkBTree root)
{
	if (root == NULL)
	{
		printf("空树");
		return;
	}
	LinkStack stack = InitStack();
	BTNode* p = root;
	BTNode* k = NULL;
	BTNode* pre = NULL;
	while (p != NULL || IsEmpty(stack) == 0)
	{
		if (p != NULL)
		{
			Push(stack, p);
			p = p->lch;
		}
		else
		{//p为空，栈顶某棵子树访问完了，先get栈顶
			k = Get(stack);
			if (k->rch != NULL && pre != k->rch)
			{//右子树还没访问
				p = k->rch;
			}
			else
			{//右子树不存在或者已经访问完了
				k = Pop(stack);
				Visit(k);
				pre = k;
			}
		}
	}
	printf("\n");
}

//----------------------------------------------
int main()
{
	LinkBTree root = NULL;
	//用于记录当前输入的是左孩子还是右孩子
	int flag;
	int n;
	char r;
	scanf_s("%d", &n);
	getchar();
	scanf_s("%c", &r);
	root = InitBTree(r);
	char x;
	char px;
	for (int i = 1; i < n; i++)
	{
		getchar();
		scanf_s("%c ", &x);
		scanf_s("%c ", &px);
		scanf_s("%d", &flag);
		Insert(root, x, px, flag);
	}
	PreOrder(root);
	InOrder(root);
	PostOrder(root);
	return 0;
}

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