#define _CRT_SECURE_NO_WARNINGS // [�� �׸� 8] : ���� �ҽ� ���� ���
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "covid19_bigdata.h"

void print_occurence_status(STATUS data[], int* p)
{
	char n[15], cpy[15]; // [���׸� 6] : ������ Ȱ��
	int select;
	char* token;

	while (1)
	{
		system("cls");

		print_submenu1(); // �޴� ���
		printf("��ȣ�� �����ϼ��� : ");
		scanf("%d", &select);

		switch (select)
		{
		case MONTH: // �Ѵ� ��� ���
			system("cls");
			printf("\nTo 2020-01-20 From 2022-06-01\n");
			printf(">>��/���� �Է��ϼ���(ex. 2022-05) : ");
			scanf("%s", n);

			printf("\n|   ����   |   ��(��)  |  �����߻� |  �ؿ����� |  ���(��) |\n");
			printf("------------------------------------------------------------\n");
			for (int i = 0; i < *p; i++) //���� ����ü�� ��ȣ������ �ݺ�
			{
				if (strncmp(data[i].date, n, 7) == 0) // �������� �б�
				{
					if (strncmp(data[i].date, "2020-02", 7) == 0) // ���� 2020�� 2��
					{
						for (int j = i; j < i + 29; j++)
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						break;
					}
					else if (strncmp(data[i].date, "2020-01", 7) == 0) // 2020�� 1�� 20�Ϻ��� ������ ����
					{
						for (int j = i; j < i + 12; j++)
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						break;
					}
					else if (strncmp(data[i].date, "2022-06", 7) == 0) // 2022�� 6�� 1�ϱ��� ������ ����
					{
						for (int j = i; j < *p; j++)
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						break;
					}
					strcpy(cpy, data[i].date);
					token = strtok(cpy, "-");
					token = strtok(NULL, "-"); // token�� Ȱ���� ���� �б�
					if (atoi(token) == 1 || atoi(token) == 3 || atoi(token) == 5 || atoi(token) == 7 || atoi(token) == 8 || atoi(token) == 10 || atoi(token) == 12)
						for (int j = i; j < i + 31; j++) // ������ ��¥�� 31�ϱ����� �� ���
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
					else if (atoi(token) == 4 || atoi(token) == 6 || atoi(token) == 9 || atoi(token) == 11)
						for (int j = i; j < i + 30; j++) // ������ ��¥�� 30�ϱ����� �� ���
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
					else if (atoi(token) == 2)
						for (int j = i; j < i + 28; j++) // ������ ��¥�� 28�ϱ����� �� ���
							printf("%11sl%11s|%11s|%11s|%11s\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
					printf("------------------------------------------------------------\n");
					break;
				}
			}
			break;
		case ALL: // ��� ���
			printf("\n|   ����   |   ��(��)  |  �����߻� |  �ؿ����� |  ���(��) |\n");
			printf("------------------------------------------------------------\n");
			for (int i = 1; i < *p; i++)
			{
				printf("%11sl%11s|%11s|%11s|%11s\n", data[i].date, data[i].total, data[i].domestic, data[i].overseas, data[i].death);
			}
			break;
		case BACK: // �������� ���ư���
			system("cls");
			return;
		default: // �Է� ���� ��
			printf("-----------------------\n�߸��� ��ȣ�� �Է��Ͽ����ϴ�\n");
			break;
		}

		printf("\n");
		print_submenu2(); // �޴� ���
		printf("��ȣ�� �����Ͻÿ� : ");
		scanf("%d", &select);

		if (select == RETURN) // REENTER = 1 (�������� ���ư���), RETURN = 2 (���θ޴��� ���ư���)
		{
			system("cls");
			break;
		}
	}
}