#include <stdio.h>

void print_submenu2(void)
{
	const char* list[2] = { // [평가항목 6] : 포인터 활용
	"1. 이전으로 돌아가기",
	"2. 메인메뉴로 돌아가기",
	};

	printf("\n  MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("-----------------------\n");
}