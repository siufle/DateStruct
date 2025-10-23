//十字链表只能用于存储有向图 可以避免邻接表功能单一或者浪费空间的问题

#include<stdio.h>
#include<stdlib.h>

//带权有向图为例。n个点 m条边  n<100
int n, m;

//创建十字链表节点
typedef struct ENode {
	//存储弧尾顶点对应的下标
	int tail;
	//下一个相同弧尾的边地址
	struct ENode* tailnext;
	//存储弧头顶点对应的下标
	int head;
	//下一个相同弧头的边地址
	struct ENode* headnext;
	//权值
	int w;
}ENode;

//顶点数组结构体
struct Graph {
	//存储顶点
	char data;
	//以该节点入边链表
	ENode* firstin;
	//以该节点出边链表
	ENode* firstout;
}g[105];

//查找x的下标
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

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	//输入顶点并初始化
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &g[i].data);
		g[i].firstin = NULL;
		g[i].firstout = NULL;
	}
	char x, y;
	int w;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		//x为弧尾 y为弧头
		scanf_s("%c ", &x);
		scanf_s("%c ", &y);
		scanf_s("%d", &w);
		//获取x y对应的下标
		xi = find(x);
		yi = find(y);

		//创建十字链表新节点
		ENode* e = (ENode*)malloc(sizeof(ENode));
		if (e != NULL)
		{
			e->w = w;

			e->tail = xi;
			e->tailnext = g[xi].firstout;
			g[xi].firstout = e;

			e->head = yi;
			e->headnext = g[yi].firstin;
			g[yi].firstin = e;
		}
	}
	getchar();
	scanf_s("%c", &x);
	xi = find(x);
	//od记录出度 id记录入度
	int od = 0;
	int id = 0;
	ENode* p = NULL;
	//求入度
	p = g[xi].firstin;
	while (p != NULL)
	{
		id++;
		p = p->headnext;
	}
	printf("入度为%d\n",id);
	//求出度
	p = g[xi].firstout;
	while (p != NULL)
	{
		od++;
		p = p->tailnext;
	}
	printf("出度为%d\n", od);
	return 0;
}

/*
4 6
ABCD
B A 3
A B 4
B D 1
D A -2
A C 1
C D -3
*/