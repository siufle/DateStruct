//ѭ��˳�����
//���Ա���α���

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
//
////����ѭ��˳�����
//typedef struct Queue {
//	int* data;
//	int f;
//	int r;
//}Queue;
//
////��ʼ��ѭ������
//Queue InitQueue() {
//	Queue q;
//	q.data = (int*)malloc(sizeof(int) * MAX);
//	q.f = 0;
//	q.r = 0;
//	return q;
//}
//
////�ж�ѭ�������Ƿ�����
////1��ʾ����   0��ʾδ��
//int IsFull(Queue q) {
//	if (q.f == (q.r + 1) % MAX) {
//		return 1;
//	}
//	return 0;
//}
//
////�ж�ѭ�������Ƿ�Ϊ��
////1��ʾ��  0��ʾδ��
//int IsEmpty(Queue q) {
//	if (q.f == q.r) {
//		return 1;
//	}
//	return 0;
//}
//
////���
//Queue EnQueue(Queue q, int k) {
//	if (IsFull(q) == 1) {
//		printf("������\n");
//		return q;
//	}
//	q.data[q.r] = k;
//	q.r = (q.r + 1) % MAX;
//	return q;
//}
//
////����
//Queue DeQueue(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("�ն���\n");
//		return q;
//	}
//	q.f = (q.f + 1) % MAX;
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