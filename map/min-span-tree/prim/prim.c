//通过prim算法获取最小生成树
//将所有点分成两类 第一类是在最小生成树中的 第二类是不在最小生成树中的
//用一个dist数组存储第二类的点到最小生成树的最小距离

#include<stdio.h>
#include<stdlib.h>

//邻接矩阵存储图 n个顶点(n<=100)为0到n-1  m条边 权值为w(w<=10000) 
// 定义无穷大为10005
#define INF 10005
int n, m;
int g[105][105];
//表示顶点是哪类点 0是第二类 1是第一类
int flag[105];
//表示点到最小生成树的最短距离
int dist[105];

//prim算法获取最小生成树 
//该算法时间复杂度为O(n^2)
void Prim()
{
	//从点s开始
	int s = 1;
	//将在树中的顶点的dist改为0
	dist[s] = 0;
	//最小生成树的权值和
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		//记录最小距离和对应的顶点
		int min = INF;
		int t = -1;
		//找到最小距离该选择的点
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				t = j;
			}
		}
		printf("v%d 点通过边权 %d 并入最小生成树\n",t,min);
		sum += min;
		//将选择的点并入第一类
		flag[t] = 1;
		//更新该点邻接点的dist的值
		for (int j = 0; j < n; j++)
		{
			dist[j] = dist[j] < g[t][j] ? dist[j] : g[t][j];
		}
	}
	printf("%d\n", sum);
}

int main()
{
	scanf_s("%d %d", &n, &m);
	//初始化dist和g数组
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		for (int j = 0; j < n; j++)
		{
			g[i][j] = INF;
		}
	}
	//输入边并存图
	int x, y, w;
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &x, &y, &w);
		g[x][y] = w;
		g[y][x] = w;
	}
	Prim();
	return 0;
}

/*
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
*/