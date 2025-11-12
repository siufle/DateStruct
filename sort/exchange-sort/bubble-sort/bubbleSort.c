//冒泡排序 时间复杂度为O(n^2) 空间复杂度为O(1) 稳定 原地排序

#include<stdio.h>

//n个数字(n<=100) 用a数组存储
int n;
int a[105];

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//冒泡排序
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= n - i; j++)//j + 1 <= n - i + 1
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}