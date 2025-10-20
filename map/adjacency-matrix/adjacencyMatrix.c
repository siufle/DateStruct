//以邻接矩阵存储图
#include<stdio.h>
#include<stdlib.h>

// 定义无穷大为10001
// e[i][j]的值为无穷大则表示i与j之间无连线
#define inf 10001

// 以带权无向图为例 n个顶点 m条边 权重为w 
// v数组存储顶点 二维数组e通过连接的两个顶点存储线
// n<=100 -10000<=w<=10000
char v[105];
int e[105][105];
int n, m, w;

//找到x的数组v中的下标
int find(char x)
{
	for (int i = 1; i <= 100; i++)
	{
		if (x == v[i])
		{
			return i;
		}
	}
}

int main()
{
	//输入顶点数和边数
	scanf_s("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		//输入顶点
		scanf_s("%c", &v[i]);
		//初始化邻接矩阵
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = inf;
		}
	}
	char x, y;
	//存储x y对应的下标
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		//输入线连接的两个顶点以及权重
		scanf_s("%c ", &x);
		scanf_s("%c ", &y);
		scanf_s("%d", &w);
		xi = find(x);
		yi = find(y);
		//更改邻接矩阵的相关信息
		e[xi][yi] = w;
		e[yi][xi] = w;
	}
	getchar();
	//存储度
	int d = 0;
	scanf_s("%c", &x);
	xi = find(x);
	for (int j = 1; j <= n; j++)
	{
		if (e[xi][j] != inf)
		{
			d++;
		}
	}
	printf("度为%d\n", d);
	return 0;
}

/*
4 5
ABCD
A B 3
A D 6
A C 0
B D 9
D C -4
*/