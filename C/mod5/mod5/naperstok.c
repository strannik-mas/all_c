#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	const char blank = ' ', ball = '\xF';
	const int delay = 20, min = 50;
	char n[3] = {blank,blank,blank};
	int r, i = 0, s, b = 0;

	setlocale(LC_CTYPE, ".866");
	srand((unsigned)time(NULL));
	while (1)
	{
		do
		{
			system("cls");
			wprintf(L"\n���� � ���������\n\n");
			wprintf(L"\n���� ������? (min = %d ���., 0 - �����\n", min);
			fflush(stdin);
		}while(!scanf("%d", &s) || s<min && s!=0);
		if(!s) break;

		wprintf(L"\n��� ������� � ������� ���������!\n");
		puts("\n\n 1 2 3");
		do
		{
			n[i] = blank;
			i = rand() %3;
			n[i] = ball;
			printf(" %c %c %c\r", n[0],n[1],n[2]);
			_sleep(delay);
		}while(!_kbhit()/*��� ������� ���������� 1 ���� � ������ ����� ���-�� ���� � 0, ���� �����*/ 
			|| (r=_getch()-'0') < 1 || r > 3);

		wprintf(L"\n%*d\n%s�����!\n", 2*r, r, r==i+1 ? (b+=s, L"�") : (b-=s, L"�� �"));

		wprintf(L"\n��� %s����� = %d ���.\n", b<0 ? L"���" : L"��", b);

		wprintf(L"\n������� ����� �������...");
		_getch();
	}
	wprintf(L"\n\n%s %d ���. � ������� �� ����...\n\n",
		b<0 ? L"�����" : L"������", abs(b));
}
