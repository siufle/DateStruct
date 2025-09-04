//链式队列

//#include<stdio.h>
//#include<stdlib.h>
//
////定义链式队列节点
//typedef struct Node {
//	int data;
//	struct Node* next;
//}QNode;
//
////定义队列结构
//typedef struct Queue {
//	//队首指针
//	QNode* f;
//	//队尾指针
//	QNode* r;
//}Queue;
//
////初始化链式队列
//Queue InitQueue() {
//	Queue q;
//	q.f = (QNode*)malloc(sizeof(QNode));
//	q.f->next = NULL;
//	q.r = q.f;
//	return q;
//}
//
////判断链式队列是否为空
////1表示为空   0表示不为空
//int IsEmpty(Queue q) {
//	if (q.r == q.f) {
//		return 1;
//	}
//	return 0;
//}
//
////入队
//Queue EnQueue(Queue q, int k) {
//	QNode* s = (QNode*)malloc(sizeof(QNode));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return q;
//	}
//	s->data = k;
//	s->next = NULL;
//	q.r->next = s;
//	q.r = s;
//	return q;
//}
//
////出队
//Queue DeQueue(Queue q) {
//	if (IsEmpty(q) == 1) {
//		printf("队空");
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