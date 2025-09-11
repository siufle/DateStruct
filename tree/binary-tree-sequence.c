//二叉树的顺序表示法

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 100
//
//char data[MAX];
////表示插入的节点是左孩子还是右孩子
////0表示左孩子  1表示右孩子
//int flag;
//
//void InitRoot(char r)
//{
//	data[1] = r;
//}
//
//int Find(char px)
//{
//	for (int i = 1; i < MAX; i++)
//	{
//		if (data[i] == px)
//		{
//			return i;
//		}
//	}
//	return 0;
//}
//
//void Insert(char x, char px)
//{
//	int parent = Find(px);
//	if (flag == 0)//左孩子
//	{
//		data[parent * 2] = x;
//	}
//	else
//	{
//		data[parent * 2 + 1] = x;
//	}
//}
//
//int main()
//{
//	//将数组所有元素设为空字符
//	for (int i = 0; i < MAX; i++)
//	{
//		data[i] = " ";
//	}
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	InitRoot(r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c ", &px);
//		scanf_s("%d", &flag);
//		Insert(x, px);
//	}
//	getchar();
//	scanf_s("%c", &x);
//	int index = Find(x);
//	if (index == 1)
//	{
//		printf("%c是根节点\n", x);
//	}
//	else
//	{
//		printf("%c的双亲节点是%c\n", x, data[index / 2]);
//	}
//	printf("%c的左孩子是%c\n", x, data[index * 2]);
//	printf("%c的右孩子是%c\n", x, data[index * 2 + 1]);
//}

/*
7
a
b a 0
c a 1
d b 0
e b 1
f e 0
g e 1

*/