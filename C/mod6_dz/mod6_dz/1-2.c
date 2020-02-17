#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define N 12

int main()
{
	int k,i,j,s, a[N];
	system("chcp 1251 > nul");

	for (i = 0; i < N; i++)
	{
		printf("¬веди %d элемент массива\n", i);
		scanf("%d", &a[i]);
	}

	
	//++++++++===============
	//вводим число искомое
	printf("—колько элементов в строке печатать? \n");
	scanf("%d", &k);

	//===========================
	//печать массива
	s=0;
	for(i=0; i<N/k; ++i)
	{
		for(j=0; j<k; j++)
		{
			printf("%d, ", a[s]);
			s++;
		}
		printf("\b\b \n");
	}
}