//队列
//用数组实现顺序队列

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 20
//
////定义顺序队列
//typedef struct Queue {
//	int* data;
//	//指向队首的指针
//	int f;
//	//指向队尾的指针
//	int r;
//}Queue;
//
////初始化顺序队列
//Queue InitQueue() {
//	Queue q;
//	q.data = (int*)malloc(sizeof(int) * MAX);
//	q.f = 0;
//	q.r = 0;
//	return q;
//}
//
////打印队列中所有元素
//void PrintfQueue(Queue q) {
//	for (int i = q.f; i < q.r; i++) {
//		printf("%d  ", q.data[i]);
//	}
//	printf("\n");
//}
//
////判断顺序队列是否已满(伪溢出)
////1表示已满  0表示未满
//int IsFull(Queue q) {
//	if (q.r == MAX) {
//		return 1;
//	}
//	return 0;
//}
//
////判断顺序队列是否为空
////1表示为空  0表示不为空
//int IsEmpty(Queue q) {
//	if (q.f == q.r) {
//		return 1;
//	}
//	return 0;
//}
//
////入队
//Queue Push(Queue q, int k) {
//	if (IsFull(q) == 1) {
//		printf("队列已满");
//		return q;
//	}
//	q.data[q.r] = k;
//	q.r++;
//	return q;
//}
//
////出队
//Queue Pop(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("队列为空");
//		return q;
//	}
//	q.f++;
//	return q;
//}
//
////获取队首元素
//int GetFirst(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("队列为空");
//		return -1;//-1表示队列为空
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