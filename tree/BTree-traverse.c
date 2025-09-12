//���ı�����ʽ

//1.��ȱ���(��α���)
//��������ʵ��  �Ƚ����ڵ���� Ȼ��ѭ��(ֱ��������Ԫ��)������Ԫ�س����ٽ�����Ԫ�ص��������

//2.��ȱ���(�������򣬺������)

//#include<stdio.h>
//#include<stdlib.h>
//
////������нڵ�
//typedef struct QNode
//{
//	char data;
//	struct QNode* next;
//}QNode;
//
////�������
//typedef struct Queue
//{
//	//����ָ��
//	QNode* f;
//	//��βָ��
//	QNode* r;
//}Queue;
//
////��ʼ������
//Queue InitQueue()
//{
//	Queue q;
//	q.f = (QNode*)malloc(sizeof(QNode));
//	if (q.f == NULL)
//	{
//		printf("��ʼ��ʧ��");
//		return q;
//	}
//	q.f->next = NULL;
//	q.r = q.f;
//	return q;
//}
//
////���
//void EnQueue(Queue* q, char x)
//{
//	QNode* s = (QNode*)malloc(sizeof(QNode));
//	if (s == NULL)
//	{
//		printf("�½ڵ㴴��ʧ��");
//		return;
//	}
//	s->data = x;
//	s->next = NULL;
//	q->r->next = s;
//	q->r = s;
//}
//
////�п�
////1��ʾ��  0��ʾ�ǿ�
//int IsEmpty(Queue* q)
//{
//	if (q->f->next == NULL)
//	{
//		return 1;
//	}
//	return 0;
//}
//
////����
//char DeQueue(Queue* q)
//{
//	if (IsEmpty(q) == 1)
//	{
//		printf("�ӿ�\n");
//		return ' ';
//	}
//	else 
//	{
//		QNode* p = q->f->next;
//		char c = p->data;
//		if (q->r == q->f->next)
//		{
//			q->r = q->f;
//		}
//		q->f->next = p->next;
//		free(p);
//		p = NULL;
//		return c;
//	}
//}
//
////-------------------------------------------
//
////�����������ڵ�
//typedef struct BTNode
//{
//	char data;
//	struct BTNode* lch;
//	struct BTNode* rch;
//}BTNode,*LinkBTree;
//
//
//
////��ʼ��
//LinkBTree InitBTree(char r)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("��ʼ��ʧ��");
//		return NULL;
//	}
//	s->data = r;
//	s->lch = NULL;
//	s->rch = NULL;
//	return s;
//}
//
////����
//BTNode* Find(LinkBTree root, char px)
//{
//	if (root->data == px)
//	{
//		return root;
//	}
//	if (root->lch != NULL)
//	{
//		BTNode* ans = Find(root->lch, px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	if (root->rch != NULL)
//	{
//		BTNode* ans = Find(root->rch, px);
//		if (ans != NULL)
//		{
//			return ans;
//		}
//	}
//	return NULL;
//}
//
////����
//LinkBTree Insert(LinkBTree root, char x, char px, int flag)
//{
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	if (s == NULL)
//	{
//		printf("�½ڵ㴴��ʧ��");
//		return root;
//	}
//	s->data = x;
//	s->lch = NULL;
//	s->rch = NULL;
//	BTNode* parent = Find(root,px);
//	if (flag == 0)
//	{
//		parent->lch = s;
//	}
//	else
//	{
//		parent->rch = s;
//	}
//	return root;
//}
//
////��α���
//void levelOrderBT(LinkBTree root)
//{
//	Queue q = InitQueue();
//	EnQueue(&q, root->data);
//	while (IsEmpty(&q) == 0)
//	{
//		char c = DeQueue(&q);
//		printf("%c ", c);
//		BTNode* p = Find(root, c);
//		if (p->lch != NULL)
//		{
//			EnQueue(&q, p->lch->data);
//		}
//		if (p->rch != NULL)
//		{
//			EnQueue(&q, p->rch->data);
//		}
//	}
//}
//
////�������
//void PreOrderBT(LinkBTree root)
//{
//	//�ݹ��������
//	if (root == NULL)
//	{
//		return;
//	}
//	//������ڵ�����
//	printf("%c ", root->data);
//	//����������
//	PreOrderBT(root->lch);
//	//����������
//	PreOrderBT(root->rch);
//}
//
////�������
//void InOrderBT(LinkBTree root)
//{
//	//�ݹ��������
//	if (root == NULL)
//	{
//		return;
//	}
//	//����������
//	PreOrderBT(root->lch);
//	//������ڵ�����
//	printf("%c ", root->data);
//	//����������
//	PreOrderBT(root->rch);
//}
//
////�������
//void PostOrderBT(LinkBTree root)
//{
//	//�ݹ��������
//	if (root == NULL)
//	{
//		return;
//	}
//	//����������
//	PreOrderBT(root->lch);
//	//����������
//	PreOrderBT(root->rch);
//	//������ڵ�����
//	printf("%c ", root->data);
//}
//
//int main()
//{
//	LinkBTree root = NULL;
//	//���ڼ�¼��ǰ����������ӻ����Һ���
//	int flag;
//	int n;
//	char r;
//	scanf_s("%d", &n);
//	getchar();
//	scanf_s("%c", &r);
//	root = InitBTree(r);
//	char x;
//	char px;
//	for (int i = 1; i < n; i++)
//	{
//		getchar();
//		scanf_s("%c ", &x);
//		scanf_s("%c ", &px);
//		scanf_s("%d", &flag);
//		root = Insert(root, x, px, flag);
//	}
//	//levelOrderBT(root);
//	//PreOrderBT(root);
//	//InOrderBT(root);
//	PostOrderBT(root);
//	return 0;
//}

/*
9
A
B A 0
E A 1
C B 1
F E 1
D C 0
G F 0
H G 0
K G 1
*/