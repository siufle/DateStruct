//˫�ױ�ʾ���洢���νṹ

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//������˫�ױ�ʾ�����Ľṹ��,��������Ӧ��ȫ�ֱ���
struct Tree {
	//�洢����
	char data;
	//�洢˫�׵��±�
	int parent_index;
}t[MAX];

//�洢����ʵ�ʴ�С
int length = 0;

//��ʼ����
void InitTree(char r) {
	t[0].data = r;
	t[0].parent_index = -1;
	length++;
}

//�ҵ��������±�
int FindNode(char px) {
	for (int i = 0; i < length; i++) {
		if (t[i].data == px) {
			return i;
		}
	}
	return -1;
}

//��������
void Insert(char x, char px) {
	if (length == MAX) {
		printf("��ǰ��������");
		return;
	}
	t[length].data = x;
	t[length].parent_index = FindNode(px);
	length++;
}

int main() {
	//�洢���δ洢��������������
	int n;
	char r;
	//����������������
	scanf_s("%d", &n);
	//����ǰһ�����ݺ�Ļ��з�������Ӱ����һ����������
	char s = getchar();
	//������ڵ�����
	scanf_s("%c", &r);
	InitTree(r);
	char x;
	char px;
	for (int i = 1; i <= n - 1; i++) {
		s = getchar();
		//�ֱ����������Լ���˫�׽ڵ������
		scanf_s("%c ", &x);
		scanf_s("%c", &px);
		Insert(x, px);
	}

	//����һ�������ҵ�����˫�׺ͺ���
	s = getchar();
	scanf_s("%c", &x);
	int index = FindNode(x);
	//��˫��
	int parent = t[index].parent_index;
	if (parent == -1) {
		printf("%c�Ǹ��ڵ�", x);
	}
	else {
		printf("%c��˫�׽ڵ���%c\n", x, t[parent].data);
	}
	//�Һ���
	for (int i = 1; i < length; i++) {
		if (t[i].parent_index == index) {
			printf("%c��%c�ĺ���\n", t[i].data, x);
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