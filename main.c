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
	printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));

	printf("\n1.�����л�����β�巨�� \n2.�����޻�����ͷ�巨�� \n3.�ж������Ƿ��л� \n0.�˳� \n\n��ѡ����Ĳ�����\n");
	while (opp != '0')
	{
		scanf_s("%c", &opp);
		switch (opp)
		{
		case '1':
			CreateListTail(&L, 10);
			printf("�ɹ������л�L(β�巨)\n");
			printf("\n");
			break;

		case '2':
			CreateListHead(&L, 10);
			printf("�ɹ������޻�L(ͷ�巨)\n");
			printf("\n");
			break;

		case '3':
			printf("����һ: \n\n");
			if (HasLoop1(L))
			{
				printf("���ۣ������л�\n\n\n");
			}
			else
			{
				printf("���ۣ������޻�\n\n\n");
			}

			printf("��������\n\n");
			if (HasLoop2(L))
			{
				printf("���ۣ������л�\n\n\n");
			}
			else
			{
				printf("���ۣ������޻�\n\n\n");
			}
			printf("\n");
			break;

		case '0':
			exit(0);
		}
	}

}