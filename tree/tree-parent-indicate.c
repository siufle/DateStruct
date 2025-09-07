//双亲表示法存储树形结构

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//定义以双亲表示的树的结构体,并创建相应的全局变量
struct Tree {
	//存储数据
	char data;
	//存储双亲的下标
	int parent_index;
}t[MAX];

//存储树的实际大小
int length = 0;

//初始化树
void InitTree(char r) {
	t[0].data = r;
	t[0].parent_index = -1;
	length++;
}

//找到该数据下标
int FindNode(char px) {
	for (int i = 0; i < length; i++) {
		if (t[i].data == px) {
			return i;
		}
	}
	return -1;
}

//插入数据
void Insert(char x, char px) {
	if (length == MAX) {
		printf("当前数组已满");
		return;
	}
	t[length].data = x;
	t[length].parent_index = FindNode(px);
	length++;
}

int main() {
	//存储本次存储的树的期望长度
	int n;
	char r;
	//接收树的期望长度
	scanf_s("%d", &n);
	//接收前一个数据后的换行符，避免影响下一个数据输入
	char s = getchar();
	//输入根节点数据
	scanf_s("%c", &r);
	InitTree(r);
	char x;
	char px;
	for (int i = 1; i <= n - 1; i++) {
		s = getchar();
		//分别输入数据以及其双亲节点的数据
		scanf_s("%c ", &x);
		scanf_s("%c", &px);
		Insert(x, px);
	}

	//输入一个数据找到它的双亲和孩子
	s = getchar();
	scanf_s("%c", &x);
	int index = FindNode(x);
	//找双亲
	int parent = t[index].parent_index;
	if (parent == -1) {
		printf("%c是根节点", x);
	}
	else {
		printf("%c的双亲节点是%c\n", x, t[parent].data);
	}
	//找孩子
	for (int i = 1; i < length; i++) {
		if (t[i].parent_index == index) {
			printf("%c是%c的孩子\n", t[i].data, x);
		}
	}
	return 0;
}

/*
13
A
B A
C A
D A
E B
F B
G C
H D
I D
J D
K E
L E
M H
B
*/