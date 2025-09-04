//顺序循环双端队列

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
//
////定义顺序循环双端队列
////规定右端存储的第一个数据放在下标为0的位置
//typedef struct Deque {
//	//存储数据的数组
//	int* data;
//	//指向最左端数据的指针
//	int l;
//	//指向最右端数据的下一个数据的指针
//	int r;
//	//记录数据数量
//	int sum;
//}Deque;
//
////初始化顺序循环双端队列
//Deque InitDeque() {
//	Deque dq;
//	dq.data = (int*)malloc(sizeof(int) * MAX);
//	dq.l = 0;
//	dq.r = 0;
//	dq.sum = 0;
//	return dq;
//}
//
////在左端插入数据
//void LInsert(Deque* dq, int k) {
//	if (dq->sum == MAX) {
//		printf("顺序循环双端队列已满");
//		return;
//	}
//	dq->l = (dq->l - 1 + MAX) % MAX;
//	dq->data[dq->l] = k;
//	dq->sum++;
//}
//
////在右端插入数据
//void RInsert(Deque* dq, int k) {
//	if (dq->sum == MAX) {
//		printf("顺序循环双端队列已满");
//		return;
//	}
//	dq->data[dq->r] = k;
//	dq->r = (dq->r + 1) % MAX;
//	dq->sum++;
//}
//
////从左端删除数据
//void LDelete(Deque* dq) {
//	if (dq->sum == 0) {
//		printf("顺序循环双端队列为空");
//		return;
//	}
//	printf("%d出队\n", dq->data[dq->l]);
//	dq->l = (dq->l + 1) % MAX;
//	dq->sum--;
//}
//
////从右端删除数据
//void RDelete(Deque* dq) {
//	if (dq->sum == 0) {
//		printf("顺序循环双端队列为空");
//		return;
//	}
//	dq->r = (dq->r - 1 + MAX) % MAX;
//	printf("%d出队\n", dq->data[dq->r]);
//	dq->sum--;
//}
//
////打印顺序循环双端队列中数据
//void PrintDeque(Deque dq) {
//	//最左端数据所在位置
//	int i = dq.l;
//	//最右端数据所在位置
//	int temp = (dq.r - 1 + MAX) % MAX;
//	while (i != temp) {
//		printf("%d ", dq.data[i]);
//		i = (i + 1) % MAX;
//	}
//	printf("%d\n", dq.data[temp]);
//}
//
//int main() {
//	Deque dq = InitDeque();
//	LInsert(&dq, 1);
//	LInsert(&dq, 2);
//	RInsert(&dq, 3);
//	LInsert(&dq, 4);
//	RInsert(&dq, 5);
//	PrintDeque(dq);
//	LDelete(&dq);
//	RDelete(&dq);
//	LDelete(&dq);
//	RDelete(&dq);
//	LDelete(&dq);
//	return 0;
//}