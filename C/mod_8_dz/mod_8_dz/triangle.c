#include<stdio.h>
#include"geom.h"
#include"triangle.h"
#include"in_out.h"
#define N 3
#define M 2 //����������� ������������
void triangle(void)
{
	double S;
	double xy[N][M];
	int i;

	//���� �������� ������
	for (i = 0; i < N; i++)
		input(xy[i], M, i+1);

	S = heron(dist(xy[0], xy[1], M),
					dist(xy[2], xy[1], M),
					dist(xy[2], xy[0], M));
	
	print(L"\n������� = %.3g\n\n", S);
}
