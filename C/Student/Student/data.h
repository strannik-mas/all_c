#ifndef DATA_H
#define DATA_H
#define N 8
#define MAXLEN		32
#define MAXGRADES	 3

typedef struct{
	char last_name[MAXLEN];
	int grade[MAXGRADES];
} student;

extern student *pstud;
extern int nstud;				//текущее количество студентов, сколько сейчас обрабатывается

int add_student(student *input_stud);
#endif