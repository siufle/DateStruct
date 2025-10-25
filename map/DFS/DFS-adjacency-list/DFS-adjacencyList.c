//图的深度遍历 以邻接表存图 
//DFS的时间复杂度为O(m+n) 因为该算法相当于访问了数组的data的链表上的所有数据
#include<stdio.h>
#include<stdlib.h>

//以n个顶点 m条边的无向无权图为例 (n<=100)
int n, m;

//邻接表节点
typedef struct ENode {
	int adj;
	struct ENode* next;
}ENode;

//顶点数组结构体
struct Graph {
	char data;
	ENode* first;
}g[105];

// flag[i]=0表示下标为i的顶点未被访问 flag[i]=1表示下标为i的顶点已被访问
int flag[105];

//找到x在顶点数组中对应的下标
int find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].data == x)
		{
			return i;
		}
	}
}

//以下标为i的顶点开始进行深度遍历
void DFS(int i)
{
	//输出该顶点的数据并将该顶点设为已访问
	printf("%c ", g[i].data);
	flag[i] = 1;
	//找到该点未被访问的邻接点 并以该点为起始点进行DFS
	ENode* e = g[i].first;
	while (e != NULL)
	{
		if (flag[e->adj] == 0)
		{
			DFS(e->adj);
		}
		e = e->next;
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &g[i].data);
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

		ENode* e1 = (ENode*)malloc(sizeof(ENode));
		if (e1 != NULL)
		{
			e1->adj = xi;
			e1->next = g[xi].first;
			g[xi].first = e1;
		}
		
		ENode* e2 = (ENode*)malloc(sizeof(ENode));
		if (e2 != NULL)
		{
			e2->adj = yi;
			e2->next = g[yi].first;
			g[yi].first = e2;
		}
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
