//图的深度遍历 以邻接矩阵存图
#include<stdio.h>
#include<stdlib.h>

//以n个顶点 m条边的无向无权图为例 (n<=100)
int n, m;
//顶点数组
char v[105];
//邻接矩阵
int g[105][105];
//标志数组 
// flag[i]=0表示下标为i的顶点未被访问 flag[i]=1表示下标为i的顶点已被访问
int flag[105];

//找到x在顶点数组中对应的下标
int find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == x)
		{
			return i;
		}
	}
}

//以下标为i的顶点开始进行深度遍历
void DFS(int i)
{
	//输出该顶点的数据并将该顶点设为已访问
	printf("%c ", v[i]);
	flag[i] = 1;
	//找到该点未被访问的邻接点 并以该点为起始点进行DFS
	for (int j = 1; j <= n; j++)
	{
		if (g[i][j] == 1 && flag[j] == 0)
		{
			DFS(j);
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &v[i]);
	}
	char x, y;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		scanf_s("%c ", &x);
		scanf_s("%c", &y);

		xi = find(x);
		yi = find(y);

		g[xi][yi] = 1;
		g[yi][xi] = 1;
	}

	//遍历每一个连通区块
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
		{
			DFS(i);
		}
	}
	return 0;
}

/*
9 16
ABCDEFGHI
A B
A F
B G
G F
B C
B I
C I
C D
I D
D G
D H
D E
G H
H E
E F
F G
*/
