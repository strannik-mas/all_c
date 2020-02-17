#include<stdio.h>
#include<locale.h>
#include<conio.h>

#define ESC 0x1B

int main()
{
	int code;
	setlocale(LC_CTYPE, ".866");
	wprintf(L"Нажимайте клавиши, смотрите коды.\n"
			L"0x00ZZ - ASCII-код (обычная клавиша)\n"
			L"0xZZ00 - Scan-код (управляющая клавиша)\n"
			L"Esc - конец\n");
	do
	{
		code = getch(); //ввод символа с консоли
		if(code == 0 || code == 0xE0)
			code = getch()<<8;
		printf("%#06X\n",code);
	}
	while(code!=ESC);
	return 0;
}