#define _CRT_SECURE_NO_WARNINGS
//печатать N чисел Фибоначчи: 1 1 2 3 5 8...
#include<stdio.h>

int main()
{
	int N,	//кол-во чисел фиб
		i,	//счетчик цикла
		a,b,c;	//числа Фибоначчи: c = a+b

	printf("Enter N\n");
	scanf("%d", &N);

	for (a=0, c=b=1, i = 0; i < N; i++, c = a+b, a=b, b=c) //рекурсия 2-го порядка f(i) = f(i-1) + f(i-2)		
		printf("%d ", c);
	printf("\n");
}