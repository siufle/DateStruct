//˳���


//#include<stdio.h>
//#include<stdlib.h>
//
////������󳤶�
//#define MAX 20
//
////����˳���洢�ṹ
//typedef struct SequenceList {
//	//���ڼ�¼����
//	int* data;
//	//���ڼ�¼���ݳ���
//	int len;
//}Sequence;
//
////��ʼ��˳���
//Sequence Init(Sequence s) {
//	//��ʼ������
//	s.data = (int *)malloc(sizeof(int) * MAX);
//	if (s.data == NULL) {
//		printf("��ʼ��ʧ��");
//	}
//	s.len = 0;
//	return s;
//}
//
////��ӡ˳���������Ԫ��
//void Printff(Sequence s) {
//	if (s.data == NULL) {
//		printf("˳���Ϊ��");
//		return ;
//	}
//	//˳�������Ԫ��
//	for (int i = 0; i < s.len; i++) {
//		printf("%d ",s.data[i]);
//	}
//	printf("\n");
//}
//
////��˳���ĩβ���Ԫ��
//Sequence Add(Sequence s, int k) {
//	if (s.len == MAX) {
//		printf("˳�������");
//		return s;
//	}
//	s.data[s.len] = k;
//	s.len++;
//	return s;
//}
//
////��˳����м����Ԫ��
//Sequence Insert(Sequence s, int position, int k) {
//	if (s.len == MAX) {
//		printf("˳�������");
//		return s;
//	}
//	//��i�Ժ����������������һλ
//	for (int j = s.len; j > position; j--) {
//		s.data[j] = s.data[j - 1];
//	}
//	//�����ݲ���ָ��λ��
//	s.data[position] = k;
//	s.len++;
//	return s;
//}
//
////����˳����е�Ԫ��,��������
//int Find(Sequence s, int k) {
//	for (int i = 0; i < s.len; i++) {
//		if (s.data[i] == k) {
//			return i;
//		}
//	}
//	//���������򷵻�-1
//	return -1;
//}
//
////ɾ��˳�����Ԫ��
//Sequence DeleteSe(Sequence s, int k) {
//	int index = Find(s, k);
//	if (index == -1) {
//		//������Ҫɾ��������
//		return s;
//	}
//	for (int i = index; i < s.len - 1; i++) {
//		s.data[i] = s.data[i + 1];
//	}
//	s.len--;
//	return s;
//}
//
////�޸�˳����е�Ԫ��
//Sequence Update(Sequence s, int old, int new) {
//	int index = Find(s, old);
//	if (index == -1) {
//		//������Ҫ�滻������
//		return s;
//	}
//	s.data[index] = new;
//	return s;
//}
//
//int main() {
//	Sequence s = {NULL,0};
//	s = Init(s);
//	s = Add(s, 1);
//	s = Add(s, 2);
//	s = Add(s, 3);
//	Printff(s);
//	s = Insert(s, 0, 5);
//	Printff(s);
//	s = Insert(s, 2, 9);
//	Printff(s);
//	//s = DeleteSe(s, 1);
//	s = Update(s, 2, 10);
//	Printff(s);
//	//int index = Find(s, 3);
//	int index = Find(s, 100);
//	printf("%d", index);
//	return 0;
//}