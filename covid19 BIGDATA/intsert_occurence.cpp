#define _CRT_SECURE_NO_WARNINGS // [�� �׸� 8] : ���� �ҽ� ���� ���
#include <stdio.h>
#include <windows.h>
#include "covid19_bigdata.h"

void insert_occurence_status(STATUS data[], int* p) // p�� ������ ����ü�� ��ȣ�� �˷���
{
	int** q = &p; // [���׸� 6] : ������ Ȱ��

	system("cls");
	printf("\n���ڸ� �Է��ϼ���(ex. 2022-06-01) : ");
	scanf("%s", data[**q].date);
	printf("��(��)�� �Է��ϼ��� : ");
	scanf("%s", data[**q].total);
	printf("�����߻�(��)�� �Է��ϼ��� : ");
	scanf("%s", data[**q].domestic);
	printf("�ؿ�����(��)�� �Է��ϼ��� : ");
	scanf("%s", data[**q].overseas);
	printf("���(��)�� �Է��ϼ��� : ");
	scanf("%s", data[**q].death);
	(**q)++; // �ْ׹�ȣ
	system("cls");
}