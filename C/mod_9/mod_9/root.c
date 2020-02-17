#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<locale.h> 
#include<math.h>

int roots (double a, double b, double c, //Bxo���� ������
			double *x1, double *x2)		//�������� ������
{
	if(a!=0)

	{

		double d = b*b - 4*a*c; 
		if(d<0)
			return 0; 
		if(d>0)
		{
			d = sqrt(d);
			*x1 = (-b+d)/(2*a);
			*x2 = (-b-d)/(2*a);
			return 2;
		}
		*x1 = *x2 = -b/(2*a);
		return 1;
	}
	else if(b != 0)
	{
		*x1 = -c/b;
		return -1;
	}
	else return -2;
}

int main()
{
	double a,b,c,x1,x2;
	setlocale(LC_CTYPE,".866"); 
	do 
	{
		fflush(stdin);
		wprintf (L"������� ��������� a*x^2+b*x+c=0\n" 
				 L"������� ������������: ");
	}while(scanf("%lf %lf %lf", &a,&b,&c)!=3);
	
	switch(roots(a,b,c,&x1,&x2))
	{
	case 2:
		wprintf(L"����� ��������� %g *x^2 + %g * x + %g \nx1 = %g, x2 = %g\n", a, b, c, x1, x2);
			break; 
	case 1:
		wprintf(L"����� ������� xl = x2 = %g\n",x1); 
		break;
	case 0:
		wprintf(L"������ ���\n");
		break;
	case -1:
		wprintf(L"��� �������� ���������: x = %g\n", x1);
		break;
	case -2:
		wprintf(L"��� ������ �� ���������\n");
		break;
	}
}