//����
//������ʵ��˳�����

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 20
//
////����˳�����
//typedef struct Queue {
//	int* data;
//	//ָ����׵�ָ��
//	int f;
//	//ָ���β��ָ��
//	int r;
//}Queue;
//
////��ʼ��˳�����
//Queue InitQueue() {
//	Queue q;
//	q.data = (int*)malloc(sizeof(int) * MAX);
//	q.f = 0;
//	q.r = 0;
//	return q;
//}
//
////��ӡ����������Ԫ��
//void PrintfQueue(Queue q) {
//	for (int i = q.f; i < q.r; i++) {
//		printf("%d  ", q.data[i]);
//	}
//	printf("\n");
//}
//
////�ж�˳������Ƿ�����(α���)
////1��ʾ����  0��ʾδ��
//int IsFull(Queue q) {
//	if (q.r == MAX) {
//		return 1;
//	}
//	return 0;
//}
//
////�ж�˳������Ƿ�Ϊ��
////1��ʾΪ��  0��ʾ��Ϊ��
//int IsEmpty(Queue q) {
//	if (q.f == q.r) {
//		return 1;
//	}
//	return 0;
//}
//
////���
//Queue Push(Queue q, int k) {
//	if (IsFull(q) == 1) {
//		printf("��������");
//		return q;
//	}
//	q.data[q.r] = k;
//	q.r++;
//	return q;
//}
//
////����
//Queue Pop(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("����Ϊ��");
//		return q;
//	}
//	q.f++;
//	return q;
//}
//
////��ȡ����Ԫ��
//int GetFirst(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("����Ϊ��");
//		return -1;//-1��ʾ����Ϊ��
//	}
//	return q.data[q.f];
//}
//
//int main() {
//	Queue q = InitQueue();
//	q = Push(q, 1);
//	q = Push(q, 2);
//	q = Push(q, 3);
//	q = Push(q, 4);
//	PrintfQueue(q);
//	q = Pop(q);
//	q = Pop(q);
//	PrintfQueue(q);
//	printf("%d", GetFirst(q));
//	return 0;
//}