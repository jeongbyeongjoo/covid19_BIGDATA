#include <stdio.h>

void print_submenu2(void)
{
	const char* list[2] = { // [���׸� 6] : ������ Ȱ��
	"1. �������� ���ư���",
	"2. ���θ޴��� ���ư���",
	};

	printf("\n  MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("-----------------------\n");
}