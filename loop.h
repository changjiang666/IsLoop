#pragma once 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

//data
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

//operations
/* 初始化带头结点的空链表 */
Status InitList(LinkList *L);

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n);

// 比较步数的方法
int HasLoop1(LinkList L);

// 利用快慢指针的方法
int HasLoop2(LinkList L);





