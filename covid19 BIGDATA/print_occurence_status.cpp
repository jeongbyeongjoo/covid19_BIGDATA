#define _CRT_SECURE_NO_WARNINGS // [�� �׸� 8] : ���� �ҽ� ���� ���
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

		print_submenu1(); // �޴� ���
		printf("��ȣ�� �����ϼ��� : ");
		scanf("%d", &select);

		switch (select)
		{
		case MONTH: // �Ѵ� ��� ���
			system("cls");
			printf("\nTo 2020-01-20 From 2022-06-06\n");
			printf(">>��/���� �Է��ϼ���(ex. 2022-05) : ");
			scanf("%s", n);

			for (int i = 0; i < *p; i++) // �Է� ���� �˻�
			{
				if (strncmp(data[i].date, n, 7) == 0) // �˸°� �Է� �� count�� 1�� ��ȯ
					count = 1;
			}
			if (count != 1) // �Է� ���� �� (count�� �״���� ��)
			{
				count = 0; // count �ʱ�ȭ
				system("cls");
				printf("\n�߸��� �����͸� �Է��Ͽ����ϴ�\n>>");
				Sleep(1000);
				system("cls");
				print_occurence_status(data, p); // ��ȯ �Լ� ȣ��
				return; // �Լ� ����
			}
			printf("\n|   ����   |   ��(��)  |  �����߻� |  �ؿ����� |  ���(��) |\n");
			printf("------------------------------------------------------------\n");
			for (int i = 0; i < *p; i++) //���� ����ü�� ��ȣ������ �ݺ�
			{
				if (strncmp(data[i].date, n, 7) == 0) // �������� �б�
				{
					if (strncmp(data[i].date, "2020-02", 7) == 0) // ���� 2020�� 2��
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
						printf("  ����(��) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					else if (strncmp(data[i].date, "2020-01", 7) == 0) // 2020�� 1�� 20�Ϻ��� ������ ����
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
						printf("  ����(��) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					else if (strncmp(data[i].date, "2022-06", 7) == 0) // 2022�� 6�� 6�ϱ��� ������ ����
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
						printf("  ����(��) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
						sum.total = 0;
						sum.domestic = 0;
						sum.overseas = 0;
						sum.death = 0;
						break;
					}
					strcpy(cpy, data[i].date);
					token = strtok(cpy, "-");
					token = strtok(NULL, "-"); // token�� Ȱ���� ���� �б�
					if (atoi(token) == 1 || atoi(token) == 3 || atoi(token) == 5 || atoi(token) == 7 || atoi(token) == 8 || atoi(token) == 10 || atoi(token) == 12)
						for (int j = i; j < i + 31; j++) // ������ ��¥�� 31�ϱ����� �� ���
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					else if (atoi(token) == 4 || atoi(token) == 6 || atoi(token) == 9 || atoi(token) == 11)
						for (int j = i; j < i + 30; j++) // ������ ��¥�� 30�ϱ����� �� ���
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					else if (atoi(token) == 2)
						for (int j = i; j < i + 28; j++) // ������ ��¥�� 28�ϱ����� �� ���
						{
							sum.total += data[j].total;
							sum.domestic += data[j].domestic;
							sum.overseas += data[j].overseas;
							sum.death += data[j].death;
							printf("%11sl%11d|%11d|%11d|%11d\n", data[j].date, data[j].total, data[j].domestic, data[j].overseas, data[j].death);
						}
					printf("------------------------------------------------------------\n");
					printf("  ����(��) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
					sum.total = 0;
					sum.domestic = 0;
					sum.overseas = 0;
					sum.death = 0;
					break;
				}
			}
			break;
		case ALL: // ��� ���
			printf("\n|   ����   |   ��(��)  |  �����߻� |  �ؿ����� |  ���(��) |\n");
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
			printf("  ����(��) l%11d|%11d|%11d|%11d\n", sum.total, sum.domestic, sum.overseas, sum.death);
			sum.total = 0;
			sum.domestic = 0;
			sum.overseas = 0;
			sum.death = 0;
			break;
		case BACK: // �������� ���ư���
			system("cls");
			return;
		default: // �Է� ���� ��
			system("cls");
			printf("\n�߸��� ��ȣ�� �Է��Ͽ����ϴ�\n>>");
			Sleep(1000);
			system("cls");
			break;
		}

		printf("\n");
		print_submenu2(); // �޴� ���
		printf("��ȣ�� �����Ͻÿ� : ");
		scanf("%d", &select);

		if (select == REENTER)
			;
		else if (select == RETURN) // REENTER = 1 (�������� ���ư���), RETURN = 2 (���θ޴��� ���ư���)
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("\n�߸��� ��ȣ�� �Է��Ͽ����ϴ�\n>>");
			Sleep(1000);
			system("cls");
		}
	}
}