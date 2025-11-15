// 堆排序对选择排序的优化 在选择时由在普通数组里选择改为在堆数组里选择
// 堆是特殊的完全二叉树 有一定顺序
// 父节点大于子树的称为大顶堆 父节点小于子树的称为小顶堆
// 因为堆是完全二叉树 因此可以直接用数组存储
// 堆排序则为每一次选择大顶堆的根节点将其与数组的最后一个数据进行交换 再将大顶堆重新向下调整
// 向下调整即为从根节点开始 与两子节点进行比较 和较大的子节点交换数据
// 堆的建立分为两种 
// 一种为一边读取节点一边使用向上调整进行调整 
// 另一种为读取完所有节点后从最小的字数开始进行向下调整
// 堆排序时间复杂度为O(nlogn) 就地排序 不稳定
// 构造堆数组的时间复杂度为O(nlogn) 无论是通过向上调整还是向下调整都一样
// 进行排序的部分时间复杂度也为O(nlogn) 进行n次循环 每一次循环向下调整的次数为logn
// 因此该算法的总体时间复杂度为O(nlogn)

#include<stdio.h>

//交换两个数据的值
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//向上调整 调整新读取的i数据以及父辈节点
void UpAdjust(int a[], int i)
{
	//当前调整的节点
	int now = i;
	//当前调整的节点的父亲节点
	int next = i / 2;
	while (now > 1)
	{//调整到该节点变为根节点或者该节点不大于父亲节点为止
		if (a[next] < a[now])
		{
			Swap(&a[now], &a[next]);
			now = next;
			next = now / 2;
		}
		else break;
	}
}

// 向下调整 调整根节点为i的树 树中有n个数据
void DownAdjust(int a[], int i, int n)
{
	//当前要调整的节点
	int now = i;
	//下一个要调整的节点 即为当前节点的子节点
	int next = i * 2;
	while (next <= n)
	{
		if (next + 1 <= n && a[next + 1] > a[next]) next++;
		if (a[next] > a[now])
		{
			Swap(&a[next], &a[now]);
			now = next;
			next = 2 * now;
		}
		else break;
	}
}

int main()
{
	int n;
	int a[105];
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
		//UpAdjust(a, i);
	}
	for (int i = n / 2; i >= 1; i--)
	{//1到n/2之间的节点才有子节点 以这些节点为根节点进行排序即可
		DownAdjust(a, i, n);
	}
	int r = n;//乱序区的右边界
	for (int i = 1; i <= n - 1; i++)//枚举趟数
	{//第i趟找到下标为n-i+1的数 即将大顶堆的根节点交换到n-i+1
		Swap(&a[1], &a[r]);
		r--;
		//交换过来的数可能会导致原来的大顶堆变得无序 再进行向下调整
		DownAdjust(a, 1, r);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}