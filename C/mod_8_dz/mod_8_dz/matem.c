#include<math.h>
#include"geom.h"
double dist(double *xy1, double *xy2, int m)
{
	double s=0.0;
	while(m--)
		s += pow(*xy1++ - *xy2++,m);
	/*
	int j;
	for (j=0; j<m; ++j)
		s += pow(xy1[j]-xy2[j],m);
	*/
	return sqrt(s);
}

double heron(double a, double b, double c)
{
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}