#include<stdio.h>

int main()
{
	
	int a[]={5,9,6,3,5,7,9,1,2,4};
	const int n=sizeof a / sizeof a[0];
	int i,j,x,k=0,inv,max=0;
	/*
	//bubble
	for(i=0; i<n-1; i++)
	{
		inv=0;
		for(j=0; j<n-i-1; j++)
			{
				if(a[j] > a[j+1])
				{
					x = a[j];
					a[j] = a[j+1];
					a[j+1] = x;
					++k;
					inv++;
				}
				
			}
		if(!inv) break;
	}
			

	//max
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(a[j]>=max)
			{
				max = a[j];
				inv = j;
				k++;
			}
		}
		x = a[n-i-1];
		a[n-i-1] = max;
		a[inv]=x;
		max =0;
	}*/
	//insert
	for(i=1; i<n; i++)
	{
		x = a[i];
		j = i-1;
		while (j>=0 && a[j]>x)
		{
			a[j+1] = a[j];
			j--;
			k++;
		}
		a[j+1]=x;
	}


	//печать массива
	for(i=0; i<n; ++i)
		printf("%d, ", a[i]);
	printf("\b\b \noperation %d\n", k);


}