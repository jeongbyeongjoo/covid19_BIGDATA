#define _CRT_SECURE_NO_WARNINGS // [�� �׸� 8] : ���� �ҽ� ���� ���
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "covid19_bigdata.h"

void insert_occurence_status(STATUS data[], int* p) // p�� ������ ����ü�� ��ȣ�� �˷���
{
	int** q = &p; // [���׸� 6] : ������ Ȱ��
	char* token;
	char s[11];

	system("cls");
	printf("\n���ڸ� �Է��ϼ���(ex. 2022-06-06) : ");
	scanf("%s", data[**q].date);
	for (int i = 0; i < **q; i++) // �Է� ���� �� 1
		if (strcmp(data[**q].date, data[i].date) == 0)
		{
			system("cls");
			printf("\n�߸��� �����͸� �Է��Ͽ����ϴ�\n>>( 2022-06-06 ���ĺ��� �Է� ���� )");
			Sleep(1000);
			system("cls");
			insert_occurence_status(data, p); // ��ȯ �Լ� ȣ��
			return; // �Լ� ����
		}
	strcpy(s, data[**q].date);
	token = strtok(s, "-");
	if (strcmp(token, "2022") != 0) // �Է� ���� �� 2
	{
		system("cls");
		printf("\n�߸��� �����͸� �Է��Ͽ����ϴ�\n>>( 2022-06-06 ���ĺ��� �Է� ���� )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // ��ȯ �Լ� ȣ��
		return; // �Լ� ����
	}
	token = strtok(NULL, "-"); 
	if (1>atoi(token)||12<atoi(token)) //�Է� ���� �� 3
	{
		system("cls");
		printf("\n�߸��� �����͸� �Է��Ͽ����ϴ�\n>>( 2022-06-06 ���ĺ��� �Է� ���� )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // ��ȯ �Լ� ȣ��
		return; // �Լ� ����
	}
	token = strtok(NULL, "-");
	if (1 > atoi(token) || 32 < atoi(token)) // �Է� ���� �� 4 (�ڵ尡 ������Ƿ� ������ 31�ϱ��� �ִٰ� ����)
	{
		system("cls");
		printf("\n�߸��� �����͸� �Է��Ͽ����ϴ�\n>>( 2022-06-06 ���ĺ��� �Է� ���� )");
		Sleep(1000);
		system("cls");
		insert_occurence_status(data, p); // ��ȯ �Լ� ȣ��
		return; // �Լ� ����
	}
	printf("��(��)�� �Է��ϼ��� : ");
	scanf("%d", &data[**q].total);
	printf("�����߻�(��)�� �Է��ϼ��� : ");
	scanf("%d", &data[**q].domestic);
	printf("�ؿ�����(��)�� �Է��ϼ��� : ");
	scanf("%d", &data[**q].overseas);
	printf("���(��)�� �Է��ϼ��� : ");
	scanf("%d", &data[**q].death);
	(**q)++; // �ْ׹�ȣ
	system("cls");
}