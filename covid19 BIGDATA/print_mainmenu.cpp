#include <stdio.h>


void print_mainmenu(void)
{
	const char* list[3] = { // [���׸� 6] : ������ Ȱ��
		"1. ���� ��Ȳ �߰�",
		"2. ���� ��Ȳ ���",
		"3. ����"
	};

	printf("\n  MAIN MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("-----------------------\n");
}