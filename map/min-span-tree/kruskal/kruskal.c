//kruskal算法求得无向有权图的最小生成树
//该算法先将边根据权值从小到大排序
//再由小到大开始选择n-1条边使得n个顶点连通且权值总和最小
//借助并查集实现
//每选择一条边都判断一次是否成环 不成环则选择

#include<stdio.h>
#include<stdlib.h>

//将n个顶点m条边的图存储在边集数组中 n<=100
int n, m;
//定义边集数组
typedef struct Edge {
	//该边连接的两个顶点
	int u, v;
	//权值
	int w;
}Edge;

//创建边集数组
Edge e[5000];

//创建并查集
int f[105];

//将数组下标为start--end边根据权值排序
void Sort(int start, int end)
{//选择排序
	for (int i = start; i < end; i++)
	{
		int min = i;
		for (int j = i + 1; j <= end; j++)
		{
			if (e[j].w <= e[min].w)
			{
				min = j;
			}
		}
		Edge temp = e[min];
		e[min] = e[i];
		e[i] = temp;
	}
}

//查找指定节点所在集合的根节点
int find(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	else
	{
		return f[x] = find(f[x]);
	}
}

//kruskal算法
void kruskal()
{
	//初始化并查集
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;
	}
	//记录权值和
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		//该边连接的两个顶点
		int x = e[i].u;
		int y = e[i].v;
		//这两个顶点的根节点
		int xr = find(x);
		int yr = find(y);
		//判断两个根节点是否相同 即判断两个顶点是否在同一个集合中
		if (xr != yr)
		{//不在同一个集合 合并
			f[xr] = yr;
			sum += e[i].w;
			//输出选择的边
			printf("v%d v%d %d\n", e[i].u, e[i].v, e[i].w);
		}
	}
	printf("最小权值和为%d\n", sum);
}

int main()
{
	scanf_s("%d %d", &n, &m);//默认顶点为1--n
	//输入每一条边
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	//根据边的权值将边集数组下标为1--m的边进行排序
	Sort(1, m);
	//执行kruskal算法获取最小生成树
	kruskal();
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