//链表


//#include<stdio.h>
//#include<stdlib.h>
//
////创建链表节点
//typedef struct Node {
//	//数据域
//	int data;
//	//指针域
//	struct Node* next;
//}Node,*LinkedList;
//
////初始化空链表
//LinkedList InitList(LinkedList l) {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("初始化失败");
//		return l;
//	}
//	head->next = NULL;
//	l = head;
//	return l;
//}
//
////打印链表中所有数据
//void PrintList(LinkedList l) {
//	Node* p = l->next;
//	while(p != NULL){
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////查找链表中某个数据的地址
//Node* Find(LinkedList l, int k) {
//	Node* p = l->next;
//	while (p != NULL && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//
////插入数据
////头插法
//LinkedList Head_insert(LinkedList l, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return l;
//	}
//	s->data = k;
//	s->next = l->next;
//	l->next = s;
//	return l;
//}
////尾插法
//LinkedList Tail_insert(LinkedList l, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return l;
//	}
//	s->data = k;
//	s->next = NULL;
//	Node* p = l;
//	//找到链表的末尾
//	while (p->next != NULL) {
//		p = p->next;
//	}
//	p->next = s;
//	return l;
//}
////在指定数据后插入数据
//LinkedList X_insert(LinkedList l, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return l;
//	}
//	s->data = k;
//	Node* p = Find(l, x);
//	if (p == NULL) {
//		printf("链表中不存在%d", x);
//		return l;
//	}
//	s->next = p->next;
//	p->next = s;
//	return l;
//}
//
////删除指定数据
//LinkedList DeleteList(LinkedList l, int k) {
//	//存储x地址
//	Node* p = l->next;
//	//存储x前一个节点地址
//	Node* q = l;
//	while (p != NULL && p->data != k) {
//		q = p;
//		p = p->next;
//	}
//	if (p == NULL) {
//		printf("链表中不存在%d", k);
//		return l;
//	}
//	q->next = p->next;
//	free(p);
//	p = NULL;
//	return l;
//}
//
////修改保存指定数据的节点的数据域为新数据
//LinkedList UpdateList(LinkedList l,int old,int new) {
//	Node* p = Find(l, old);
//	p->data = new;
//	return l;
//}
//
//int main(){
//	LinkedList l = NULL;
//	l = InitList(l);
//	l = Head_insert(l, 1);
//	l = Head_insert(l, 2);
//	l = Head_insert(l, 3);
//	PrintList(l);
//	l = Tail_insert(l, 4);
//	l = Tail_insert(l, 5);
//	l = Tail_insert(l, 6);
//	PrintList(l);
//	l = X_insert(l, 2, 8);
//	l = X_insert(l, 5, 7);
//	PrintList(l);
//	l = DeleteList(l, 3);
//	PrintList(l);
//	l = UpdateList(l, 7, 9);
//	PrintList(l);
//	return 0;
//}