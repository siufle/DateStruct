//��ʽ����

//#include<stdio.h>
//#include<stdlib.h>
//
////������ʽ���нڵ�
//typedef struct Node {
//	int data;
//	struct Node* next;
//}QNode;
//
////������нṹ
//typedef struct Queue {
//	//����ָ��
//	QNode* f;
//	//��βָ��
//	QNode* r;
//}Queue;
//
////��ʼ����ʽ����
//Queue InitQueue() {
//	Queue q;
//	q.f = (QNode*)malloc(sizeof(QNode));
//	q.f->next = NULL;
//	q.r = q.f;
//	return q;
//}
//
////�ж���ʽ�����Ƿ�Ϊ��
////1��ʾΪ��   0��ʾ��Ϊ��
//int IsEmpty(Queue q) {
//	if (q.r == q.f) {
//		return 1;
//	}
//	return 0;
//}
//
////���
//Queue EnQueue(Queue q, int k) {
//	QNode* s = (QNode*)malloc(sizeof(QNode));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return q;
//	}
//	s->data = k;
//	s->next = NULL;
//	q.r->next = s;
//	q.r = s;
//	return q;
//}
//
////����
//Queue DeQueue(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("�ӿ�");
//		return q;
//	}
//	QNode* p = q.f->next;
//	if (p == q.r) {
//		q.r = q.f;
//	}
//	q.f->next = p->next;
//	free(p);
//	p = NULL;
//	return q;
//}
//
//int main() {
//	Queue q = InitQueue();
//	q = EnQueue(q, 1);
//	q = EnQueue(q, 2);
//	q = EnQueue(q, 3);
//	q = DeQueue(q);
//	q = DeQueue(q);
//	q = DeQueue(q);
//	q = DeQueue(q);
//	return 0;
//}