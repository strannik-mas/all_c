#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"in_out.h"

void input(double xy[], int m, int i)
{
	int j;
	
	wprintf(L"Введите координаты %d-й точки \n", i); //для работы с юникодом
	for (j = 0; j < m; j++)
		do
		{
			printf("%c = ", 'x'+j); //вычисляется код x y и z
			fflush(stdin);
			
		//}while(scanf("%lf", &xy[j])!=1);
		}while(scanf("%lf", xy + j ) !=1 );
}

void print(const wchar_t *format, double s)
{
	wprintf(format, s);
}