//����


//#include<stdio.h>
//#include<stdlib.h>
//
////��������ڵ�
//typedef struct Node {
//	//������
//	int data;
//	//ָ����
//	struct Node* next;
//}Node,*LinkedList;
//
////��ʼ��������
//LinkedList InitList(LinkedList l) {
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL) {
//		printf("��ʼ��ʧ��");
//		return l;
//	}
//	head->next = NULL;
//	l = head;
//	return l;
//}
//
////��ӡ��������������
//void PrintList(LinkedList l) {
//	Node* p = l->next;
//	while(p != NULL){
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////����������ĳ�����ݵĵ�ַ
//Node* Find(LinkedList l, int k) {
//	Node* p = l->next;
//	while (p != NULL && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//
////��������
////ͷ�巨
//LinkedList Head_insert(LinkedList l, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return l;
//	}
//	s->data = k;
//	s->next = l->next;
//	l->next = s;
//	return l;
//}
////β�巨
//LinkedList Tail_insert(LinkedList l, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return l;
//	}
//	s->data = k;
//	s->next = NULL;
//	Node* p = l;
//	//�ҵ������ĩβ
//	while (p->next != NULL) {
//		p = p->next;
//	}
//	p->next = s;
//	return l;
//}
////��ָ�����ݺ��������
//LinkedList X_insert(LinkedList l, int x, int k) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return l;
//	}
//	s->data = k;
//	Node* p = Find(l, x);
//	if (p == NULL) {
//		printf("�����в�����%d", x);
//		return l;
//	}
//	s->next = p->next;
//	p->next = s;
//	return l;
//}
//
////ɾ��ָ������
//LinkedList DeleteList(LinkedList l, int k) {
//	//�洢x��ַ
//	Node* p = l->next;
//	//�洢xǰһ���ڵ��ַ
//	Node* q = l;
//	while (p != NULL && p->data != k) {
//		q = p;
//		p = p->next;
//	}
//	if (p == NULL) {
//		printf("�����в�����%d", k);
//		return l;
//	}
//	q->next = p->next;
//	free(p);
//	p = NULL;
//	return l;
//}
//
////�޸ı���ָ�����ݵĽڵ��������Ϊ������
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