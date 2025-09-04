//循环双向链表


//#include<stdio.h>
//#include<stdlib.h>
//
////定义循环双向链表节点
//typedef struct Node {
//	int data;
//	struct Node* pre;
//	struct Node* next;
//}Node,*Double_Circular_LinkedList;
//
////初始化循环双向链表
//Double_Circular_LinkedList InitList() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("循环双向链表初始化失败");
//		return NULL;
//	}
//	head->next = head;
//	head->pre = head;
//	return head;
//}
//
////找到指定数据
//Node* Find(Double_Circular_LinkedList dcl, int x) {
//	Node* p = dcl->next;
//	while (p != dcl && p->data != x) {
//		p = p->next;
//	}
//	return p;
//}
//
////打印循环双向链表中所有数据
//void PrintfList(Double_Circular_LinkedList dcl) {
//	Node* p = dcl->next;
//	while (p != dcl) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////在循环双向链表中插入数据
////头插法
//Double_Circular_LinkedList Head_Insert(Double_Circular_LinkedList dcl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return dcl;
//	}
//	s->data = k;
//	s->next = dcl->next;
//	s->pre = dcl;
//	dcl->next->pre = s;
//	dcl->next = s;
//	return dcl;
//}
////尾插法
//Double_Circular_LinkedList Tail_Insert(Double_Circular_LinkedList dcl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return dcl;
//	}
//	s->data = k;
//	s->next = dcl;
//	Node* p = dcl->pre;  
//	s->pre = p;
//	p->next = s;
//	dcl->pre = s;
//	return dcl;
//}
////在指定数据后插入新数据
//Double_Circular_LinkedList X_Insert(Double_Circular_LinkedList dcl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return dcl;
//	}
//	s->data = k;
//	Node* p = Find(dcl, x);
//	if (p == dcl) {
//		printf("循环双向链表中不存在%d", x);
//		return dcl;
//	}
//	s->next = p->next;
//	s->pre = p;
//	p->next->pre = s;
//	p->next = s;
//	return dcl;
//}
//
////删除指定数据
//Double_Circular_LinkedList DeleteList(Double_Circular_LinkedList dcl, int x) {
//	Node* p = Find(dcl, x);
//	if (p == dcl) {
//		printf("循环双向链表中不存在%d", x);
//		return dcl;
//	}
//	p->pre->next = p->next;
//	p->next->pre = p->pre;
//	free(p);
//	p = NULL;
//	return dcl;
//}
//
////修改指定数据为新的数据
//Double_Circular_LinkedList UpdateList(Double_Circular_LinkedList dcl, int old, int new) {
//	Node* p = Find(dcl, old);
//	if (p == dcl) {
//		printf("循环双向链表中不存在%d", old);
//		return dcl;
//	}
//	p->data = new;
//	return dcl;
//}
//
//int main() {
//	Double_Circular_LinkedList dcl = NULL;
//	dcl = InitList();
//	dcl = Head_Insert(dcl, 1);
//	dcl = Head_Insert(dcl, 2);
//	dcl = Head_Insert(dcl, 3);
//	dcl = Head_Insert(dcl, 4);
//	PrintfList(dcl);
//	dcl = Tail_Insert(dcl, 5);
//	dcl = Tail_Insert(dcl, 6);
//	dcl = Tail_Insert(dcl, 7);
//	PrintfList(dcl);
//	dcl = X_Insert(dcl,3, 8);
//	dcl = X_Insert(dcl,6, 9);
//	PrintfList(dcl);
//	dcl = DeleteList(dcl, 4);
//	dcl = DeleteList(dcl, 1);
//	PrintfList(dcl);
//	dcl = UpdateList(dcl, 6, 10);
//	PrintfList(dcl);
//	return 0;
//}