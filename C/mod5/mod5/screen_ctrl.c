#include<stdio.h>
#include<Windows.h>

#define gotoxy(x,y) { COORD d={x,y}; \
					SetConsoleCursorPosition( \
						GetStdHandle( STD_OUTPUT_HANDLE), d); }
#define textattr(color) { SetConsoleTextAttribute( \
							GetStdHandle( STD_OUTPUT_HANDLE), color); }

int main()
{
	puts("Hello from console");
	gotoxy(1, 20);
	textattr(0x1F);
	puts("Hello from console 1");
	gotoxy(20, 1);
	textattr(0xE5);
	puts("Hello from console 2");
	textattr(0x07);
}
