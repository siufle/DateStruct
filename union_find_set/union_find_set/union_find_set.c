//并查集
//主要用于以树形结构存储的多个不相交集合的合并与查找操作
//合并指将两个集合中的数据合并到一个集合中
//查找指查找两个数据是否在一个同集合中

#include<stdio.h>
#include<stdlib.h>

//记录每一个数据的父亲节点 规定最多100个数据 如果是根节点则父亲节点就是自己(即f[i]=i)
int f[105];
//记录每一个节点的高度
int h[105];

//获取两数之间较大数
int GetMax(int x, int y)
{
	return x >= y ? x : y;
}

//查找--非递归
//int Find(int x)
//{
//	int p = x;
//	while (f[p] != p)
//	{
//		p = f[p];
//	}
//	return p;
//}

//查找--递归
//int Find(int x)
//{
//	if (f[x] == x)return x;
//	return Find(f[x]);
//}

//查找--递归--路径压缩
//通过将x的直系祖先的父亲节点都变成根节点将树的高度压缩在α(n)以内 即4以内
int Find(int x)
{
	if (f[x] == x)return x;
	else
	{
		int p = Find(f[x]);
		f[x] = p;
		return p;
	}
}


int main()
{
	//n 数据的个数  q 操作的次数
	int n, q;
	scanf_s("%d %d", &n, &q);
	//初始化f数组 将1-n的根节点都设为自己
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		//将每一棵集合树最初的高度设置为1
		h[i] = 1;
	}
	//op 操作码(1表示合并 2表示查找)  x y 要进行操作的数字
	int op, x, y;
	//x y的根节点数据
	int fx, fy;
	for (int i = 0; i < q; i++)
	{
		scanf_s("%d %d %d", &op, &x, &y);
		//找到x和y的根节点
		fx = Find(x);
		fy = Find(y);
		if (op == 1)
		{//合并操作
			//让y的根节点成为x的根节点的根节点(这样可能会导致树的高度为n 达不到提高效率的目的)
			// f[fx] = fy;

			//可以让高度小的树成为高度大的树的子树(这样可以适当降低每一棵集合树的高度)
			/*if (h[fx] >= h[fy])
			{//x根节点高度更高 让y的根节点成为x的根节点的子树
				f[fy] = fx;
				h[fx] = GetMax(h[fx], h[fy] + 1);
			}
			else
			{
				f[fx] = fy;
				h[fy] = GetMax(h[fy], h[fx] + 1);
			}*/

			f[fx] = fy;
		}
		else
		{//查找操作
			if (fx == fy) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}