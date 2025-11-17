// 计数排序 在输入时将输入的数字a[i]的个数在cnt数组中增加 即cnt[a[i]]++
// 引入一个变量max记录输入的最大值 可以减小cnt数组遍历次数 由遍历0到10005减小为0到max
// 引入一个数组sum记录数字i的前缀和 即sum[i] = sum[i-1]+cnt[i]
// 同时sum[i]的值也是最后一个i所在的位置 因此可以借用该数组保证该排序的稳定性
// 时间复杂度为O(max+n) 类似于图的邻接表 非就地排序 稳定 较浪费空间

#include<stdio.h>

int n; //n<=100
int a[105]; //0<=a[i]<=10000
int cnt[10005];
int max = 0;
int sum[10005];
int t[105]; //存储排好后的数据的顺序

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] > max) max = a[i];
		cnt[a[i]]++;
	}
	sum[0] = cnt[0];
	for (int i = 1; i <= max; i++)
	{
		sum[i] = sum[i - 1] + cnt[i];
	}
	for (int i = n; i >= 1; i--)
	{
		int k = sum[a[i]]; //a[i]应该在的位置
		t[k] = a[i];
		sum[a[i]]--; //下一个与a[i]相等的值应该在的位置
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", t[i]);
	}
	return 0;
}