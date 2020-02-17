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
			wprintf(L"\nИгра в наперстки\n\n");
			wprintf(L"\nВаша ставка? (min = %d руб., 0 - конец\n", min);
			fflush(stdin);
		}while(!scanf("%d", &s) || s<min && s!=0);
		if(!s) break;

		wprintf(L"\nЖми клавишу с номером наперстка!\n");
		puts("\n\n 1 2 3");
		do
		{
			n[i] = blank;
			i = rand() %3;
			n[i] = ball;
			printf(" %c %c %c\r", n[0],n[1],n[2]);
			_sleep(delay);
		}while(!_kbhit()/*эта функция возвращает 1 если в буфере клавы что-то есть и 0, если пусто*/ 
			|| (r=_getch()-'0') < 1 || r > 3);

		wprintf(L"\n%*d\n%sгадал!\n", 2*r, r, r==i+1 ? (b+=s, L"У") : (b-=s, L"Не у"));

		wprintf(L"\nВаш %sигрыш = %d руб.\n", b<0 ? L"про" : L"вы", b);

		wprintf(L"\nНажмите любую клавишу...");
		_getch();
	}
	wprintf(L"\n\n%s %d руб. и спасибо за игру...\n\n",
		b<0 ? L"Отдай" : L"Получи", abs(b));
}
