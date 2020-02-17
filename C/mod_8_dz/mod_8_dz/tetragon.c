#include<stdio.h>
#include"geom.h"
#include"tetragon.h"
#include"in_out.h"
#define N 4
#define M 2 //размерность пространства
void tetragon(void)
{
	double S;
	double xy[N][M];
	int i;

	//ввод исходных данных
	for (i = 0; i < N; i++)
		input(xy[i], M, i+1);

	S = heron(		dist(xy[0], xy[1], M),
					dist(xy[2], xy[1], M),
					dist(xy[2], xy[0], M))
		+heron(		dist(xy[0], xy[2], M),
					dist(xy[2], xy[3], M),
					dist(xy[3], xy[0], M));
	
	print(L"\nПлощадь = %.3g\n\n", S);
}
