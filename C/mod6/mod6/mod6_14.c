#include<stdio.h>

#define N 20

int main()
{
	int a[N] = {2};
	int k,i,j,n;

	printf("Enter n: \n");
	scanf("%d",&n);
	/*
	for (k=1, i = 3; k<n; i+=2)
	{
		for(j=0; j<k && i % a[j] != 0; ++j)
			;
		if(j == k) a[k++]=i;
	}
	*/
	//увеличение эффективности
	for (k=1, i = 3; k<n; i+=2)
	{
		//ставим кандидата в кач. барьера
		for(a[k]=i, j=0; /*j<k &&*/ i % a[j] != 0; ++j)
			;
		if(j == k) k++;
	}

	for(i=0; i<n; ++i)
		printf("%d, ", a[i]);
	printf("\b\b \n");
}