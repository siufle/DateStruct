//��ջ
//����Ԫ�ڵ���Ϊջ��

//#include<stdio.h>
//#include<stdlib.h>
//
////������ջ�ڵ�
//typedef struct SNode {
//	int data;
//	struct SNode* next;
//}SNode,*LinkStack;
//
////��ʼ����ջ
//LinkStack InitStack() {
//	LinkStack h = (SNode*)malloc(sizeof(SNode));
//	if (h == NULL) {
//		printf("��ջ��ʼ��ʧ��");
//		return NULL;
//	}
//	h->next = NULL;
//	return h;
//}
//
////��ӡ��ջ������Ԫ��
//void PrintfStack(LinkStack ls) {
//	SNode* p = ls->next;
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
////�ж���ջ�Ƿ�Ϊ��
////1��ʾΪ��  0��ʾ��Ϊ��
//int isEmpty(LinkStack ls) {
//	if (ls->next == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
////��ջ(�൱�ڵ������ͷ�巨)
//LinkStack Push(LinkStack ls, int k) {
//	SNode* s = (SNode*)malloc(sizeof(SNode));
//	if (s == NULL) {
//		printf("�½ڵ㴴��ʧ��");
//		return ls;
//	}
//	s->data = k;
//	s->next = ls->next;
//	ls->next = s;
//	return ls;
//}
//
////��ջ(�൱��ɾ����Ԫ�ڵ�)
//LinkStack Pop(LinkStack ls) {
//	if (isEmpty(ls) == 1) {
//		printf("ջ��");
//		return ls;
//	}
//	SNode* p = ls->next;
//	ls->next = p->next;
//	free(p);
//	p = NULL;
//	return ls;
//}
//
////��ȡջ��Ԫ��
//int GetTop(LinkStack ls) {
//	if (isEmpty(ls) == 1) {
//		printf("ջ��");
//		return -1;//-1��ʾջ��
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