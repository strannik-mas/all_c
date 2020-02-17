//Площадь треугольника, заданного вершинами
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<locale.h>
#define N 3
#define M 2 //размерность пространства
//прототипы (определения)
//расстояние между 2 точками
double dist(double xy1[], double xy2[], int m);
//площадь треуг-ка
double heron(double, double, double);

//печать ответа
void print(const wchar_t format[], double);

//ввод данных
void input(double xy[], int m, int i);

int main()
{
	double xy[N][M];
	// x1,y1,x2,y2,x3,y3,
	double	a,b,c,
			S; 
	int i;
	setlocale(LC_CTYPE, ".866");
	//ввод данных
	for (i = 0; i < N; i++)
		input(xy[i], M, i+1);
/*
	wprintf(L"Введите координаты 3-х вершин -> "); //для работы с юникодом
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
*/
	a = dist(xy[0], xy[1], M);
	b = dist(xy[2], xy[1], M);
	c = dist(xy[2], xy[0], M);
	
	S = heron(a,b,c);

	print(L"\nПлощадь = %.3g\n\n", S);

	return 0;
}

double dist(double xy1[], double xy2[], int m)
{
	double s=0.0;
	int j;
	for (j=0; j<m; ++j)
		s += pow(xy1[j]-xy2[j],m);
	return sqrt(s);
}

double heron(double a, double b, double c)
{
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void print(const wchar_t format[], double s)
{
	wprintf(format, s);
}

void input(double xy[], int m, int i)
{
	int j;
	wprintf(L"Введите координаты %d-й точки \n", i); //для работы с юникодом
	for (j = 0; j < m; j++)
		do
		{
			printf("%c = ", 'x'+j); //вычисляется код x y и z
			fflush(stdin);
			
		}while(scanf("%lf", &xy[j])!=1);
}