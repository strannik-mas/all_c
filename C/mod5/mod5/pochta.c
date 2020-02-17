#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int main()
{
	const int N = 5, M = 3, AP = 3;
	int k, i, j, x;
	//на какой этаж и в какой подъезд нужно войти почтальону
	do
	{
		printf("Enter number of apartments:\n");
		//если ввести символ, то он останется в буфере клавы и его надо очистить
		fflush(stdin); // под linux не работает

	}while(scanf("%d", &k) != 1 && printf("Need a number!\n")
		|| k> M*N*AP && printf("Need value <= %d\n", M*N*AP)
		|| k <=0 && printf("Need a positive value!\n"));
//	if (k> M*N*AP) printf ("Enter valid value!\n");
//	else
//	{
		//i = (k-1)%N+1;
		//j = (k-1)/N +1;
		for(i=0; i<M; i++)
			for(j=0; j<N; ++j)
				for(x=1; x<=AP; ++x)
					{
						if (k == x+j*AP+i*N*AP) printf ("Appartment %d, floor %d, house %d\n", x, j+1,i+1);
					}
//	}	
}