#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c, d, e, f;
	int r1, r2;
	char sim;
	//������ �������� �� ��� ����������
	int leap;
	system("chcp 1251 > nul");
	//������ �� ������� � �������� ��� ����
	printf("Enter time in format dd.mm.yyyy\n");
	scanf_s("%2d.%2d.%4d\n%2d.%2d.%4d", &a,&b,&c,&d,&e,&f) == 6
		&& a>0 && a<=31 
		&& b>=1 && b<=12 
		&& c>=1 && c<=2016
		&& d>0 && d<=31 
		&& e>0 && e<=12 
		&& f>=1 && f<=2016 
		&& printf("���� ������� �������.\n%02d.%02d.%04d\n%02d.%02d.%04d\n", a,b,c,d,e,f)
		|| printf("Invalid time format!\n");

	/*
yyyymmdd <>

	*/
	r1 = c*10000 + b*100 +a;
	r2 = f*10000 + e*100 +d;
//����� ����������� ������: (�� ����� � ������� ����� 5 ���� - 2� 5�� = 32)
	r1 = c << 9 | b<< 5 |a;
	r2 = f << 9 | e<< 5 |d;
	sim = r1>r2 ? '>' : r1<r2 ? '<' : '=';
	printf("%02d.%02d.%04d %c %02d.%02d.%04d\n",
		a,b,c,
		//����� ���:
		/*
		c>f || c==f && (b>e || b==e && a>d)
		? '>'
		: c==f && b==e && a==d
		? '='
		: '<',
		*/
		sim,
		/*����*///c>f ? '>' : c<f ? '<' : 
		/*������*///b>e ? '>' : b<e ? '<' : 
		/*�����*///a>d ? '>' : a<d ? '<' : '=',
		d,e,f);
	//���������� ����������� ����
	leap = c%4 ==0 && (c%100!=0 || c%400 ==0);
	printf("%d is%s leap year\n", c,leap ? "": "n't");
}
