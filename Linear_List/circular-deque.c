//˳��ѭ��˫�˶���

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 20
//
////����˳��ѭ��˫�˶���
////�涨�Ҷ˴洢�ĵ�һ�����ݷ����±�Ϊ0��λ��
//typedef struct Deque {
//	//�洢���ݵ�����
//	int* data;
//	//ָ����������ݵ�ָ��
//	int l;
//	//ָ�����Ҷ����ݵ���һ�����ݵ�ָ��
//	int r;
//	//��¼��������
//	int sum;
//}Deque;
//
////��ʼ��˳��ѭ��˫�˶���
//Deque InitDeque() {
//	Deque dq;
//	dq.data = (int*)malloc(sizeof(int) * MAX);
//	dq.l = 0;
//	dq.r = 0;
//	dq.sum = 0;
//	return dq;
//}
//
////����˲�������
//void LInsert(Deque* dq, int k) {
//	if (dq->sum == MAX) {
//		printf("˳��ѭ��˫�˶�������");
//		return;
//	}
//	dq->l = (dq->l - 1 + MAX) % MAX;
//	dq->data[dq->l] = k;
//	dq->sum++;
//}
//
////���Ҷ˲�������
//void RInsert(Deque* dq, int k) {
//	if (dq->sum == MAX) {
//		printf("˳��ѭ��˫�˶�������");
//		return;
//	}
//	dq->data[dq->r] = k;
//	dq->r = (dq->r + 1) % MAX;
//	dq->sum++;
//}
//
////�����ɾ������
//void LDelete(Deque* dq) {
//	if (dq->sum == 0) {
//		printf("˳��ѭ��˫�˶���Ϊ��");
//		return;
//	}
//	printf("%d����\n", dq->data[dq->l]);
//	dq->l = (dq->l + 1) % MAX;
//	dq->sum--;
//}
//
////���Ҷ�ɾ������
//void RDelete(Deque* dq) {
//	if (dq->sum == 0) {
//		printf("˳��ѭ��˫�˶���Ϊ��");
//		return;
//	}
//	dq->r = (dq->r - 1 + MAX) % MAX;
//	printf("%d����\n", dq->data[dq->r]);
//	dq->sum--;
//}
//
////��ӡ˳��ѭ��˫�˶���������
//void PrintDeque(Deque dq) {
//	//�������������λ��
//	int i = dq.l;
//	//���Ҷ���������λ��
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