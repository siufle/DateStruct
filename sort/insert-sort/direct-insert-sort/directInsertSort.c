// 直接插入排序
// 将数组分为两部分 一部分为有序部分 另一部分为无序部分
// 每一次循环取无序部分第一个元素插入到有序部分中
// 时间复杂度为O(n^2)

#include<stdio.h>
#include<stdlib.h>

// 对n个数字进行排序 n<=100
int n;
// 存储数字的数组
int a[105];

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)//从下标1开始存
	{
		scanf_s("%d", &a[i]);
	}
	//直接插入排序
	for (int i = 1; i <= n - 1; i++)//1-i为有序部分 i+1-n为无序部分
	{
		int t = a[i + 1];
		int j = i;
		for (; j >= 1; j--)
		{//从后往前遍历 找到第一个小于等于t的数 则j+1为t应该在的位置
			if (a[j] > t)
			{//将j后移
				a[j + 1] = a[j];
			}
			else break;
		}
		a[j + 1] = t;
	}
	//遍历数组 输出排序后的顺序
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}