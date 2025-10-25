//图的广度优先遍历 以邻接矩阵存图 借助循环队列实现
//将图的起始顶点下标入队之后循环 出队一个顶点再将其邻接顶点入队
//BFS的时间复杂度为O(n^2) 相当于访问邻接矩阵中所有数据

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
//顶点数组
char v[105];
//邻接矩阵
int g[105][105];


//找到顶点x的下标
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

//广度优先遍历
void BFS(int i)
{
	//创建队列并初始化
	Queue q;
	InitQueue(&q);

	//将第一个顶点入队
	EnQueue(&q, i);
	flag[i] = 1;

	while (isEmpty(&q) == 0)
	{
		//将x出队并打印
		int x = DeQueue(&q);
		printf("%c ", v[x]);

		//将x的未入队的邻接点入队
		for (int j = 1; j <= n; j++)
		{
			if (g[x][j] == 1 && flag[j] == 0)
			{
				EnQueue(&q, j);
				flag[j] = 1;
			}
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
9 15
ABCDEFGHI
A B
A F
B C
B I
B G
G F
G D
G H
F E
C I
C D
I D
D H
D E
E H
*/