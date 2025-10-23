//多重邻接表 和十字链表类似 不过适用于无向图

#include<stdio.h>
#include<stdlib.h>

//无权无向向图为例。n个点 m条边  n<100  
int n, m;

//定义链表节点
typedef struct ENode {
	//x y存储节点对应的下标
	int x;
	int y;
	//xnext ynext分别存储以x y为其中一个顶点的下一条边的节点地址
	struct ENode* xnext;
	struct ENode* ynext;
}ENode;

//顶点数组结构体
struct Graph {
	char data;
	ENode* first;
}g[105];

int find(char p)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].data == p)
		{
			return i;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	//输入顶点并初始化
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &g[i].data);
		g[i].first = NULL;
	}
	char p, q;
	int pi, qi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		scanf_s("%c ", &p);
		scanf_s("%c", &q);

		pi = find(p);
		qi = find(q);

		ENode* e = (ENode*)malloc(sizeof(ENode));
		if (e != NULL)
		{
			e->x = p;
			e->xnext = g[pi].first;
			g[pi].first = e;

			e->y = q;
			e->ynext = g[qi].first;
			g[qi].first = e;
		}
	}
	getchar();
	char u;
	int ui;
	scanf_s("%c", &u);
	ui = find(u);
	int d = 0;
	ENode* t = g[ui].first;
	while (t != NULL)
	{
		d++;
		if (t->x == u)
		{
			t = t->xnext;
		}
		else
		{
			t = t->ynext;
		}
	}
	printf("度为%d\n", d);
	return 0;
}

/*
4 5
ABCD
B A
B D
D A
A C
C D
*/