#define _CRT_SECURE_NO_WARNINGS // [평가 항목 8] : 다중 소스 파일 사용
#include <stdio.h>
#include <windows.h>
#include "covid19_bigdata.h"

void insert_occurence_status(STATUS data[], int* p) // p는 현재의 구조체의 번호를 알려줌
{
	int** q = &p; // [평가항목 6] : 포인터 활용

	system("cls");
	printf("\n일자를 입력하세요(ex. 2022-06-01) : ");
	scanf("%s", data[**q].date);
	printf("계(명)을 입력하세요 : ");
	scanf("%s", data[**q].total);
	printf("국내발생(명)을 입력하세요 : ");
	scanf("%s", data[**q].domestic);
	printf("해외유입(명)을 입력하세요 : ");
	scanf("%s", data[**q].overseas);
	printf("사망(명)을 입력하세요 : ");
	scanf("%s", data[**q].death);
	(**q)++; // 다믕번호
	system("cls");
}