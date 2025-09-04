//��ʽ˫�˶���
//�涨ͷ�ڵ�����������ڴ洢�Ҷ˵�һ������

#include<stdio.h>
#include<stdlib.h>

//����ڵ�
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//������ʽ˫�˶���
typedef struct LinkDeque {
	//ָ����������ݽڵ��ָ��
	Node* l;
	//ָ�����Ҷ����ݵ���һ���ڵ��ָ��
	Node* r;
}LinkDeque;

//��ʼ����ʽ˫�˶���
LinkDeque InitDeque() {
	LinkDeque ldq;
	ldq.l = NULL;
	ldq.r = NULL;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("��ʼ��ʧ��\n");
		return ldq;
	}
	s->next = NULL;
	s->pre = NULL;
	ldq.l = s;
	ldq.r = s;
	return ldq;
}

//�ж���ʽ˫�˶����Ƿ�Ϊ��
//1��ʾΪ��    0��ʾ��Ϊ��
int IsEmpty(LinkDeque ldq) {
	if (ldq.l == ldq.r) {
		return 1;
	}
	return 0;
}

//�����
void LInsert(LinkDeque* ldq, int k) {
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("���ʧ��\n");
		return;
	}
	s->data = k;
	s->next = ldq->l;
	s->pre = NULL;
	ldq->l->pre = s;
	ldq->l = s;
}

//�����
void RInsert(LinkDeque* ldq, int k) {
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		printf("���ʧ��\n");
		return;
	}
	s->pre = ldq->r;
	s->next = NULL;
	ldq->r->data = k;
	ldq->r->next = s;
	ldq->r = s;
}

//�����
void LDelete(LinkDeque* ldq) {
	if (IsEmpty(*ldq) == 1) {
		printf("�ӿ�\n");
		return;
	}
	Node* p = ldq->l;
	ldq->l = p->next;
	ldq->l->pre = NULL;
	free(p);
	p = NULL;
}

//�ҳ���
void RDelete(LinkDeque* ldq) {
	if (IsEmpty(*ldq) == 1) {
		printf("�ӿ�\n");
		return;
	}
	Node* p = ldq->r;
	ldq->r = p->pre;
	ldq->r->next = NULL;
	free(p);
	p = NULL;
}

//��ӡ��ʽ˫�˶�����������
void PrintDeque(LinkDeque ldq) {
	if (IsEmpty(ldq) == 1) {
		printf("�ӿ�\n");
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