#pragma once 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

//data
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

//operations
/* ��ʼ����ͷ���Ŀ����� */
Status InitList(LinkList *L);

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L);

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n);

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n);

// �Ƚϲ����ķ���
int HasLoop1(LinkList L);

// ���ÿ���ָ��ķ���
int HasLoop2(LinkList L);





