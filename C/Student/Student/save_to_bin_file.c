#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"data.h"
#include"save_to_bin_file.h"

int save(student *pstud, int nstud)
{

	FILE *file = fopen("stud.dat", "wb");
	if(!file) {
		perror("stud.dat");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}
	
	fwrite(&nstud, sizeof (int), 1 , file);	//���������� ����� ������� � ����
	fwrite(pstud, sizeof (student), nstud , file);

	fclose(file);
	return nstud;
}