// 拓扑排序
// 基于DAG图即有向无环图 
// 若A--->B 则A是B的前置活动 必须先执行完A再执行B
// 拓扑排序即将有向无环图按照先后顺序排序
// 借助栈实现 每一次循环将入度为0的节点进栈 然后出栈 更新出栈节点的邻接点的出度 再将入度变成0的节点入栈

#include<stdio.h>
#include<stdlib.h>

// 栈
// 栈中存储节点的下标
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode, *Stack;

// 初始化栈
Stack InitStack()
{
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	if (s == NULL)
	{
		printf("初始化失败\n");
		return NULL;
	}
	s->next = NULL;
	return s;
}

// 入栈
Stack Push(Stack s, int x)
{
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
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

// 判空
int IsEmpty(Stack s)
{
	if (s->next == NULL)
	{
		return 0;//栈空
	}
	return 1;//非空
}

// 出栈
Stack Pop(Stack s)
{
	if (IsEmpty(s) == 0)
	{
		printf("栈空\n");
		return NULL;
	}
	StackNode* p = s->next;
	s->next = p->next;
	free(p);
	p = NULL;
	return s;
}

// 获取栈顶元素
int GetTop(Stack s)
{
	if (IsEmpty(s) == 0)
	{
		printf("栈空\n");
		return -1;//若栈为空则返回-1 因为数组下标一定大于-1
	}
	return s->next->data;
}

// 图
// n个顶点 n<=100 m条有向边 存储在邻接表中
int n, m;

//邻接表节点
typedef struct ENode {
	int adj;//指向顶点的下标
	struct ENode* next;
}ENode;

//顶点数组
struct Graph {
	char d;//顶点数据
	ENode* first;
}g[105];

//存储入度
int ind[105];

//存储拓扑序列
int topo[105];

//当前拓扑数组大小
int k = 0;

//寻找顶点对应下标
int Find(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].d == x)
		{
			return i;
		}
	}
	return -1;//没找到
}

//拓扑排序 若成功则返回1 若遇到环则失败返回0
int TopoSort()
{
	//初始化栈
	Stack s = InitStack();
	//将最初入度为0的顶点入栈
	for (int i = 1; i <= n ; i++)
	{
		if (ind[i] == 0)
		{
			s = Push(s, i);
		}
	}
	//循环将图进行拓扑排序
	for (int i = 1; i <= n; i++)
	{
		//判断栈是否为空
		if (IsEmpty(s) == 0)
		{//栈空 遇到了环 直接结束
			return 0;
		}
		//获取栈顶元素
		int temp = GetTop(s);
		//出栈栈顶
		s = Pop(s);
		//将栈顶元素放入排序数组中 从1开始存
		topo[++k] = temp;
		//更新邻接点的入度
		ENode* p = g[temp].first;
		while (p != NULL)
		{
			int x = p->adj;
			p = p->next;
			ind[x]--;
			//判断该顶点入度更新之后是否为0
			if (ind[x] == 0)
			{//将该点入栈
				s = Push(s, x);
			}
		}
	}
	return 1;
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
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		getchar();

		//x-->y
		scanf_s("%c ", &x);
		scanf_s("%c", &y);

		xi = Find(x);
		yi = Find(y);

		ENode* e = (ENode*)malloc(sizeof(ENode));
		if (e != NULL)
		{
			e->adj = yi;
			e->next = g[xi].first;
			g[xi].first = e;

			ind[yi]++;//给yi入度+1
		}
	}
	int flag = TopoSort();
	if (flag == 0)
	{
		printf("有环\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%c ", g[topo[i]].d);
		}
		printf("\n");
	}
	return 0;
}

/*
6 8
ABCDEF
A B
A C
A D
C B
C E
F D
F E
D E
*/