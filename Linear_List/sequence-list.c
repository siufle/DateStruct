//顺序表


//#include<stdio.h>
//#include<stdlib.h>
//
////数组最大长度
//#define MAX 20
//
////创建顺序表存储结构
//typedef struct SequenceList {
//	//用于记录数据
//	int* data;
//	//用于记录数据长度
//	int len;
//}Sequence;
//
////初始化顺序表
//Sequence Init(Sequence s) {
//	//初始化数组
//	s.data = (int *)malloc(sizeof(int) * MAX);
//	if (s.data == NULL) {
//		printf("初始化失败");
//	}
//	s.len = 0;
//	return s;
//}
//
////打印顺序表中所有元素
//void Printff(Sequence s) {
//	if (s.data == NULL) {
//		printf("顺序表为空");
//		return ;
//	}
//	//顺序表中有元素
//	for (int i = 0; i < s.len; i++) {
//		printf("%d ",s.data[i]);
//	}
//	printf("\n");
//}
//
////在顺序表末尾添加元素
//Sequence Add(Sequence s, int k) {
//	if (s.len == MAX) {
//		printf("顺序表已满");
//		return s;
//	}
//	s.data[s.len] = k;
//	s.len++;
//	return s;
//}
//
////在顺序表中间插入元素
//Sequence Insert(Sequence s, int position, int k) {
//	if (s.len == MAX) {
//		printf("顺序表已满");
//		return s;
//	}
//	//将i以后的数据依次往后移一位
//	for (int j = s.len; j > position; j--) {
//		s.data[j] = s.data[j - 1];
//	}
//	//将数据插入指定位置
//	s.data[position] = k;
//	s.len++;
//	return s;
//}
//
////查找顺序表中的元素,返回索引
//int Find(Sequence s, int k) {
//	for (int i = 0; i < s.len; i++) {
//		if (s.data[i] == k) {
//			return i;
//		}
//	}
//	//若不存在则返回-1
//	return -1;
//}
//
////删除顺序表中元素
//Sequence DeleteSe(Sequence s, int k) {
//	int index = Find(s, k);
//	if (index == -1) {
//		//不存在要删除的数据
//		return s;
//	}
//	for (int i = index; i < s.len - 1; i++) {
//		s.data[i] = s.data[i + 1];
//	}
//	s.len--;
//	return s;
//}
//
////修改顺序表中的元素
//Sequence Update(Sequence s, int old, int new) {
//	int index = Find(s, old);
//	if (index == -1) {
//		//不存在要替换的数据
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