/* [평가항목 1] : 과제 설명

	컴퓨터프로그래밍 평과과제 (배점 25점)
	학과 : 컴퓨터공학부
	학번 : 202203141
	이름 : 정병주

	과제 주제 : covid-19 관련 처리를 하는 프로그램을 구현

	프로그램 설명 : 'covid19 bigdata' 프로그램은 대한민국 정부가 공식으로 만든 '코로나바이러스감염증-19' 정식 홈페이지에서 '2020.01.20부터
	2022.06.06까지의 코로나바이러스 확진 환자 발생 현황이 기록된 엑셀 자료를 다운로드하여 텍스트 자료로 변환한 후 텍스트 자료를 바탕으로 사
	용자에게 당시의 코로나바이러스 발생 현황을 보여주는 프로그램입니다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "covid19_bigdata.h"

int main(void)
{
	STATUS data[1000]; // [평가항목 3] : 배열 사용
	FILE* fp;
	char buffer[100];
	char* token;
	int select, count = 0; // 생성될 구조체의 번호를 알려줄 count변수 생성
	int* p = &count; // [평가항목 4] : 포인터 사용

	if ((fp = fopen("코로나바이러스감염증-19_확진환자_발생현황_220606.txt", "r")) == NULL) // [평가항목 7] : 파일 입출력
	{
		fprintf(stderr, "파일 코로나바이러스감염증-19_확진환자_발생현황_220601.txt을 열 수 없습니다."); // 오류 발생 시 문구 출력
		exit(1);
	}

	fgets(buffer, 100, fp); // 첫줄 삭제 (일자, 계(명), 국내발생(명), 해외유입(명), 사망(명))

	for (int i = 0; feof(fp) == NULL; i++) //텍스트 파일 구조체 배열에 담기
	{
		fgets(buffer, 100, fp);
		token = strtok(buffer, " \t\n");
		strcpy(data[i].date, token);
		token = strtok(NULL, " \t\n");
		data[i].total = atoi(token);
		token = strtok(NULL, " \t\n");
		data[i].domestic = atoi(token);
		token = strtok(NULL, " \t\n");
		data[i].overseas = atoi(token);
		token = strtok(NULL, " \t\n");
		data[i].death = atoi(token);
		*p += 1;
	}

	while (1)
	{
		print_mainmenu(); // 메뉴 출력
		printf("번호를 선택하시오 : ");
		scanf("%d", &select);

		switch (select)
		{
		case INSERT: // 발생 현황 추가
			insert_occurence_status(data, p);
			break;
		case PRINT: // 발생 현황 출력
			print_occurence_status(data, p);
			break;
		case QUIT: // 종료
			return 0;
		default: // 입력 오류 시
			system("cls");
			printf("\n잘못된 번호를 입력하였습니다\n>>");
			Sleep(1000);
			system("cls");
			break;
		}
	}

	fclose(fp);

	return 0;
}