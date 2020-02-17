#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"data.h"
#include"load.h"
#include"in_out.h"

int load(student *pstud, int nstud)
{
	student * const q = malloc(nstud*sizeof(student));
	int k;
	FILE *file = fopen("stud.dat", "rb");
	if(!file) {
		perror("stud.dat");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}
	
	fread(&k, sizeof (int), 1 , file);			//���������� ����� ������� �� �����
	if(k>0 && k<=nstud)
	{
		fread(q, sizeof (student), k , file);
		output(q, k);
	}else k=0;
	fclose(file);
	
	return k;
}