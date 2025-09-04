//循环单链表


//#include<stdio.h>
//#include<stdlib.h>
//
////定义循环单链表的节点
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *Circular_LinkedList;
//
////初始化一个循环单链表的头节点
//Circular_LinkedList InitList() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("初始化失败");
//		return NULL;
//	}
//	head->next = head;
//	return head;
//}
//
////在循环单链表中找到指定数据
//Node* Find(Circular_LinkedList cl, int x) {
//	Node* p = cl->next;
//	while (p != cl && p->data != x) {
//		p = p->next;
//	}
//	return p;
//}
//
////打印循环单链表中所有数据
//void PrintfList(Circular_LinkedList cl) {
//	Node* p = cl->next;
//	while (p != cl) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////在循环单链表中添加数据
////头插法
//Circular_LinkedList Head_Insert(Circular_LinkedList cl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return cl;
//	}
//	s->data = k;
//	s->next = cl->next;
//	cl->next = s;
//	return cl;
//}
////尾插法
//Circular_LinkedList Tail_Insert(Circular_LinkedList cl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return cl;
//	}
//	s->data = k;
//	s->next = cl;
//	//找到尾节点
//	Node* p = cl;
//	while (p->next != cl) {
//		p = p->next;
//	}
//	p->next = s;
//	return cl;
//}
////在指定数据后面插入数据
//Circular_LinkedList X_Insert(Circular_LinkedList cl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return cl;
//	}
//	s->data = k;
//	Node* p = Find(cl, x);
//	if (p == cl) {
//		printf("循环单链表中不存在%d", x);
//		return cl;
//	}
//	s->next = p->next;
//	p->next = s;
//	return cl;
//}
//
////删除指定数据
//Circular_LinkedList DeleteList(Circular_LinkedList cl, int x) {
//	Node* p = cl->next;
//	Node* q = cl;
//	while (p != cl && p->data != x) {
//		q = p;
//		p = p->next;
//	}
//	if (p == cl) {
//		printf("循环单链表中不存在%d", x);
//		return cl;
//	}
//	q->next = p->next;
//	free(p);
//	p = NULL;
//	return cl;
//}
//
////修改指定数据为新的数据
//Circular_LinkedList UpdateList(Circular_LinkedList cl, int old, int new) {
//	Node* p = Find(cl, old);
//	if (p == cl) {
//		printf("循环单链表中不存在%d", old);
//		return cl;
//	}
//	p->data = new;
//	return cl;
//}
//
//
//int main() {
//	Circular_LinkedList cl = NULL;
//	cl = InitList();
//	cl = Head_Insert(cl, 1);
//	cl = Head_Insert(cl, 2);
//	cl = Head_Insert(cl, 3);
//	cl = Head_Insert(cl, 4);
//	PrintfList(cl);
//	cl = Tail_Insert(cl, 5);
//	cl = Tail_Insert(cl, 6);
//	cl = Tail_Insert(cl, 7);
//	PrintfList(cl);
//	cl = X_Insert(cl,3, 8);
//	cl = X_Insert(cl,6, 9);
//	PrintfList(cl);
//	cl = DeleteList(cl, 4);
//	cl = DeleteList(cl, 1);
//	PrintfList(cl);
//	cl = UpdateList(cl, 6, 10);
//	PrintfList(cl);
//	return 0;
//}