//Dijkstra算法求最短路径(单源 起点到其他所有点的最小距离) 前提是边权不为负且起点可以到达任意点
//将所有点分为已算出最短路径和未算出 定义一个flag数组标记两类点
//定义一个dist数组记录该点到起点的最短路径

#include<stdio.h> 

//n个顶点(n<=100) m条边 带权无向图 点默认为0--n-1
int n, m;
#define INF 10001
int g[105][105];//以邻接矩阵存图
int flag[105];//1为已算出 0为未算出
int dist[105];
int pre[105];//记录起点到该点的该点的前一个节点 若没有前一个节点则记为-1

//以s为起点进行Dijkstra算法 该算法时间复杂度为O(n^2)
void Dijkstra(int s)
{
	flag[s] = 1;
	dist[s] = 0;
	//更新起点的邻接点的dist值
	for (int i = 0; i < n; i++)
	{
		if (g[s][i] != INF)
		{
			dist[i] = g[s][i];
			pre[i] = s;
		}
	}
	//循环n-1次将所有节点到起点的最短距离算出
	for (int i = 1; i < n; i++)
	{
		//找到dist数组中值最小的点
		int min = INF;//当前数组内的最小距离
		int k = -1;//最小距离的点
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		//将该点设置为距离值不会再改变的点
		//因为没有任何一个点可以作为该点到起点的中转点(要作为中转点必须满足中转点到起点的距离小于该点到起点的距离)
		flag[k] = 1;
		//更新k的邻接点的dist的值
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && g[k][j] + dist[k] < dist[j])
			{
				dist[j] = g[k][j] + dist[k];
				//将k点作为该点的前置节点 更新pre数组
				pre[j] = k;
			}
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	//初始化dist数组
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		pre[i] = -1;
		//初始化邻接矩阵
		for (int j = 0; j < n; j++)
		{
			g[i][j] = INF;
		}
	}
	int x, y;
	int w;
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &x, &y, &w);
		g[x][y] = w;
		g[y][x] = w;
	}
	int s;
	scanf_s("%d", &s);
	Dijkstra(s);
	//输出结果
	for (int i = 0; i < n; i++)
	{
		printf("v%d 到 v%d 的最短路径为 %d, 逆向路径为: %d ", s, i, dist[i], i);
		int j = pre[i];
		while (j != -1)
		{
			printf("%d ", j);
			j = pre[j];
		}
		printf("\n");
	}
	return 0;
}

/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/