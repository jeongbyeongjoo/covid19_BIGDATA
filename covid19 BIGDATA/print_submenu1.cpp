#include <stdio.h>

void print_submenu1(void)
{
	const char* list[3] = { // [���׸� 6] : ������ Ȱ��
		"2-1. ���� ��� ���",
		"2-2. ��� ���",
		"2-3. �������� ���ư���"
	};

	printf("\n  MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("-----------------------\n");
}