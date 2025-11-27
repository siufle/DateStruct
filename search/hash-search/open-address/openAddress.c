//开放定址法解决哈希冲突
#include<stdio.h>
#include<stdlib.h>

#define nul -1
#define size 15

//表长为m，n个数据构造散列表，保证n<=m 且表中数据均为非负整数
//Hash(key)=key%13
//处理冲突的方法：线性探测法

typedef struct
{
	int* data; //哈希数组
	int m;     //表长
} HashTable;

//初始化哈希表
HashTable* Init()
{
	HashTable* h = (HashTable*)malloc(sizeof(HashTable));
	if (h == NULL)
	{
		printf("初始化失败\n");
		return NULL;
	}
	h->m = size;
	h->data = (int*)malloc(sizeof(int) * h->m);
	if (h->data == NULL)
	{
		printf("初始化失败\n");
		return NULL;
	}
	for (int i = 0; i < h->m; i++)
	{
		h->data[i] = nul;
	}
	return h;
}

//计算hash值
int Hash(int key)
{
	return key % 13;
}

//找到数据k对应的下标
int Find_i(HashTable* h, int k)
{
	int i = Hash(k);
	if (h->data[k] != nul)//位置冲突
	{
		int d = 0;
		int newi = (i + d) % h->m;
		while (h->data[newi] != nul)
		{
			d++;
			newi = (i + d) % h->m;
		}
		return newi;
	}
	else return i;
}

//插入数据
void Insert(HashTable* h, int k)
{
	int i = Find_i(h, k);
	h->data[i] = k;
}

//查找k所在位置
int Find_k(HashTable* h, int k)
{
	int i = Hash(k);
	if (h->data[i] == nul) return -1;//不存在
	else
	{
		int d = 0;
		int newi = (i + d) % h->m;
		do
		{
			if (h->data[newi] == k) return newi;
			else
			{
				d++;
				newi = (i + d) % h->m;
			}
		} while (h->data[newi] != nul && newi != i);
		return -1;
	}
}

int main()
{
	HashTable* h = Init();
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf_s("%d", &k);
		Insert(h, k);
	}
	//输出哈希表
	for (int i = 0; i < h->m; i++)
	{
		printf("%d %d\n", i, h->data[i]);
	}
	//查找k所在位置 若不存在则返回-1
	int k;
	scanf_s("%d", &k);
	int index = Find_k(h, k);
	if (index == -1) printf("%d不存在\n", k);
	else printf("%d下标为%d\n", k, index);
	return 0;
}

/*
12
19 14 23 1 68 20 84 27 55 11 10 79

15
19 14 23 1 68 20 84 27 55 11 10 79 0 13 14
*/