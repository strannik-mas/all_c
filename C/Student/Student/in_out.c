#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"data.h"
#include"in_out.h"
int input(student *pstud, int nstud)
{
	
	student * const x = malloc((N-nstud)*sizeof(student)); //для проверки выделения памяти
	int res, i = 0;
	do
	{
		printf("\nВведи фамилию студня\n");
		fflush(stdin);
	}while (scanf("%s", x->last_name)==0);
	do
	{
		
		printf("\nВведи оценку за %d экзамен студня\n", i+1);
		fflush(stdin);
	}while ((scanf("%d", &x->grade[i])!=1 || x->grade[i]<1 || x->grade[i]>5) || ++i<MAXGRADES);
	res = add_student(x);
	return res;
}

int output(student *pstud, int nstud)
{
	int i, j;
	for (i = 0; i < nstud; i++)
	{
		fprintf(stdout, "%s", pstud[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(stdout, "%2d"/*не приклеится*/, pstud[i].grade[j]);
		}
		fprintf(stdout,"\n");
	}
	return nstud;
}