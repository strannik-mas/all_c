#include<stdio.h>
#include<locale.h>
#include<conio.h>	//��� getch()
#include<stdlib.h>	//��� rand()
#include<time.h>	//��� time()

#include"console_ctrl.h"

#define ESC 0x1B

int main()
{
	int i, x;
	const int N=10, A=10, B=50;
	setlocale(LC_CTYPE,".866");
	srand((unsigned)time(NULL)); rand();
	do
	{
		textattr(0xE1); 
		system("cls");
		wprintf (L"�������������� ����������� �� ��������� ������ �� %d �� %d\n", A, B);
		for(i=0; i<N; ++i)
		{
			x = rand() % (B-A+1) + A; 
			printf("\n%3d ", x); 
			textattr(0x10); 
			printf("%*c\n", x,'	');
			textattr(0xE1);
		}
		wprintf(L"\nESC - ���������, ����� ������� - ����������\n");
		//TextXY(150, 50, "Ede", 0xE1);
	}while(_getch() != ESC);
	return 0;
}