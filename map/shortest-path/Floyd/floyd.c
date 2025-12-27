//floyd算法求最短路径(动态规划)不能出现负回路
//时间复杂度为O(n^3)
//空间复杂度为O(n^2)或O(n^3)
//两点之间的路径有两种可能 直接到达以及经过中转点再到达 而经过中转点可能路径长度会小于直接到达
//经过的中转点越多 路径减小的可能性越大
//n作为中转点时 i到j的最短路径为x 
//因此可以将dp数组声明为三维数组 dp[k][i][j]=x
//但是求以n作为中转点的最短路径时 只需要用到以n-1为中转点的最短路径
//因此可以降维成二维数组dp[i][j]

#include<stdio.h>
#include<stdlib.h>

//假设边权最大值为10000
#define inf 10005

//以邻接矩阵存储图
int a[105][105];
int dp[105][105];
int n;//n个点 n<=100
int m;//m条边

int minn(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf_s("%d %d", &n, &m);
	//初始化邻接矩阵
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = inf;
			if (i == j) a[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf_s("%d %d %d", &u, &v, &w);
		a[u][v] = w;
	}
	//初始化dp数组
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = a[i][j];
		}
	}
	//求最短路径
	for (int k = 1; k <= n; k++)//枚举中转点
	{
		for (int i = 1; i <= n; i++)//枚举起点
		{
			for (int j = 1; j <= n; j++)//枚举终点
			{
				//选择k作为中转点或不作为中转点的较小值作为最短路径
				dp[i][j] = minn(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	//输出结果
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d-->%d:%d\n", i, j, dp[i][j]);
		}
	}
	return 0;
}

/*
5 7
1 3 1
1 5 10
2 5 5
2 4 1
3 2 1
3 5 7
4 5 1
*/