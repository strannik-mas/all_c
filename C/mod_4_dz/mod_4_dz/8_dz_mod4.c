#include<stdio.h>
#include<locale.h>

#define FINAL_DAY	10
#define START_DIST	10
#define FINAL_DIST	20
#define TOTAL_DIST	100
#define PERCENT		10
#define FACTOR		(100+PERCENT)/100.0

#define MYDEBUG

#ifndef MYDEBUG
#define DUMP(ival, fval);
#else
#define DUMP(ival, fval) printf(#ival"=%d\t"#fval"=%f\n",ival,fval);
#endif

int main()
{
	double x, //ежедневный пробег
		s;		//суммарный пробег
	int n;
	setlocale(LC_CTYPE, ".866");
	for(n=1, x=START_DIST; n<FINAL_DAY; ++n, x*=FACTOR)
		DUMP(n,x);
	wprintf(L"В %d-й день спортсмен пробежал %.3f км \n\n",n,x);
	for(n=1, x=START_DIST; x<FINAL_DIST; ++n, x*=FACTOR)
		DUMP(n,x);
	wprintf(L"В %d-й день спортсмен пробежал %.3f км \n\n",n,x);
	for(n=1, s=x=START_DIST; s<TOTAL_DIST; ++n, s += x*=FACTOR)
		DUMP(n,x);
	wprintf(L"В %d-й день спортсмен пробежал %.3f км \n\n",n,x);
}