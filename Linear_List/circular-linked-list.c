//ѭ��������


//#include<stdio.h>
//#include<stdlib.h>
//
////����ѭ��������Ľڵ�
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *Circular_LinkedList;
//
////��ʼ��һ��ѭ���������ͷ�ڵ�
//Circular_LinkedList InitList() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("��ʼ��ʧ��");
//		return NULL;
//	}
//	head->next = head;
//	return head;
//}
//
////��ѭ�����������ҵ�ָ������
//Node* Find(Circular_LinkedList cl, int x) {
//	Node* p = cl->next;
//	while (p != cl && p->data != x) {
//		p = p->next;
//	}
//	return p;
//}
//
////��ӡѭ������������������
//void PrintfList(Circular_LinkedList cl) {
//	Node* p = cl->next;
//	while (p != cl) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////��ѭ�����������������
////ͷ�巨
//Circular_LinkedList Head_Insert(Circular_LinkedList cl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return cl;
//	}
//	s->data = k;
//	s->next = cl->next;
//	cl->next = s;
//	return cl;
//}
////β�巨
//Circular_LinkedList Tail_Insert(Circular_LinkedList cl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return cl;
//	}
//	s->data = k;
//	s->next = cl;
//	//�ҵ�β�ڵ�
//	Node* p = cl;
//	while (p->next != cl) {
//		p = p->next;
//	}
//	p->next = s;
//	return cl;
//}
////��ָ�����ݺ����������
//Circular_LinkedList X_Insert(Circular_LinkedList cl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return cl;
//	}
//	s->data = k;
//	Node* p = Find(cl, x);
//	if (p == cl) {
//		printf("ѭ���������в�����%d", x);
//		return cl;
//	}
//	s->next = p->next;
//	p->next = s;
//	return cl;
//}
//
////ɾ��ָ������
//Circular_LinkedList DeleteList(Circular_LinkedList cl, int x) {
//	Node* p = cl->next;
//	Node* q = cl;
//	while (p != cl && p->data != x) {
//		q = p;
//		p = p->next;
//	}
//	if (p == cl) {
//		printf("ѭ���������в�����%d", x);
//		return cl;
//	}
//	q->next = p->next;
//	free(p);
//	p = NULL;
//	return cl;
//}
//
////�޸�ָ������Ϊ�µ�����
//Circular_LinkedList UpdateList(Circular_LinkedList cl, int old, int new) {
//	Node* p = Find(cl, old);
//	if (p == cl) {
//		printf("ѭ���������в�����%d", old);
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