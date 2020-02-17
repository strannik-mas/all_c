#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int x; float z;

	system("chcp 1251 > nul");
	printf("Hello, world!\n");
	printf("Привет, мир!\n");
	system("pause");
	
	x = 15;
	printf("%d %15u %#15o %#15x %#15X\n", x, x , x, x, x, x);

	x = 20;
	printf("%*d %15u %#15o %#15x %#15X\n", x-5,x, x , x, x, x, x);

	x = -1;
	printf("%15d %15u %#15o %#15x %#15X\n", x, x , x, x, x, x);

	z= -123.456f;
	printf("%20.3f %15E %.3G\n", z, z, z);

	z= -123.456E6f;
	printf("%20.3f %15E %.3G\n", z, z, z);

	printf("%s%c\n", "t=100", '\xF8');
	printf("%c%d. %s\n", '\x15', 1, "C progr.");
	printf("\x15%d. C progr.\n", 1);

	//scanf("(%3d)%3d-%2d-%2d", );
	scanf("%2d", &x);
	printf("%15d %15u %#15o %#15x %#15X\n", x, x , x, x, x, x);
	system("pause");
	system("cls");
	
	srand((unsigned)time(NULL)); rand(); rand();
	x = rand() % 20 +1;
	printf("%d\n", x);
	x = rand() % 20 +1;
	printf("%d\n", x);
	x = rand() % 20 +1;
	printf("%d\n", x);
	x = rand() % 20 +1;
	printf("%d\n", x);
	x = rand() % 20 +1;
	printf("%d\n", x);
	//system("dir");
/*
	//улучшенный генератор чисел от 1 до 100
	srand((unsigned)time(NULL)); rand(); rand();
	x = rand() 
*/
}