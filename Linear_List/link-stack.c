//链栈
//将首元节点作为栈顶

//#include<stdio.h>
//#include<stdlib.h>
//
////定义链栈节点
//typedef struct SNode {
//	int data;
//	struct SNode* next;
//}SNode,*LinkStack;
//
////初始化链栈
//LinkStack InitStack() {
//	LinkStack h = (SNode*)malloc(sizeof(SNode));
//	if (h == NULL) {
//		printf("链栈初始化失败");
//		return NULL;
//	}
//	h->next = NULL;
//	return h;
//}
//
////打印链栈中所有元素
//void PrintfStack(LinkStack ls) {
//	SNode* p = ls->next;
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////判断链栈是否为空
////1表示为空  0表示不为空
//int isEmpty(LinkStack ls) {
//	if (ls->next == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
////入栈(相当于单链表的头插法)
//LinkStack Push(LinkStack ls, int k) {
//	SNode* s = (SNode*)malloc(sizeof(SNode));
//	if (s == NULL) {
//		printf("新节点创建失败");
//		return ls;
//	}
//	s->data = k;
//	s->next = ls->next;
//	ls->next = s;
//	return ls;
//}
//
////出栈(相当于删除首元节点)
//LinkStack Pop(LinkStack ls) {
//	if (isEmpty(ls) == 1) {
//		printf("栈空");
//		return ls;
//	}
//	SNode* p = ls->next;
//	ls->next = p->next;
//	free(p);
//	p = NULL;
//	return ls;
//}
//
////获取栈顶元素
//int GetTop(LinkStack ls) {
//	if (isEmpty(ls) == 1) {
//		printf("栈空");
//		return -1;//-1表示栈空
//	}
//	return ls->next->data;
//}
//
//
//int main() {
//	LinkStack ls = InitStack();
//	ls = Push(ls, 1);
//	ls = Push(ls, 2);
//	ls = Push(ls, 3);
//	PrintfStack(ls);
//	ls = Pop(ls);
//	ls = Pop(ls);
//	PrintfStack(ls);
//	printf("%d", GetTop(ls));
//	return 0;
//}