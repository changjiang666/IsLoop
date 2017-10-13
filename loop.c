#include "loop.h"
#include <stdio.h>

/* ��ʼ����ͷ���Ŀ����� */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */

	if (!(*L)) /* �洢����ʧ�� */
		return ERROR;

	(*L)->next = NULL; /* ָ����Ϊ�� */

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* pָ���һ����� */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;

	srand(time(0));                         /*  ��ʼ����������� */

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  ����һ����ͷ���ĵ����� */

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r = *L;                              /* rΪָ��β���Ľ�� */

	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}

	r->next = (*L)->next->next;
}

// �Ƚϲ����ķ���
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
					printf("����λ���ڵ�%d����㴦��\n\n", pos2 + 1);
					return 1;       // �л�������1
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

// ���ÿ���ָ��ķ���
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