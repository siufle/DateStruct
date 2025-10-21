//用邻接表存储图
//用结构体数组存储顶点和该顶点的邻接点

#include<stdio.h>
#include<stdlib.h>

//以带权无向图为例 n为顶点数 m为边数 w为权值
int n, m;

//定义边链表结构体
typedef struct ENode {
	//存储邻接点在数组中的下标
	int adj;
	//权重
	int w;
	//指针域
	struct ENode* next;
}ENode;

//定义邻接表数组结构体 并创建数组
struct Graph {
	//存储顶点
	char data;
	//存储边链表
	ENode* first;
}g[105];

//找到x的下标
int find(char x)
{
	for (int i = 1; i <= 105; i++)
	{
		if (x == g[i].data)
		{
			return i;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &g[i].data);
		g[i].first = NULL;
	}
	char x, y;
	int w;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		scanf_s("%c ", &x);
		scanf_s("%c ", &y);
		scanf_s("%d", &w);
		xi = find(x);
		yi = find(y);
		//采用头插法将邻接点插入到对应的邻接链表中
		//将yi插入到xi的邻接链表中
		ENode* p = (ENode*)malloc(sizeof(ENode));
		if (p != NULL)
		{
			p->adj = yi;
			p->w = w;
			p->next = g[xi].first;
			g[xi].first = p;
		}
		
		//将xi插入到yi的邻接链表中
		ENode* q = (ENode*)malloc(sizeof(ENode));
		if (q != NULL)
		{
			q->adj = xi;
			q->w = w;
			q->next = g[yi].first;
			g[yi].first = q;
		}
	}
	getchar();
	scanf_s("%c", &x);
	xi = find(x);
	int d = 0;
	ENode* p = g[xi].first;
	while (p != NULL)
	{
		d++;
		p = p->next;
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