#include<stdio.h>
#include<locale.h>
#include<conio.h>

#define ESC 0x1B

int main()
{
	int code;
	setlocale(LC_CTYPE, ".866");
	wprintf(L"��������� �������, �������� ����.\n"
			L"0x00ZZ - ASCII-��� (������� �������)\n"
			L"0xZZ00 - Scan-��� (����������� �������)\n"
			L"Esc - �����\n");
	do
	{
		code = getch(); //���� ������� � �������
		if(code == 0 || code == 0xE0)
			code = getch()<<8;
		printf("%#06X\n",code);
	}
	while(code!=ESC);
	return 0;
}