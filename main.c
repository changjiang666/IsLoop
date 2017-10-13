#include "loop.h"
int main()
{
	LinkList L;
	Status i;
	char opp = 1;
	ElemType e;
	int find;
	int tmp;

	i = InitList(&L);
	printf("初始化L后：ListLength(L)=%d\n", ListLength(L));

	printf("\n1.创建有环链表（尾插法） \n2.创建无环链表（头插法） \n3.判断链表是否有环 \n0.退出 \n\n请选择你的操作：\n");
	while (opp != '0')
	{
		scanf_s("%c", &opp);
		switch (opp)
		{
		case '1':
			CreateListTail(&L, 10);
			printf("成功创建有环L(尾插法)\n");
			printf("\n");
			break;

		case '2':
			CreateListHead(&L, 10);
			printf("成功创建无环L(头插法)\n");
			printf("\n");
			break;

		case '3':
			printf("方法一: \n\n");
			if (HasLoop1(L))
			{
				printf("结论：链表有环\n\n\n");
			}
			else
			{
				printf("结论：链表无环\n\n\n");
			}

			printf("方法二：\n\n");
			if (HasLoop2(L))
			{
				printf("结论：链表有环\n\n\n");
			}
			else
			{
				printf("结论：链表无环\n\n\n");
			}
			printf("\n");
			break;

		case '0':
			exit(0);
		}
	}

}