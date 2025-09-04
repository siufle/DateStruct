//双向链表


//#include<stdio.h>
//#include<stdlib.h>
//
////定义双向链表节点
//typedef struct Node {
//	//数据域
//	int data;
//	//指向前一个节点的指针域
//	struct Node* pre;
//	//指向后一个节点的指针域
//	struct Node* next;
//}Node,*DoubleLinkedList;
//
////初始化双项链表
//DoubleLinkedList InitList() {
//	Node* h = (Node*)malloc(sizeof(Node));
//	h->next = NULL;
//	h->pre = NULL;
//	return h;
//}
//
////在双链表中查找指定数据的位置
//Node* Find(DoubleLinkedList dl, int k) {
//	Node* p = dl->next;
//	while (p != NULL && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//
////打印双链表中所有数据
//void PrintfList(DoubleLinkedList dl) {
//	Node* p = dl->next;
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////添加数据
////头插法
//DoubleLinkedList Head_Insert(DoubleLinkedList dl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("节点创建失败");
//		return dl;
//	}
//	s->data = k;
//	s->pre = dl;
//	s->next = dl->next;
//	if (dl->next != NULL) {
//		dl->next->pre = s;
//	}
//	dl->next = s;
//	return dl;
//}
////尾插法
//DoubleLinkedList Tail_Insert(DoubleLinkedList dl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("节点创建失败");
//		return dl;
//	}
//	s->data = k;
//	s->next = NULL;
//	Node* p = dl;
//	while (p->next != NULL) {
//		p = p->next;
//	}
//	s->pre = p;
//	p->next = s;
//	return dl;
//}
////在指定数据后插入数据
//DoubleLinkedList X_Insert(DoubleLinkedList dl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("节点创建失败");
//		return dl;
//	}
//	s->data = k;
//	Node* p = Find(dl, x);
//	s->pre = p;
//	s->next = p->next;
//	if (p->next != NULL) {
//		p->next->pre = s;
//	}
//	p->next = s;
//	return dl;
//}
//
////删除指定数据
//DoubleLinkedList DeleteList(DoubleLinkedList dl, int k) {
//	Node* p = Find(dl, k);
//	if (p == NULL) {
//		printf("该双链表中无%d", k);
//		return dl;
//	}
//	p->pre->next = p->next;
//	if (p->next != NULL) {
//		p->next->pre = p->pre;
//	}
//	free(p);
//	p = NULL;
//	return dl;
//}
//
////修改指定数据为另一个数据
//DoubleLinkedList UpdateList(DoubleLinkedList dl, int old, int new) {
//	Node* p = Find(dl, old);
//	if (p == NULL) {
//		printf("该双链表中无%d", old);
//		return dl;
//	}
//	p->data = new;
//	return dl;
//}
//
//int main() {
//	DoubleLinkedList dl = NULL;
//	dl = InitList();
//	dl = Head_Insert(dl, 1);
//	dl = Head_Insert(dl, 2);
//	dl = Head_Insert(dl, 3);
//	dl = Head_Insert(dl, 4);
//	PrintfList(dl);
//	dl = Tail_Insert(dl, 5);
//	dl = Tail_Insert(dl, 6);
//	PrintfList(dl);
//	dl = X_Insert(dl, 3, 7);
//	dl = X_Insert(dl, 6, 8);
//	PrintfList(dl);
//	dl = DeleteList(dl, 1);
//	dl = DeleteList(dl, 6);
//	PrintfList(dl);
//	dl = UpdateList(dl, 2, 9);
//	dl = UpdateList(dl, 7, 10);
//	PrintfList(dl);
//	return 0;
//}