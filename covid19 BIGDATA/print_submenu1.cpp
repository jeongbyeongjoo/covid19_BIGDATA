#include <stdio.h>

void print_submenu1(void)
{
	const char* list[3] = { // [평가항목 6] : 포인터 활용
		"2-1. 월별 통계 출력",
		"2-2. 모두 출력",
		"2-3. 이전으로 돌아가기"
	};

	printf("\n  MENU");
	printf("\n-----------------------\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("-----------------------\n");
}