// 二分查找 即折半查找
// 时间复杂度为O(logn)

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int a[105];
	scanf_s("%d", &n);
	//假设a数组输入时就有序 即不用额外排序
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int k;
	scanf_s("%d", &k);
	int ans = -1;
	int l = 1;
	int r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == k)
		{
			ans = mid;
			break;
		}
		else if (a[mid] > k) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}