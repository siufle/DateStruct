//二叉平衡树 (任意节点的平衡因子不大于1 即左右子树的高度差不大于1)

#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode {
	int data;
	struct AVLNode* lch;
	struct AVLNode* rch;
	//用于记录该节点的高度
	//叶子节点高度为1 非叶子节点高度为两个子树中高度最大的值加1
	int h;
}AVLNode, *AVLTree;

//获取两数之间的最大值
int GetMax(int x, int y) 
{
	return x >= y ? x : y;
}

//获取节点x的高度
int Geth(AVLTree x)
{
	if (x == NULL)
	{
		return 0;
	}
	else
	{
		return x->h;
	}
}

// 右旋
// 有节点失衡x且失衡节点x的左子树高度大于右子树时 对失衡节点x的子树进行右旋
AVLTree RightRotation(AVLTree x)
{
	//1.将失衡节点的左子树赋值给y
	AVLNode* y = x->lch;
	//2.让y的右子树成为x的左子树
	x->lch = y->rch;
	//3.让x成为y的右子树
	y->rch = x;
	//4.更新x和y的高度(因为只有x和y的子树发生了变化 因此只用更新x和y的高度)
	x->h = 1 + GetMax(Geth(x->lch), Geth(x->rch));
	y->h = 1 + GetMax(Geth(y->lch), Geth(y->rch));
	//5.返回y
	return y;
}

// 左旋
// 有节点失衡x且失衡节点x的右子树高度大于左子树时 对失衡节点x的子树进行左旋
AVLTree LeftRotation(AVLTree x)
{
	//1.将失衡节点的右子树赋值给y
	AVLNode* y = x->rch;
	//2.让y的左子树成为x的右子树
	x->rch = y->lch;
	//3.让x成为y的左子树
	y->lch = x;
	//4.更新x和y的高度(因为只有x和y的子树发生了变化 因此只用更新x和y的高度)
	x->h = 1 + GetMax(Geth(x->lch), Geth(x->rch));
	y->h = 1 + GetMax(Geth(y->lch), Geth(y->rch));
	//5.返回y
	return y;
}

int main()
{
	AVLTree root = NULL;
	return 0;
}