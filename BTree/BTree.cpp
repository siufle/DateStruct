//B树

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define m 5
#define fl (m+1)/2-1//非根结点的关键字个数下限 ceil(m/2)-1

//B树节点结构
typedef struct BNode {
	int key[m + 1]; //存储数据1到m-1
	struct BNode* ptr[m + 1]; //m+1 从0下标开始存 key[0]~~key[m]
	//key[i]对应的左边孩子是ptr[i-1],对应的右孩子是ptr[i]
	struct BNode* parent; //双亲节点
	int keynum;//记录结点中数据的个数
}BNode, * BTree;

//结果集结构体 存储查找的结果
typedef struct Result {
	BNode* z; //查找的数据应该在的节点
	int i; //查找的数据应该在该节点的key数组的哪个下标
	int tag; //标记是否查找成功 若成功则为1 找不到则为0
}Result;

//查找p节点中第一个大于等于k的数的下标
int SearchK(BNode* p, int k)
{
	int i = 1;
	for (; i <= p->keynum; i++)
	{
		if (p->key[i] >= k) return i;
	}
	return i;
}

//查找数据 若数据存在则查到数据所在位置 若不存在则查到数据应该在的位置
void SearchBTree(BTree t, int k, Result& r)
{
	int i = 1; //记录k在对应节点key中的下标
	BNode* p = t; //指向k所在节点
	BNode* pa = NULL; //指向q的父亲节点
	int f = 0; //标记是否找到
	while (p != NULL && f == 0)
	{
		i = SearchK(p, k);//在结点p中找第一个大于等于k的位置
		if (i <= p->keynum && p->key[i] == k)
		{//找到了k
			f = 1;
		}
		else
		{//没找到k 到i的左孩子里找
			pa = p;
			p = p->ptr[i - 1];
		}
	}
	if (f == 1)
	{//查找成功
		r.tag = 1;
		r.z = p;
		r.i = i;
	}
	else
	{//查找失败
		r.tag = 0;
		r.z = pa;//此时p指向NULL pa才指向k该在的节点
		r.i = i;
	}
}

//创建新的根节点 节点p和ap分别时数据k的左右孩子
void NewRoot(BTree& t, BNode* p, int k, BNode* ap)
{
	t = (BNode*)malloc(sizeof(BNode));
	if (t == NULL)
	{
		printf("新根节点创建失败\n");
		return;
	}
	t->key[1] = k;
	t->keynum = 1;
	t->ptr[0] = p;
	if (p != NULL) p->parent = t;
	t->ptr[1] = ap;
	if (ap != NULL) ap->parent = t;
	t->parent = NULL;
}

