//二叉平衡树 (任意节点的平衡因子不大于1 即左右子树的高度差不大于1)

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct AVLNode {
//	int data;
//	struct AVLNode* lch;
//	struct AVLNode* rch;
//	//用于记录该节点的高度
//	//叶子节点高度为1 非叶子节点高度为两个子树中高度最大的值加1
//	int h;
//}AVLNode, *AVLTree;
//
////获取两数之间的最大值
//int GetMax(int x, int y) 
//{
//	return x >= y ? x : y;
//}
//
////获取节点x的高度
//int Geth(AVLTree x)
//{
//	if (x == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return x->h;
//	}
//}
//
////插入节点所引起的节点失衡只有四种情况
////1.LL---在失衡节点x的左子树的左孩子加入新节点导致失衡 对失衡节点x的子树进行右旋
////2.RR---在失衡节点x的右子树的右孩子加入新节点导致失衡 对失衡节点x的子树进行左旋
////3.LR---在失衡节点x的左子树的右孩子加入新节点导致失衡 对失衡节点x的左子树的子树先进行左旋 再对失衡节点x的子树进行右旋
////4.RL---在失衡节点x的右子树的左孩子加入新节点导致失衡 对失衡节点x的右子树的子树先进行右旋 再对失衡节点x的子树进行左旋
//
////1.LL---在失衡节点x的左子树的左孩子加入新节点导致失衡 对失衡节点x的子树进行右旋
//AVLTree LL_Rotation(AVLTree x)
//{
//	//1.将失衡节点的左子树赋值给y
//	AVLNode* y = x->lch;
//	//2.让y的右子树成为x的左子树
//	x->lch = y->rch;
//	//3.让x成为y的右子树
//	y->rch = x;
//	//4.更新x和y的高度(因为只有x和y的子树发生了变化 因此只用更新x和y的高度)
//	x->h = 1 + GetMax(Geth(x->lch), Geth(x->rch));
//	y->h = 1 + GetMax(Geth(y->lch), Geth(y->rch));
//	//5.返回y
//	return y;
//}
//
////2.RR---在失衡节点x的右子树的右孩子加入新节点导致失衡 对失衡节点x的子树进行左旋
//AVLTree RR_Rotation(AVLTree x)
//{
//	//1.将失衡节点的右子树赋值给y
//	AVLNode* y = x->rch;
//	//2.让y的左子树成为x的右子树
//	x->rch = y->lch;
//	//3.让x成为y的左子树
//	y->lch = x;
//	//4.更新x和y的高度(因为只有x和y的子树发生了变化 因此只用更新x和y的高度)
//	x->h = 1 + GetMax(Geth(x->lch), Geth(x->rch));
//	y->h = 1 + GetMax(Geth(y->lch), Geth(y->rch));
//	//5.返回y
//	return y;
//}
//
////3.LR---在失衡节点x的左子树的右孩子加入新节点导致失衡 对失衡节点x的左子树的子树先进行左旋 再对失衡节点x的子树进行右旋
//AVLTree LR_Rotation(AVLTree x)
//{
//	//对失衡节点x的左子树的子树先进行左旋
//	x->lch = RR_Rotation(x->lch);
//	//再对失衡节点x的子树进行右旋
//	x = LL_Rotation(x);
//	return x;
//}
//
////4.RL---在失衡节点x的右子树的左孩子加入新节点导致失衡 对失衡节点x的右子树的子树先进行右旋 再对失衡节点x的子树进行左旋
//AVLTree RL_Rotation(AVLTree x)
//{
//	//对失衡节点x的右子树的子树先进行右旋
//	x->rch = LL_Rotation(x->rch);
//	//再对失衡节点x的子树进行左旋
//	x = RR_Rotation(x);
//	return x;
//}
//
////创建节点
//AVLNode* CreateNode(int x)
//{
//	AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
//	if (s == NULL)
//	{
//		printf("新节点创建失败");
//		return NULL;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	s->h = 1;
//	return s;
//}
//
////插入节点
//AVLTree Insert(AVLTree root, int x)
//{
//	if (root == NULL)
//	{
//		root = CreateNode(x);
//		return root;
//	}
//	if (x < root->data)
//	{
//		root->lch = Insert(root->lch, x);
//		//在左子树插入节点可能会导致有节点失衡
//		if (Geth(root->lch) - Geth(root->rch) > 1)
//		{//root失衡
//			AVLNode* left = root->lch;
//			//如果插入的值小于左子树的值则为LL 否则为LR
//			if (x < left->data)
//			{//LL
//				root = LL_Rotation(root);
//			}
//			else 
//			{//LR
//				root = LR_Rotation(root);
//			}
//		}
//	}
//	else
//	{
//		root->rch = Insert(root->rch, x);
//		//在右子树插入节点可能会导致有节点失衡
//		if (Geth(root->rch) - Geth(root->lch) > 1)
//		{//root失衡
//			AVLNode* right = root->rch;
//			//如果插入的值小于左子树的值则为RL 否则为RR
//			if (x < right->data)
//			{//RL
//				root = RL_Rotation(root);
//			}
//			else
//			{//RR
//				root = RR_Rotation(root);
//			}
//		}
//	}
//	root->h = 1 + GetMax(Geth(root->lch), Geth(root->rch));
//	return root;
//}
//
////删除节点
////删除节点导致的失衡可以看作在另一子树上插入一个节点导致的失衡
////在左子树上删除节点导致的失衡可以看作在右子树上插入节点导致的失衡
//// 根据失衡节点x的右子树r的左右子树高度大小判断是RR还是RL
//// 如果r->rch->h >= r->lch->h  为RR
//// 如果r->rch->h < r->lch->h  为RL
////在右子树上删除节点导致的失衡可以看作在左子树上插入节点导致的失衡
//// 根据失衡节点x的左子树l的左右子树高度大小判断是LL还是LR
//// 如果l->lch->h >= l->rch->h  为LL
//// 如果l->lch->h < l->rch->h  为LR
//AVLTree DeleteAVLTree(AVLTree root, int x)
//{
//	if (root->data == x)
//	{
//		//判断要删除的节点度为几
//		if (root->lch != NULL && root->rch != NULL)
//		{
//			//度为2
//			//找到该节点在中序遍历中的前驱
//			AVLNode* p = root->lch;
//			while (p->rch != NULL)
//			{
//				p = p->rch;
//			}
//			root->data = p->data;
//			//删除p节点
//			root->lch = DeleteAVLTree(root->lch, p->data);
//			//判断root节点是否失衡
//			if (Geth(root->rch) - Geth(root->lch) > 1)
//			{
//				//失衡 RR或RL
//				AVLNode* r = root->rch;
//				if (Geth(r->rch) >= Geth(r->lch))
//				{//RR
//					root = RR_Rotation(root);
//				}
//				else
//				{//RL
//					root = RL_Rotation(root);
//				}
//			}
//		}
//		else
//		{//度为1或0
//			AVLNode* p = root;
//			if (root->lch != NULL)
//			{
//				root = root->lch;
//
//			}
//			else
//			{
//				root = root->rch;
//			}
//			free(p);
//			p = NULL;
//		}
//	}
//	else if (x < root->data)
//	{
//		root->lch = DeleteAVLTree(root->lch, x);
//		//判断root节点是否失衡
//		if (Geth(root->rch) - Geth(root->lch) > 1)
//		{
//			//失衡 RR或RL
//			AVLNode* r = root->rch;
//			if (Geth(r->rch) >= Geth(r->lch))
//			{//RR
//				root = RR_Rotation(root);
//			}
//			else
//			{//RL
//				root = RL_Rotation(root);
//			}
//		}
//	}
//	else
//	{
//		root->rch = DeleteAVLTree(root->rch, x);
//		//判断root节点是否失衡
//		if (Geth(root->lch) - Geth(root->rch) > 1)
//		{
//			//失衡 LL或LR
//			AVLNode* l = root->lch;
//			if (Geth(l->lch) >= Geth(l->rch))
//			{//LL
//				root = LL_Rotation(root);
//			}
//			else
//			{//LR
//				root = LR_Rotation(root);
//			}
//		}
//	}
//	if (root != NULL)
//	{
//		root->h = 1 + GetMax(Geth(root->lch), Geth(root->rch));
//	}
//	return root;
//}
//
////中序遍历
//void InOrder(AVLTree root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	InOrder(root->lch);
//	//平衡因子
//	int p = Geth(root->lch) - Geth(root->rch);
//	printf("%d  %d\n", root->data, p);
//	InOrder(root->rch);
//}
//
//int main()
//{
//	AVLTree root = NULL;
//	int n;
//	int x;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &x);
//		root = Insert(root, x);
//	}
//	InOrder(root);
//	printf("------------------------\n");
//	while (root != NULL)
//	{
//		scanf_s("%d", &x);
//		root = DeleteAVLTree(root, x);
//		InOrder(root);
//		printf("------------------------\n");
//	}
//	return 0;
//}
/*
9
8 3 10 1 6 14 4 7 13
*/