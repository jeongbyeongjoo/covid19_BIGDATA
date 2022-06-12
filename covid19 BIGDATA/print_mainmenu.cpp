#include <stdio.h>


void print_mainmenu(void)
{
	const char* list[3] = { // [평가항목 6] : 포인터 활용
		"1. 현재 현황 추가",
		"2. 현재 현황 출력",
		"3. 종료"
	};

	printf("\n  MAIN MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("-----------------------\n");
}