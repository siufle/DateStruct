// 希尔排序是对直接插入排序的优化
// 将所有数字进行分组排序 分为n/d组 每组相邻两个数字下标相差d
// 循环logn次 每一次的d等于上一次的1/2 第一次的d等于n/2
// 最后一次d一定等于1
// 时间复杂度优化为了大约O(n^1.3) 最坏的情况可能会退化至O(n^2)

#include<stdio.h>
#include<stdlib.h>

int n;
int a[105];

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int d = n / 2;
	int k = 0;//记录执行了几趟
	for (; d >= 1; d /= 2)
	{
		k++;
		// 每一组的第一个数都是有序的 因此第一个无序数是d+1
		for (int i = d + 1; i <= n; i++)
		{
			int t = a[i];
			// 将t放入其所在组的有序部分中
			int j = i - d;
			for (; j >= 1; j-=d)
			{
				if (a[j] > t)
				{
					a[j + d] = a[j];
				}
				else break;
			}
			a[j + d] = t;
		}
		printf("第%d趟的排序结果是: ", k);
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}