#define _CRT_SECURE_NO_WARNINGS // [평가 항목 8] : 다중 소스 파일 사용
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "covid19_bigdata.h"

void insert_occurence_status(STATUS data[], int* p) // p는 현재의 구조체의 번호를 알려줌
{
	int** q = &p; // [평가항목 6] : 포인터 활용
	char* token;
	char s[11];

	system("cls");
	printf("\n일자를 입력하세요(ex. 2022-06-06) : ");
	scanf("%s", data[**q].date);
	for (int i = 0; i < **q; i++) // 입력 오류 시 1
		if (strcmp(data[**q].date, data[i].date) == 0)
		{
			system("cls");
			printf("\n잘못된 데이터를 입력하였습니다\n>>( 2022-06-06 이후부터 입력 가능 )");
			Sleep(1000);
			system("cls");
			insert_occurence_status(data, p); // 순환 함수 호출
			return; // 함수 종료
		}
	strcpy(s, data[**q].date);
	token = strtok(s, "-");
	if (strcmp(token, "2022") != 0) // 입력 오류 시 2
	{
		system("cls");
		printf("\n잘못된 데이터를 입력하였습니다\n>>( 2022-06-06 이후부터 입력 가능 )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // 순환 함수 호출
		return; // 함수 종료
	}
	token = strtok(NULL, "-"); 
	if (1>atoi(token)||12<atoi(token)) //입력 오류 시 3
	{
		system("cls");
		printf("\n잘못된 데이터를 입력하였습니다\n>>( 2022-06-06 이후부터 입력 가능 )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // 순환 함수 호출
		return; // 함수 종료
	}
	token = strtok(NULL, "-");
	if (1 > atoi(token) || 32 < atoi(token)) // 입력 오류 시 4 (코드가 길어지므로 모든달이 31일까지 있다고 가정)
	{
		system("cls");
		printf("\n잘못된 데이터를 입력하였습니다\n>>( 2022-06-06 이후부터 입력 가능 )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // 순환 함수 호출
		return; // 함수 종료
	}
	printf("계(명)을 입력하세요 : ");
	scanf("%d", &data[**q].total);
	printf("국내발생(명)을 입력하세요 : ");
	scanf("%d", &data[**q].domestic);
	printf("해외유입(명)을 입력하세요 : ");
	scanf("%d", &data[**q].overseas);
	printf("사망(명)을 입력하세요 : ");
	scanf("%d", &data[**q].death);
	(**q)++; // 다믕번호
	system("cls");
}