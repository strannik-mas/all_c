#include<stdlib.h>
#include<stdio.h>
#include"data.h"


student group[] = 
	{
		{"Ivanov",			{5,4,4}},
		{"Petrashevsky",	{4,3,4}},
		{"Kim",				{5,3,5}},
		{"Pupkin",			{4,2,3}},
		{"Kuzin",			{5,5,5}}
	};

int nstud = 5, i;

student *pstud = group;

int add_student(student *input_stud)
{
	//добавляет только одного студента - остальные удаляются
	pstud = input_stud;
	
	return nstud = 1;
}

