#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MYDEBUG

#ifndef MYDEBUG
#define DUMP(val_1, val_2, val_3);
#else
#define DUMP(val_1, val_2, val_3) printf(#val_1"=%d\t"#val_2"=%d\t"#val_3"=%d\n",val_1, val_2, val_3);
#endif

#define DESCRIMINANT(a1, b1, c1) ( (b1*b1 - 4*a1*c1) >= 0 ? 1 : 0)

int main()
{
	int a,b,c;
	double x1, x2, descr;
	system("chcp 1251 > nul");

	do
	{
		printf("введи коэффициенты квадратного уравнения\n");
		fflush(stdin);
	}while (scanf("%d %d %d", &a, &b, &c) !=3 && printf ("нужно вводить только целые числа\n"));

	//==================================================
	DUMP(a,b,c);
	//printf("Значение дискриминанта равно %d\n", DESCRIMINANT(a,b,c));
	if (DESCRIMINANT(a,b,c))
	{
		descr = b*b - 4*a*c;
		x1 = (-b + sqrt(descr))/(2*a);
		x2 = (-b - sqrt(descr))/(2*a);
	}
		//==============================================
	if (!DESCRIMINANT(a,b,c))
		printf("корней на множестве действительных чисел нет\n"); 
	else printf("Первый корень равен %lf\nВторой корень равен %lf\n", x1,x2);

}