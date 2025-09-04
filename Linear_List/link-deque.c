//链式双端队列
//规定头节点的数据域用于存储右端第一个数据

#include<stdio.h>
#include<stdlib.h>

//定义节点
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//定义链式双端队列
typedef struct LinkDeque {
	//指向最左端数据节点的指针
	Node* l;
	//指向最右端数据的下一个节点的指针
	Node* r;
}LinkDeque;

//初始化链式双端队列
LinkDeque InitDeque() {
	LinkDeque ldq;
	ldq.l = NULL;
	ldq.r = NULL;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("初始化失败\n");
		return ldq;
	}
	s->next = NULL;
	s->pre = NULL;
	ldq.l = s;
	ldq.r = s;
	return ldq;
}

//判断链式双端队列是否为空
//1表示为空    0表示不为空
int IsEmpty(LinkDeque ldq) {
	if (ldq.l == ldq.r) {
		return 1;
	}
	return 0;
}

//左入队
void LInsert(LinkDeque* ldq, int k) {
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("添加失败\n");
		return;
	}
	s->data = k;
	s->next = ldq->l;
	s->pre = NULL;
	ldq->l->pre = s;
	ldq->l = s;
}

//右入队
void RInsert(LinkDeque* ldq, int k) {
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("添加失败\n");
		return;
	}
	s->pre = ldq->r;
	s->next = NULL;
	ldq->r->data = k;
	ldq->r->next = s;
	ldq->r = s;
}

//左出队
void LDelete(LinkDeque* ldq) {
	if (IsEmpty(*ldq) == 1) {
		printf("队空\n");
		return;
	}
	Node* p = ldq->l;
	ldq->l = p->next;
	ldq->l->pre = NULL;
	free(p);
	p = NULL;
}

//右出队
void RDelete(LinkDeque* ldq) {
	if (IsEmpty(*ldq) == 1) {
		printf("队空\n");
		return;
	}
	Node* p = ldq->r;
	ldq->r = p->pre;
	ldq->r->next = NULL;
	free(p);
	p = NULL;
}

//打印链式双端队列所有数据
void PrintDeque(LinkDeque ldq) {
	if (IsEmpty(ldq) == 1) {
		printf("队空\n");
		return;
	}
	Node* p = ldq.l;
	while (p != ldq.r) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LinkDeque ldq = InitDeque();
	LInsert(&ldq, 1);
	LInsert(&ldq, 2);
	LInsert(&ldq, 3);
	RInsert(&ldq, 4);
	RInsert(&ldq, 5);
	PrintDeque(ldq);
	LDelete(&ldq);
	LDelete(&ldq);
	RDelete(&ldq);
	PrintDeque(ldq);
	LDelete(&ldq);
	LDelete(&ldq);
	PrintDeque(ldq);
	return 0;
}