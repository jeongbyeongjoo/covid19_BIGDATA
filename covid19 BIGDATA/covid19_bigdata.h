#pragma once 

#define INSERT 1
#define PRINT 2
#define QUIT 3
#define MONTH 1
#define ALL 2
#define BACK 3
#define REENTER 1
#define	RETURN 2

// [평가항목 5] : 구조체 사용
typedef struct occurrence_status {
	char date[15];	//일자
	int total;		//계(명)
	int domestic;	//국내발생(명)
	int overseas;	//해외유입(명)
	int death;		//사망(명)
} STATUS;

void print_mainmenu(void); // [평가 항목 2] : 함수 사용
void print_submenu1(void);
void print_submenu2(void);
void insert_occurence_status(STATUS data[], int* p);
void print_occurence_status(STATUS data[], int* p);