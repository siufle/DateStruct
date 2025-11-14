//选择排序 选择最大或最小的数放到数组的最后或者最前面
//时间复杂度为O(n^2) 就地排序 不稳定

#include<stdio.h>

int n;//数字个数 n<=100
int a[105];//存储数字

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//选择排序
	for (int i = 1; i <= n - 1; i++)
	{
		int min = i;
		for (int j = i; j <= n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}