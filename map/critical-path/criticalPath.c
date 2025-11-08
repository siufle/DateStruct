// AOE网用顶点表示事件(即事务开始与结束的节点事件) 用边表示事务边权表示事务的耗时
// 关键路径即为可用于计算完成整个工程所需时间的边 完成整个工程所需时间即为从起点到终点的最长路径
// 该路径上的事件与事务都只能按期完成不能有任何延期
// 不在该路径上的事件与事务可以有延期的余地

#include<stdio.h>
#include<stdlib.h>

// 借助两个数组etv和ltv分别表示顶点事件发生的最早时间与最晚时间
// 求出每个事件的最早发生时间ete与最晚发生时间lte 若两个值相等则说明没有延期的余地则为关键路径
// 每一个事件的最早发生时间由其入边邻接点决定 最晚发生时间由其出边邻接点决定
// 该事件的最早发生时间即为其所有入边邻接点的最早发生时间加各自的边权的最大值
// 该事件的最晚发生时间即为其所有出边邻接点的最晚发生时间减各自的边权的最小值
// 可以借由拓扑排序来算出最早发生时间 
// 该点的入边邻接点在拓扑排序中一定在该点之前 一定可以在该点之前确定最早发生时间 并由此确定该点的最早发生时间
// 最晚发生时间同样可以借由拓扑排序的逆序求得
// 该点的出边邻接点在拓扑排序的逆序中一定在该点之前 一定可以在该点之前确定最晚发生时间 并由此确定该点的最晚发生时间

//链栈
typedef struct SNode {
	int data;//顶点下标
	struct SNode* next;
}SNode,*Stack;

//初始化
Stack InitStack()
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	if (s == NULL)
	{
		printf("栈初始化失败\n");
		return NULL;
	}
	s->next = NULL;
	return s;
}

//判空
int IsEmpty(Stack s)
{
	if (s->next == NULL)
	{
		return 0;//栈空
	}
	return 1;//栈不为空
}

//入栈
Stack Push(Stack s, int x)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL)
	{
		printf("新节点创建失败\n");
		return s;
	}
	p->data = x;
	p->next = s->next;
	s->next = p;
	return s;
}

//出栈
Stack Pop(Stack s)
{
	if (IsEmpty(s) == 0)
	{
		printf("栈空\n");
		return s;
	}
	SNode* p = s->next;
	s->next = p->next;
	free(p);
	p = NULL;
	return s;
}

//取栈顶元素
int GetTop(Stack s)
{
	if (IsEmpty(s) == 0)
	{
		printf("栈空\n");
		return -1;//返回一个不存在的下标
	}
	return s->next->data;
}

//图 n(n<=100)个顶点m条边的带权有向图 以邻接表存储
int n, m;
int ind[105];//记录入度
int topo[105];//记录拓扑序列(下标)
int k;//记录当前已排序的顶点个数
int etv[105];//每个顶点事件的最早发生时间
int ltv[105];//每个顶点事件的最晚发生时间

typedef struct ENode {
	int adj;//邻接点的下标
	int w;//权值
	struct ENode* next;
}ENode;

struct Graph {
	char d;//顶点
	ENode* first;
}g[105];

//查找x顶点对应下标
int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].d == x)
		{
			return i;
		}
	}
	return -1;
}

int Max(int x, int y)
{
	return x > y ? x : y;
}

int Min(int x, int y)
{
	return x < y ? x : y;
}

//拓扑排序并计算出每个顶点的etv
void TopoSort()
{
	//初始化栈
	Stack s = InitStack();
	//找到起点(即入度为0的点) 将其下标入栈
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			s = Push(s, i);
		}
	}
	//初始化etv数组
	for (int i = 1; i <= n; i++)
	{
		etv[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		//出栈
		int p = GetTop(s);
		s = Pop(s);
		//加入topo数组中
		topo[++k] = p;
		//更新入度邻接点的ind和etv
		ENode* q = g[p].first;
		while (q != NULL)
		{
			int t = q->adj;
			ind[t]--;
			//更新etv
			int wi = q->w;
			etv[t] = Max(etv[t], etv[p] + wi);
			//判断当前顶点是否可以入栈
			if (ind[t] == 0)
			{
				s = Push(s, t);
			}
			q = q->next;
		}
	}
}

//计算出每个顶点的ltv并得出关键路径
void CriticalPath()
{
	//求出终点
	int end = topo[n];
	//初始化ltv数组
	for (int i = 1; i <= n; i++)
	{
		ltv[i] = etv[end];
	}
	//从终点前一个顶点开始维护
	for (int i = n - 1; i >= 1; i--)
	{
		int p = topo[i];
		ENode* q = g[p].first;
		while (q != NULL)
		{
			int t = q->adj;
			int wi = q->w;
			ltv[p] = Min(ltv[p], ltv[t] - wi);
			q = q->next;
		}
	}

	printf("关键路径是:\n");
	for (int i = 1; i <= n; i++)
	{
		ENode* p = g[i].first;
		//算出每条边的ete和lte 并得出当前边是否是关键路径
		while (p != NULL)
		{
			int t = p->adj;
			int wi = p->w;
			int ete = etv[i];
			int lte = ltv[t] - wi;
			if (ete == lte)
			{//是关键路径
				printf("%c--->%c  %d\n", g[i].d, g[t].d, wi);
			}
			p = p->next;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%c", &g[i].d);
		g[i].first = NULL;
	}
	char x, y;
	int wi;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();
		//x--->y
		scanf_s("%c ", &x);
		scanf_s("%c ", &y);
		scanf_s("%d", &wi);

		xi = Find(x);
		yi = Find(y);

		ENode* e = (ENode*)malloc(sizeof(ENode));
		if (e != NULL)
		{
			e->w = wi;
			e->adj = yi;
			e->next = g[xi].first;
			g[xi].first = e;

			ind[yi]++;
		}
	}
	TopoSort();
	CriticalPath();

	return 0;
}

/*
9 11
ABCDEFGHY
A B 6
A C 4
A D 5
B E 1
C E 1
D F 2
E G 9
E H 7
F H 4
G Y 2
H Y 4
*/