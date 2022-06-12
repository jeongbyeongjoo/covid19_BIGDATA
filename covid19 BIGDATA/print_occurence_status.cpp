#define _CRT_SECURE_NO_WARNINGS // [평가 항목 8] : 다중 소스 파일 사용
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "covid19_bigdata.h"

void print_occurence_status(STATUS data[], int* p)
{
	STATUS sum = { 0 };
	char n[15], cpy[15];
	int select, count = 0;
	char* token;

	while (1)
	{
		system("cls");

		print_submenu1(); // 메뉴 출력
		printf("번호를 선택하세요 : ");
		scanf("%d", &select);

		switch (select)
		{
		case MONTH: // 한달 통계 출력
			system("cls");
			printf("\nTo 2020-01-20 From 2022-06-06\n");
			printf(">>년/월를 입력하세요(ex. 2022-05) : ");
			scanf("%s", n);

			for (int i = 0; i < *p; i++) // 입력 오류 검사
			{
				if (strncmp(data[i].date, n, 7) == 0) // 알맞게 입력 시 count를 1로 전환
					count = 1;
			}
			if (count != 1) // 입력 오류 시 (count가 그대로일 때)
			{
				count = 0; // count 초기화
				system("cls");
				printf("\n잘못된 데이터를 입력하였습니다\n>>");
				Sleep(1000);
				system("cls");
				print_occurence_status(data, p); // 순환 함수 호출
				return; // 함수 종료
			}
			printf("\n|   일자   |   계(명)  |  국내발생 |  해외유입 |  사망(명) |\n");
			printf("------------------------------------------------------------\n");
			for (int i = 0; i < *p; i++) //현재 구조체의 변호까지만 반복
			{
				if (strncmp(data[i].date, n, 7) == 0) // 월까지만 읽기
				{
					if (strncmp(data[i].date, "2020-02", 7) == 0) // 윤년 2020년 2월
					{
						for (int j = i; j < i + 29; j++)
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
						printf("------------------------------------------------------------\n");
						printf("  누적(명) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					else if (strncmp(data[i].date, "2020-01", 7) == 0) // 2020년 1월 20일부터 데이터 존재
					{
						for (int j = i; j < i + 12; j++)
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
						printf("------------------------------------------------------------\n");
						printf("  누적(명) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					else if (strncmp(data[i].date, "2022-06", 7) == 0) // 2022년 6월 6일까지 데이터 존재
					{
						for (int j = i; j < *p; j++)
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
						printf("------------------------------------------------------------\n");
						printf("  누적(명) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					strcpy(cpy, data[i].date);
					token = strtok(cpy, "-");
					token = strtok(NULL, "-"); // token을 활용해 월만 읽기
					if (atoi(token) == 1 || atoi(token) == 3 || atoi(token) == 5 || atoi(token) == 7 || atoi(token) == 8 || atoi(token) == 10 || atoi(token) == 12)
						for (int j = i; j < i + 31; j++) // 마지막 날짜가 31일까지인 달 출력
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					else if (atoi(token) == 4 || atoi(token) == 6 || atoi(token) == 9 || atoi(token) == 11)
						for (int j = i; j < i + 30; j++) // 마지막 날짜가 30일까지인 달 출력
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					else if (atoi(token) == 2)
						for (int j = i; j < i + 28; j++) // 마지막 날짜가 28일까지인 달 출력
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					printf("------------------------------------------------------------\n");
					printf("  누적(명) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
					sum.total = 0;
					sum.domestic = 0;
					sum.overseas = 0;
					sum.death = 0;
					break;
				}
			}
			break;
		case ALL: // 모두 출력
			printf("\n|   일자   |   계(명)  |  국내발생 |  해외유입 |  사망(명) |\n");
			printf("------------------------------------------------------------\n");
			for (int i = 1; i < *p; i++)
			{
				sum.total += data[i].total;
				sum.domestic += data[i].domestic;
				sum.overseas += data[i].overseas;
				sum.death += data[i].death;
				printf("%11sl%11d|%11d|%11d|%11d\n", data[i].date, data[i].total, data[i].domestic, data[i].overseas, data[i].death);
			}
			printf("------------------------------------------------------------\n");
			printf("  누적(명) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
			sum.total = 0;
			sum.domestic = 0;
			sum.overseas = 0;
			sum.death = 0;
			break;
		case BACK: // 이전으로 돌아가기
			system("cls");
			return;
		default: // 입력 오류 시
			system("cls");
			printf("\n잘못된 번호를 입력하였습니다\n>>");
			Sleep(1000);
			system("cls");
			break;
		}

		printf("\n");
		print_submenu2(); // 메뉴 출력
		printf("번호를 선택하시오 : ");
		scanf("%d", &select);

		if (select == REENTER)
			;
		else if (select == RETURN) // REENTER = 1 (이전으로 돌아가기), RETURN = 2 (메인메뉴로 돌아가기)
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("\n잘못된 번호를 입력하였습니다\n>>");
			Sleep(1000);
			system("cls");
		}
	}
}