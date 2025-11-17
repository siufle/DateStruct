// 归并排序
// 将数组a[n]平均分为两组有序的组 即a[1]--a[n/2]和a[n/2+1]--a[n] 
// 每一次取两组数中的最小值按序放到另一个数组t中 最后将数组t中的数copy到数组a中
// 可以通过递归实现 
// 每一次递归将当前要排序的部分平均分为两份
// 然后对这两部分进行递归调用
// 结束之后可以得到两组有序的部分
// 最后对这两组有序的部分进行两边交替选择的排序
// 时间复杂度为O(nlogn) 计算方法与快速排序类似 不是就地排序 稳定 空间复杂度为O(n)

#include<stdio.h>

//对a数组下标l到r范围内的数进行归并排序
void MergeSort(int a[], int l, int r)
{
	//结束条件 数组长度小于等于1
	if (l >= r)return;
	int mid = (l + r) / 2;
	//对均分的两部分进行递归调用
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	//排序 从有序的两部分第一个数开始
	int i = l;
	int j = mid + 1;
	int t[105];//暂时存储将两部分归并后的数组
	int k = 0;
	while (i <= mid && j <= r)
	{//直到一边超出边界
		if (a[i] <= a[j])
		{
			t[k] = a[i];
			k++;
			i++;
		}
		else
		{
			t[k] = a[j];
			k++;
			j++;
		}
	}
	//某一部分超出边界后另一部分一定没有归并完
	while (i <= mid)
	{
		t[k] = a[i];
		k++;
		i++;
	}
	while (j <= r)
	{
		t[k] = a[j];
		k++;
		j++;
	}
	//此时t数组中0到k-1就是归并了两个有序部分后的结果
	for (int p = 0; p < k; p++)
	{
		a[l + p] = t[p];
	}
}

int main()
{
	int n; //n个数 n<=100
	int a[105]; //存储数组
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	MergeSort(a, 1, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}