#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//3б
#define MYDEBUG2

#ifndef MYDEBUG2
#define DUMP2(ival);
#else
#define DUMP2(ival) printf(#ival"=[%d]\n",ival);
#endif

int main()
{
	int a[] = {1,2,3,4,5,6,7,9,11,13,31,54,65};
	const int n = sizeof a / sizeof a[0];
	int i,x;

	system("chcp 1251 > nul");
	//печать массива
	for(i=0; i<n; ++i)
		printf("%d, ", a[i]);
	printf("\b\b \n"); 
	//вводим число искомое
	printf("Enter value: \n");
	scanf("%d", &x);
	//============================
	i = n/2;
	do
	{		
		DUMP2(i);
		if (x >a[i])
			i += i/2; 
		if (x < a[i])
			i /= 2; 
	}while(a[i] != x);
	//================================
	printf("искомое число %d имеет индекс в массиве %d\n", x,i);
}