//将数据x插入到q节点的key数组的i位置 并将ap插入到ptr数组的i位置
void Insert(BNode*& q, int i, int x, BNode* ap)
{
	//将key数组以及ptr数组i位置以后的数据向后移一位
	for (int j = q->keynum; j >= i; j--)
	{
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->key[i] = x;
	q->ptr[i] = ap;
	if (ap != NULL) ap->parent = q;
	q->keynum++;
}

//在s位置分裂q节点 ap指向新产生的节点
void Split(BNode*& q, int s, BNode*& ap)
{
	ap = (BNode*)malloc(sizeof(BNode));
	if (ap == NULL)
	{
		printf("新节点创建失败\n");
		return;
	}
	ap->ptr[0] = q->ptr[s];
	for (int i = s + 1; i <= m; i++)
	{
		ap->key[i - s] = q->key[i];
		ap->ptr[i - s] = q->ptr[i];
		if (q->ptr[i] != NULL) q->ptr[i]->parent = ap;
	}
	q->keynum = s - 1;
	ap->keynum = m - s;
	ap->parent = q->parent;
}

//将数据k插入到以t为根节点的B树的q节点的key数组的i位置
void InsertKey(BTree& t, int k, BNode*& q, int i)
{
	//判断该B树是否为空
	if (t == NULL)
	{//是空树 即第一次插入 创建一个新的根节点
		NewRoot(t, NULL, k, NULL);
		return;
	}
	//非空树插入
	int s = 0;//分裂位置
	int x = k;//要插入的数据
	BNode* ap = NULL;//插入一个数据 也要多一个孩子
	int finished = 0;//是否继续插入
	int needroot = 0;//是否分裂了根结点
	while (finished == 0 && needroot == 0)
	{
		Insert(q, i, x, ap);//把x插入到key[i] ap插入到ptr[i]
		//判断是否要分裂
		if (q->keynum <= m - 1)
		{//不需要分裂 插入结束
			finished = 1;
		}
		else
		{//需要分裂
			s = (m + 1) / 2;
			//1~~s-1的数据留下 s位置上的数据给父亲 s+1~~m的数据成为一个新节点 并成为s的右孩子
			x = q->key[s];//以便下次循环 插入到q到父亲结点中
			Split(q, s, ap);//结点q一分为2 ap指向因为分裂新创建的结点
			//分裂完之后x成为要向q父亲插入的数据
			if (q->parent != NULL)
			{//循环向上分裂
				q = q->parent;
				i = SearchK(q, x);
			}
			else
			{//q节点就是根节点 需要创建一个新的根节点 存放x
				NewRoot(t, q, x, ap);
				needroot = 1;
			}
		}
	}
}

//打印t为根节点的B树 tab为需要制表符的个数
void PrintfBTree(BTree t, int tab)
{
	if (t == NULL) return;
	BNode* p = t;
	for (int i = 1; i <= tab; i++) printf("\t");
	for (int i = 1; i <= p->keynum; i++) printf("%d ", p->key[i]);
	printf("\n");
	for (int i = 0; i <= p->keynum; i++) PrintfBTree(p->ptr[i], tab + 1);
}

//插入键
void InsertKeyOperation(BTree& t)
{
	int k; //记录要插入的数据
	Result r; //记录查找的结果
	while (true)
	{
		printf("请输入要插入的关键字：\n");
		scanf_s("%d", &k);
		SearchBTree(t, k, r);//在以t为根的b树中找k r是结果
		if (r.tag == 1)printf("该关键字已经存在\n");
		else
		{//k不存在 插入k
			InsertKey(t, k, r.z, r.i);//把k插入到r.z结点的r.i位置。 因为前面没判断空树插入 t可能是NULL
			printf("插入成功,B树如下\n");
			printf("----------------------------------------------\n");
			PrintfBTree(t, 1);
			printf("----------------------------------------------\n");
		}
		printf("是否继续插入,是 y,否 n\n");
		char c;
		getchar();
		scanf_s("%c", &c);
		if (c != 'y')break;
	}
}

//-----------------------------------------删除---------------------------------------

//调整函数和合并函数相互调用 需要提前声明
void Restore(BTree& t, BNode*& p);
void Merge(BNode*& x, BNode*& pa, BNode*& y, BTree& t, int yi);

//删除终端节点p的key数组的第i个数据
void Remove(BNode*& p, int i)
{
	for (int j = i; j < p->keynum; j++)
	{
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--;
}

//找兄弟借关键字
void Borrow(BNode*& p, BNode*& lbro, BNode*& rbro, BNode*& pa, int i)
{
	if (lbro != NULL && lbro->keynum > fl)
	{//左兄弟够借 找左兄弟借 借左兄弟的最右边的数据
		//先将p节点key和ptr的第一个位置空出来
		for (int j = p->keynum; j >= 1; j--) p->key[j + 1] = p->key[j];
		for (int j = p->keynum; j >= 0; j--) p->ptr[j + 1] = p->ptr[j];
		//把父亲的第i个数据给p 把左兄弟key数组最右边的数据给父亲覆盖父亲的第i个数据 
		p->key[1] = pa->key[i];
		pa->key[i] = lbro->key[lbro->keynum];
		//将左兄弟的最后一个孩子给p
		p->ptr[0] = lbro->ptr[lbro->keynum];
		if (p->ptr[0] != NULL) p->ptr[0]->parent = p;
		p->keynum++;
		lbro->keynum--;
	}
	else
	{//左兄弟不够借 右兄弟够借 找右兄弟借 借右兄弟的最左边的数据
		//把父亲的第i+1个数据给p 把右兄弟key数组最左边的数据给父亲覆盖父亲的第i+1个数据 
		p->key[p->keynum + 1] = pa->key[i + 1];
		pa->key[i + 1] = rbro->key[1];
		//将右兄弟的第一个孩子给p
		p->ptr[p->keynum + 1] = rbro->ptr[0];
		if (rbro->ptr[0] != NULL) rbro->ptr[0]->parent = p;
		//将右兄弟的第一个数据和第一个孩子覆盖
		for (int j = 1; j < rbro->keynum; j++) rbro->key[j] = rbro->key[j + 1];
		for (int j = 0; j < rbro->keynum; j++) rbro->ptr[j] = rbro->ptr[j + 1];
		p->keynum++;
		rbro->keynum--;
	}
}

//在根节点为t的B树中和并xy yi为y在其父亲节点pa的下标位置
void Merge(BNode*& x, BNode*& pa, BNode*& y, BTree& t, int yi)
{
	//把父亲节点中第yi个数据给x
	x->key[x->keynum + 1] = pa->key[yi];
	//再单独把y中的第0个孩子给x
	x->ptr[x->keynum + 1] = y->ptr[0];
	if (y->ptr[0] != NULL) y->ptr[0]->parent = x;
	x->keynum++;
	//将y中剩余的数据和孩子全都合并到x中
	for (int j = 1; j <= y->keynum; j++)
	{
		x->keynum++;
		x->key[x->keynum] = y->key[j];
		x->ptr[x->keynum] = y->ptr[j];
		if (y->ptr[j] != NULL) y->ptr[j]->parent = x;
	}
	//释放y的内存
	free(y);
	y = NULL;
	//在pa中删除下标yi位置的数据和孩子
	Remove(pa, yi);
	//判断pa节点是否需要调整
	if (pa->parent == NULL)
	{//pa节点是根节点
		if (pa->keynum < 1)
		{//pa节点数据为空 x成为新的根节点 释放pa的空间
			t = x;
			x->parent = NULL;
			free(pa);
			pa = NULL;
		}
	}
	else
	{//pa不是根节点
		if (pa->keynum < fl)
		{//需要调整
			Restore(t, pa);
		}
	}
}

//对数据量小于最小数据量的非根节点进行调整
void Restore(BTree& t, BNode*& p)
{
	//先找到当前节点是父亲节点的第几个孩子
	BNode* pa = p->parent;
	int i;
	for (i = 0; i <= pa->keynum; i++)
	{
		if (pa->ptr[i] == p) break;
	}
	BNode* lbro = NULL; //左兄弟
	BNode* rbro = NULL; //右兄弟
	if (i > 0) lbro = pa->ptr[i - 1];
	if (i < pa->keynum) rbro = pa->ptr[i + 1];
	//判断是要找兄弟借还是和兄弟合并
	if ((lbro != NULL && lbro->keynum > fl) || (rbro != NULL && rbro->keynum > fl))
	{//至少有一个兄弟够借 找兄弟借
		Borrow(p, lbro, rbro, pa, i);
	}
	else
	{//两个兄弟都不够借 和兄弟合并
		BNode* x = NULL; //要合并的两个节点的左边的节点
		BNode* y = NULL; //要合并的两个节点的右边的节点
		int yi = 0;//y在其父亲结点孩子数组中的下标
		//若左兄弟存在则和左兄弟合并
		if (lbro != NULL)
		{
			x = lbro;
			y = p;
			yi = i;
		}
		else
		{
			x = p;
			y = rbro;
			yi = i + 1;
		}
		Merge(x, pa, y, t, yi);
	}
}

//在t为根节点的B树中删除q节点的key数组的第i个数据
void DeleteBTree(BTree& t, BNode* q, int i)
{
	//先判断q是不是终端节点
	if (q->ptr[0] != NULL)
	{//不是终端节点 将其后继的数据覆盖当前要删除的数据 然后删除后继数据
		//找到后继数据以及其所在节点p
		BNode* p = q->ptr[i];
		while (p->ptr[0] != NULL)
		{
			p = p->ptr[0];
		}
		//用p节点的第一个数据(即要删除节点的后继节点)覆盖q节点的第i个数据
		q->key[i] = p->key[1];
		//更改要删除的节点
		q = p;
		i = 1;
	}
	//删除终端节点
	Remove(q, i);
	//判断是否要调整
	if (q->parent == NULL)
	{//q是根节点
		if (q->keynum < 1)
		{//根节点为空 即B树成为了空树 释放空间
			free(q);
			q = NULL;
			t = NULL;
		}
	}
	else
	{//q不是根节点
		if (q->keynum < fl)
		{//要进行调整
			Restore(t, q);
		}
	}
}

//删除B树中的键
void DeleteKeyOperation(BTree& t)
{
	int k;
	Result r;
	while (true)
	{
		printf("请输入要删除的关键字：\n");
		scanf_s("%d", &k);
		SearchBTree(t, k, r);//在以t为根的b树中找k r是结果
		if (r.tag == 0)printf("该数据不存在，无法删除\n");
		else
		{//查找成功 可以删除
			DeleteBTree(t, r.z, r.i);//2.在结点r.z中删除key[r.i] 
			printf("删除成功,B树如下\n");
			printf("----------------------------------------------\n");
			PrintfBTree(t, 1);
			printf("----------------------------------------------\n");
		}
		printf("是否继续删除,是 y,否 n\n");
		char c;
		getchar();
		scanf_s("%c", &c);
		if (c != 'y')break;
	}
}
 
//-----------------------------------------删除---------------------------------------

int main()
{
	BTree t = NULL;
	InsertKeyOperation(t);
	DeleteKeyOperation(t);
	return 0;
}