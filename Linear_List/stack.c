//˳��ջ

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
////����˳��ջ
//typedef struct Sstack {
//	//������洢ջ������
//	int* data;
//	//ջ��ָ��
//	int top;
//}Sstack;
//
////��ӡ˳��ջ������Ԫ��
//void PrintfStack(Sstack s) {
//	for (int i = 0; i < s.top; i++) {
//		printf("%d  ", s.data[i]);
//	}
//	printf("\n");
//}
//
////��ʼ��˳��ջ
//Sstack InitStack() {
//	Sstack s;
//	s.data = (int *)malloc(sizeof(int) * MAX);
//	//ָ��ջ��Ԫ�ص���һ��Ԫ��
//	s.top = 0;
//	return s;
//}
//
////�ж�˳��ջ�Ƿ�Ϊ��
////1��ʾ�գ�0��ʾ�ǿ�
//int isEmpty(Sstack s) {
//	if (s.top == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////��ջ
//Sstack Push(Sstack s, int k) {
//	if (s.top == MAX) {
//		printf("ջ��");
//		return;
//	}
//	s.data[s.top] = k;
//	s.top++;
//	return s;
//}
//
////��ջ
//Sstack Pop(Sstack s) {
//	if (isEmpty(s) == 1) {
//		printf("ջ��");
//		return s;
//	}
//	s.top--;
//	return s;
//}
//
////��ȡջ��Ԫ��
//int GetTop(Sstack s) {
//	if (isEmpty(s) == 1) {
//		printf("ջ��");
//		return -1;//-1��ʾջ��
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