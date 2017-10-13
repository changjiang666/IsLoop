#include "loop.h"
#include <stdio.h>

/* 初始化带头结点的空链表 */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */

	if (!(*L)) /* 存储分配失败 */
		return ERROR;

	(*L)->next = NULL; /* 指针域为空 */

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;

	srand(time(0));                         /*  初始化随机数种子 */

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  建立一个带头结点的单链表 */

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;
		(*L)->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r = *L;                              /* r为指向尾部的结点 */

	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}

	r->next = (*L)->next->next;
}

// 比较步数的方法
int HasLoop1(LinkList L)
{
	LinkList cur1 = L->next;
	int pos1 = 0;
	while (cur1)
	{
		LinkList cur2 = L->next;
		int pos2 = 0;
		while (cur2)
		{
			if (cur2 == cur1)
			{
				if (pos2 == pos1)
					break;
				else
				{
					printf("环的位置在第%d个结点处。\n\n", pos2 + 1);
					return 1;       // 有环并返回1
				}
				
			}
			cur2 = cur2->next;
			++pos2;
		}
		cur1 = cur1->next;
		++pos1;
	}
	return 0;
}

// 利用快慢指针的方法
int HasLoop2(LinkList L)
{
	LinkList p = L, q = L; 
	for (; p && q && q->next; p = p->next, q = q->next->next)
	{
		printf("p:%d, q:%d \n", p->data, q->data);
		if (p == q)
			return 1;
	}
	return 0;
}