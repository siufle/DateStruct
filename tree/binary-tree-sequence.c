//��������˳���ʾ��

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 100
//
//char data[MAX];
////��ʾ����Ľڵ������ӻ����Һ���
////0��ʾ����  1��ʾ�Һ���
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
//	if (flag == 0)//����
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
//	//����������Ԫ����Ϊ���ַ�
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
//		printf("%c�Ǹ��ڵ�\n", x);
//	}
//	else
//	{
//		printf("%c��˫�׽ڵ���%c\n", x, data[index / 2]);
//	}
//	printf("%c��������%c\n", x, data[index * 2]);
//	printf("%c���Һ�����%c\n", x, data[index * 2 + 1]);
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