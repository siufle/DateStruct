//顺序栈

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
////定义顺序栈
//typedef struct Sstack {
//	//用数组存储栈中数据
//	int* data;
//	//栈顶指针
//	int top;
//}Sstack;
//
////打印顺序栈中所有元素
//void PrintfStack(Sstack s) {
//	for (int i = 0; i < s.top; i++) {
//		printf("%d  ", s.data[i]);
//	}
//	printf("\n");
//}
//
////初始化顺序栈
//Sstack InitStack() {
//	Sstack s;
//	s.data = (int *)malloc(sizeof(int) * MAX);
//	//指向栈顶元素的下一个元素
//	s.top = 0;
//	return s;
//}
//
////判断顺序栈是否为空
////1表示空，0表示非空
//int isEmpty(Sstack s) {
//	if (s.top == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////入栈
//Sstack Push(Sstack s, int k) {
//	if (s.top == MAX) {
//		printf("栈满");
//		return;
//	}
//	s.data[s.top] = k;
//	s.top++;
//	return s;
//}
//
////出栈
//Sstack Pop(Sstack s) {
//	if (isEmpty(s) == 1) {
//		printf("栈空");
//		return s;
//	}
//	s.top--;
//	return s;
//}
//
////获取栈顶元素
//int GetTop(Sstack s) {
//	if (isEmpty(s) == 1) {
//		printf("栈空");
//		return -1;//-1表示栈空
//	}
//	return s.data[s.top - 1];
//}
//
//int main() {
//	Sstack s = InitStack();
//	s = Push(s, 1);
//	s = Push(s, 2);
//	s = Push(s, 3);
//	PrintfStack(s);
//	s = Pop(s);
//	s = Pop(s);
//	PrintfStack(s);
//	printf("%d", GetTop(s));
//	return 0;
//}