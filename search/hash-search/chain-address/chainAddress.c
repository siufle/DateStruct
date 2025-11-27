//链地址法解决哈希冲突

#include<stdio.h>
#include<stdlib.h>

#define size 15
#define nul -1
//表长为m，n个数据构造散列表，保证n<=m 且表中数据均为非负整数
//Hash(key)=key%13
//处理冲突的方法：链地址

//链表的结点结构
typedef struct HNode{
	int data;
	struct Node* next;
}HNode;

//哈希表的结构
typedef struct HashTable {
	HNode* hash[size];//哈希数组
	int m;//表长
}HashTable;

//初始化
HashTable* Init()
{
	HashTable* h = (HashTable*)malloc(sizeof(HashTable));
	if (h == NULL)
	{
		printf("初始化失败\n");
		return NULL;
	}
	h->m = size;
	for (int i = 0; i < h->m; i++)
	{
		h->hash[i] = NULL;
	}
	return h;
}

//获取哈希值
int Hash(int k)
{
	return k % 13;
}

//插入数据
void Insert(HashTable* h, int k)
{
	int i = Hash(k);
	HNode* p = (HNode*)malloc(sizeof(HNode));
	if (p == NULL)
	{
		printf("新节点创建失败\n");
		return;
	}
	p->data = k;
	p->next = h->hash[i];
	h->hash[i] = p;
}

//查找数据 存在返回1 不存在返回-1
int Find_k(HashTable* h, int k)
{
	int i = Hash(k);
	HNode* p = h->hash[i];
	while (p != NULL)
	{
		if (p->data == k) return 1;
		p = p->next;
	}
	return 0;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	HashTable* h = Init();
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf_s("%d", &k);
		Insert(h, k);
	}
	//查找k是否存在
	int k;
	scanf_s("%d", &k);
	int flag = Find_k(h, k);
	if (flag == 0) printf("%d不存在\n", k);
	else printf("%d存在\n", k);
	return 0;
}

/*
12
19 14 23 1 68 20 84 27 55 11 10 79

15
19 14 23 1 68 20 84 27 55 11 10 79 0 13 14
*/