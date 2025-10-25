//图的广度优先遍历 以邻接表存图 借助循环队列实现
//将图的起始顶点下标入队之后循环 出队一个顶点再将其邻接顶点入队
//BFS的时间复杂度为O(m+n)

#include<stdio.h>
#include<stdlib.h>

//定义循环队列
#define MAX 100
typedef struct Queue {
	int data[MAX];
	int f;//队头指针
	int r;//队尾指针
}Queue;

//初始化
void InitQueue(Queue* q)
{
	q->f = 0;
	q->r = 0;
}

//判空
int isEmpty(Queue* q)
{
	if (q->f == q->r)
	{
		return 1;//空
	}
	return 0;//非空
}

//入队
void EnQueue(Queue* q, int i)
{
	if ((q->r + 1) % MAX == q->f)
	{
		printf("队满\n");
		return;
	}
	q->data[q->r] = i;
	q->r = (q->r + 1) % MAX;
}

//出队
int DeQueue(Queue* q)
{
	if (isEmpty(q) == 1)
	{
		printf("队空\n");
		return -1;
	}
	int i = q->data[q->f];
	q->f = (q->f + 1) % MAX;
	return i;
}

//n（<100）个点 m条边的无权无向图
int n, m;
//flag[i]==1  i点入队了
int flag[105];

//定义邻接表节点
typedef struct ENode {
	int adj;
	struct ENode* next;
}ENode;

//顶点数组
struct Graph {
	char data;
	ENode* first;
}g[105];

//找到顶点x的下标
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

//广度优先遍历
void BFS(int i)
{
	//创建队列并初始化
	Queue q;
	InitQueue(&q);

	//将第一个顶点入队
	EnQueue(&q, i);
	flag[i] = 1;

	ENode* e = NULL;
	while (isEmpty(&q) == 0)
	{
		//将j出队并打印
		int j = DeQueue(&q);
		printf("%c ", g[j].data);

		e = g[j].first;
		//将j的未入队的邻接点入队
		while (e != NULL)
		{
			if (flag[e->adj] == 0)
			{
				EnQueue(&q, e->adj);
				flag[e->adj] = 1;
			}
			e = e->next;
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
			e1->adj = yi;
			e1->next = g[xi].first;
			g[xi].first = e1;
		}

		ENode* e2 = (ENode*)malloc(sizeof(ENode));
		if (e2 != NULL)
		{
			e2->adj = xi;
			e2->next = g[yi].first;
			g[yi].first = e2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
		{
			BFS(i);
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