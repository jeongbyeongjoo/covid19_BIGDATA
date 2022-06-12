/* [���׸� 1] : ���� ����

	��ǻ�����α׷��� ������� (���� 25��)
	�а� : ��ǻ�Ͱ��к�
	�й� : 202203141
	�̸� : ������

	���� ���� : covid-19 ���� ó���� �ϴ� ���α׷��� ����

	���α׷� ���� : 'covid19 bigdata' ���α׷��� ���ѹα� ���ΰ� �������� ���� '�ڷγ����̷���������-19' ���� Ȩ���������� '2020.01.20����
	2022.06.06������ �ڷγ����̷��� Ȯ�� ȯ�� �߻� ��Ȳ�� ��ϵ� ���� �ڷḦ �ٿ�ε��Ͽ� �ؽ�Ʈ �ڷ�� ��ȯ�� �� �ؽ�Ʈ �ڷḦ �������� ��
	���ڿ��� ����� �ڷγ����̷��� �߻� ��Ȳ�� �����ִ� ���α׷��Դϴ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "covid19_bigdata.h"

int main(void)
{
	STATUS data[1000]; // [���׸� 3] : �迭 ���
	FILE* fp;
	char buffer[100];
	char* token;
	int select, count = 0; // ������ ����ü�� ��ȣ�� �˷��� count���� ����
	int* p = &count; // [���׸� 4] : ������ ���

	if ((fp = fopen("�ڷγ����̷���������-19_Ȯ��ȯ��_�߻���Ȳ_220606.txt", "r")) == NULL) // [���׸� 7] : ���� �����
	{
		fprintf(stderr, "���� �ڷγ����̷���������-19_Ȯ��ȯ��_�߻���Ȳ_220601.txt�� �� �� �����ϴ�."); // ���� �߻� �� ���� ���
		exit(1);
	}

	fgets(buffer, 100, fp); // ù�� ���� (����, ��(��), �����߻�(��), �ؿ�����(��), ���(��))

	for (int i = 0; feof(fp) == NULL; i++) //�ؽ�Ʈ ���� ����ü �迭�� ���
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
		print_mainmenu(); // �޴� ���
		printf("��ȣ�� �����Ͻÿ� : ");
		scanf("%d", &select);

		switch (select)
		{
		case INSERT: // �߻� ��Ȳ �߰�
			insert_occurence_status(data, p);
			break;
		case PRINT: // �߻� ��Ȳ ���
			print_occurence_status(data, p);
			break;
		case QUIT: // ����
			return 0;
		default: // �Է� ���� ��
			system("cls");
			printf("\n�߸��� ��ȣ�� �Է��Ͽ����ϴ�\n>>");
			Sleep(1000);
			system("cls");
			break;
		}
	}

	fclose(fp);

	return 0;
}