//循环顺序队列
//可以避免伪溢出

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
//
////定义循环顺序队列
//typedef struct Queue {
//	int* data;
//	int f;
//	int r;
//}Queue;
//
////初始化循环队列
//Queue InitQueue() {
//	Queue q;
//	q.data = (int*)malloc(sizeof(int) * MAX);
//	q.f = 0;
//	q.r = 0;
//	return q;
//}
//
////判断循环队列是否已满
////1表示已满   0表示未满
//int IsFull(Queue q) {
//	if (q.f == (q.r + 1) % MAX) {
//		return 1;
//	}
//	return 0;
//}
//
////判断循环队列是否为空
////1表示空  0表示未空
//int IsEmpty(Queue q) {
//	if (q.f == q.r) {
//		return 1;
//	}
//	return 0;
//}
//
////入队
//Queue EnQueue(Queue q, int k) {
//	if (IsFull(q) == 1) {
//		printf("满队列\n");
//		return q;
//	}
//	q.data[q.r] = k;
//	q.r = (q.r + 1) % MAX;
//	return q;
//}
//
////出队
//Queue DeQueue(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("空队列\n");
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