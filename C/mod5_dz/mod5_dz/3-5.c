#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

#define ESC 0x1B

int main()
{
	int x, x1, x2, code;
	//float x1, x2;
	system("chcp 1251 > nul");
	
		printf("¬води целые числа\n");
	do
	{	
		fflush(stdin); 
		code = _getch();
		scanf("%d", &x);
		x1 = x%10;
		
		while (x1 > 1)
		{
			x2 = x1%10;
			x1 %=10;
		}
		
	//--------------------------------------------

	printf("Chislo ravno %d\n", x1);
	
	}while(code!=ESC);
}