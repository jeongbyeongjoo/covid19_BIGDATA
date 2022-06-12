#pragma once 

#define INSERT 1
#define PRINT 2
#define QUIT 3
#define MONTH 1
#define ALL 2
#define BACK 3
#define REENTER 1
#define	RETURN 2

// [���׸� 5] : ����ü ���
typedef struct occurrence_status {
	char date[15];	//����
	int total;		//��(��)
	int domestic;	//�����߻�(��)
	int overseas;	//�ؿ�����(��)
	int death;		//���(��)
} STATUS;

void print_mainmenu(void); // [�� �׸� 2] : �Լ� ���
void print_submenu1(void);
void print_submenu2(void);
void insert_occurence_status(STATUS data[], int* p);
void print_occurence_status(STATUS data[], int* p);