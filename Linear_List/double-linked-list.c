//˫������


//#include<stdio.h>
//#include<stdlib.h>
//
////����˫������ڵ�
//typedef struct Node {
//	//������
//	int data;
//	//ָ��ǰһ���ڵ��ָ����
//	struct Node* pre;
//	//ָ���һ���ڵ��ָ����
//	struct Node* next;
//}Node,*DoubleLinkedList;
//
////��ʼ��˫������
//DoubleLinkedList InitList() {
//	Node* h = (Node*)malloc(sizeof(Node));
//	h->next = NULL;
//	h->pre = NULL;
//	return h;
//}
//
////��˫�����в���ָ�����ݵ�λ��
//Node* Find(DoubleLinkedList dl, int k) {
//	Node* p = dl->next;
//	while (p != NULL && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//
////��ӡ˫��������������
//void PrintfList(DoubleLinkedList dl) {
//	Node* p = dl->next;
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////�������
////ͷ�巨
//DoubleLinkedList Head_Insert(DoubleLinkedList dl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�ڵ㴴��ʧ��");
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
////β�巨
//DoubleLinkedList Tail_Insert(DoubleLinkedList dl, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�ڵ㴴��ʧ��");
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
////��ָ�����ݺ��������
//DoubleLinkedList X_Insert(DoubleLinkedList dl, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�ڵ㴴��ʧ��");
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
////ɾ��ָ������
//DoubleLinkedList DeleteList(DoubleLinkedList dl, int k) {
//	Node* p = Find(dl, k);
//	if (p == NULL) {
//		printf("��˫��������%d", k);
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
////�޸�ָ������Ϊ��һ������
//DoubleLinkedList UpdateList(DoubleLinkedList dl, int old, int new) {
//	Node* p = Find(dl, old);
//	if (p == NULL) {
//		printf("��˫��������%d", old);
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