//通过哈夫曼树实现哈夫曼编码

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//基于数组实现哈夫曼树
//定义哈夫曼树节点
typedef struct HuffmanNode
{
	//权重
	int weight;
	//该节点的父亲节点下标
	int f;
	//该节点的孩子下标
	int lch;
	int rch;
}HuffmanNode;

//找到哈夫曼树中下标0到k权重最小的两个根节点
void Find(HuffmanNode* tree, int k, int* s1, int* s2)
{
	int minn = 0;
	//将第一个根节点暂时当作最小
	for (int i = 0; i <= k; i++)
	{
		if (tree[i].f == -1)
		{
			minn = i;
			break;
		}
	}
	//从minn开始找最小
	for (int i = minn; i <= k; i++)
	{
		if (tree[i].f == -1 && tree[i].weight <= tree[minn].weight)
		{
			minn = i;
		}
	}
	*s1 = minn;

	//找第二小的
	for (int i = 0; i <= k; i++)
	{
		if (i != *s1 && tree[i].f == -1)
		{
			minn = i;
			break;
		}
	}
	for (int i = minn; i <= k; i++)
	{
		if (i != *s1 && tree[i].f == -1 && tree[i].weight <= tree[minn].weight)
		{
			minn = i;
		}
	}
	*s2 = minn;
}

//根据要添加的叶子节点的数量创建哈夫曼树
HuffmanNode* CreateHuffmanTree(int w[], int n)
{
	//哈夫曼树数组的长度 
	int m = 2 * n - 1;
	HuffmanNode* tree = (HuffmanNode*)malloc(sizeof(HuffmanNode) * m);
	if (tree == NULL)
	{
		printf("哈夫曼树创建失败");
		return NULL;
	}
	//将所有要编码的字符当作根节点 将权重附上
	for (int i = 0; i < n; i++)
	{
		tree[i].f = -1;
		tree[i].weight = w[i];
		tree[i].lch = -1;
		tree[i].rch = -1;
	}
	//存储当前树中根节点权重最小的两棵树
	int s1, s2;
	//从下表为n的地方开始创建新的根节点
	for (int i = n; i < m; i++)
	{
		//找到当前树中根节点权重最小的两棵树 
		//从0找到i-1 即新节点的前一个节点
		Find(tree, i - 1, &s1, &s2);
		//更改新根节点信息
		tree[i].f = -1;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
		tree[i].lch = s1;
		tree[i].rch = s2;
		tree[s1].f = i;
		tree[s2].f = i;
	}
	return tree;
}

//创建哈夫曼编码
char** CreateCodes(HuffmanNode* tree, int n)
{
	//用字符指针数组存储下标对应的字符的编码
	char **codes = (char**)malloc(sizeof(char*) * n);
	if (codes == NULL)
	{
		return NULL;
	}
	memset(codes, 0, sizeof(char*) * n);
	//临时保存某个字符的编码
	char* temp = (char*)malloc(sizeof(char) * n);
	if (temp == NULL)
	{
		return NULL;
	}
	int start = 0;
	//记录当前节点和其父亲节点
	int p, pre;
	for (int i = 0; i < n; i++)
	{
		p = i;
		pre = tree[i].f;
		start = n - 1;
		temp[start] = '\0';
		while (pre != -1)
		{
			start--;
			if (p == tree[pre].lch)
			{
				temp[start] = '1';
			}
			else
			{
				temp[start] = '0';
			}
			p = pre;
			pre = tree[pre].f;
		}
		codes[i] = (char*)malloc(sizeof(char) * (n - start));
		for (int j = 0; j < n - start; j++)
		{
			codes[i][j] = temp[j + start];
		}
	}
	return codes;
}

int main()
{
	//对n个字符进行编码 规定n<=100
	int n;
	//存储字符
	char c[105];
	//存储字符对应的权重  w[i]为c[i]的权重
	int w[105];
	scanf_s("%d", &n);
	getchar();
	//输入要进行编码的字符
	for (int i = 0; i < n; i++)
	{
		scanf_s("%c", &c[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	HuffmanNode* tree = CreateHuffmanTree(w,n);
	char** codes = CreateCodes(tree,n);
	for (int i = 0; i < n; i++)
	{
		printf("%c: %s\n", c[i], codes[i]);
	}
}

/*
9
agmteh is
1 1 1 1 2 2 3 3 5
*/