//ѭ��˫������


//#include<stdio.h>
//#include<stdlib.h>
//
////����ѭ��˫������ڵ�
//typedef struct Node {
//	int data;
//	struct Node* pre;
//	struct Node* next;
//}Node,*Double_Circular_LinkedList;
//
////��ʼ��ѭ��˫������
//Double_Circular_LinkedList InitList() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("ѭ��˫�������ʼ��ʧ��");
//		return NULL;
//	}
//	head->next = head;
//	head->pre = head;
//	return head;
//}
//
////�ҵ�ָ������
//Node* Find(Double_Circular_LinkedList dcl, int x) {
//	Node* p = dcl->next;
//	while (p != dcl && p->data != x) {
//		p = p->next;
//	}
//	return p;
//}
//
////��ӡѭ��˫����������������
//void PrintfList(Double_Circular_LinkedList dcl) {
//	Node* p = dcl->next;
//	while (p != dcl) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////��ѭ��˫�������в�������
////ͷ�巨
//Double_Circular_LinkedList Head_Insert(Double_Circular_LinkedList dcl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return dcl;
//	}
//	s->data = k;
//	s->next = dcl->next;
//	s->pre = dcl;
//	dcl->next->pre = s;
//	dcl->next = s;
//	return dcl;
//}
////β�巨
//Double_Circular_LinkedList Tail_Insert(Double_Circular_LinkedList dcl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
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
////��ָ�����ݺ����������
//Double_Circular_LinkedList X_Insert(Double_Circular_LinkedList dcl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return dcl;
//	}
//	s->data = k;
//	Node* p = Find(dcl, x);
//	if (p == dcl) {
//		printf("ѭ��˫�������в�����%d", x);
//		return dcl;
//	}
//	s->next = p->next;
//	s->pre = p;
//	p->next->pre = s;
//	p->next = s;
//	return dcl;
//}
//
////ɾ��ָ������
//Double_Circular_LinkedList DeleteList(Double_Circular_LinkedList dcl, int x) {
//	Node* p = Find(dcl, x);
//	if (p == dcl) {
//		printf("ѭ��˫�������в�����%d", x);
//		return dcl;
//	}
//	p->pre->next = p->next;
//	p->next->pre = p->pre;
//	free(p);
//	p = NULL;
//	return dcl;
//}
//
////�޸�ָ������Ϊ�µ�����
//Double_Circular_LinkedList UpdateList(Double_Circular_LinkedList dcl, int old, int new) {
//	Node* p = Find(dcl, old);
//	if (p == dcl) {
//		printf("ѭ��˫�������в�����%d", old);
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