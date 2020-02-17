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
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}
	
	fwrite(&nstud, sizeof (int), 1 , file);	//записываем число записей в файл
	fwrite(pstud, sizeof (student), nstud , file);

	fclose(file);
	return nstud;
}