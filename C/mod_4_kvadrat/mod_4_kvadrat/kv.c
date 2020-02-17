//Печать флажков
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define N 21

int main()
{
	int i,j;
	//----------------------------------------------------------------	
	for(i=0; i<N; ++i)									//	*****
	{													//	*****
		for(j=0; j<N; ++j)								//	*****
			putchar('\xDB');								//	*****
		putchar('\n');									//	*****
	}
	system("pause");
	system("cls");
//----------------------------------------------------------------	
	for(i=0; i<N; ++i)									//	*****
	{													//	 ****
		for(j=0; j<N; ++j)								//	  ***
			putchar(i<=j?'\xDB':'\xFA');					//	   **
		putchar('\n');									//	    *
	}
	system("pause");
	system("cls");
//----------------------------------------------------------------	
	for(i=0; i<N; ++i)									//	*****
	{													//	 ****
		for(j=0; j<N; ++j)								//	  ***
			putchar(i>=j?'\xDB':'\xFA');					//	   **
		putchar('\n');									//	    *
	}
	system("pause");
	system("cls");
//----------------------------------------------------------------	
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i<=N-j-1?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
		for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i>=N-j-1?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i>=j && i<=N/2 || i<=N-j-1 && i>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------

		for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(j>=i && j<=N/2 || j<=N-i-1 && j>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((i>=N-j-1 && i<=N/2) || (i<=j && i>N/2) ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
		for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(j>=N-i-1 && j<=N/2 || j<=i && j>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------

	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((i<=N-j-1 && i<=N/2) || (i>=j && i>N/2) ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((j>=i || j>=N-i-1) && j<=N/2 || (j<=N-i-1 || j<=i) && j>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");

for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((i>=N-j-1 || i>=j) && i<=N/2 || (i<=j || i<=N-j-1) && i>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(j>=N-i-1-N/2 && j<=N/2 || j<=i+N/2 && j>N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(j>=abs(N/2 -i) && j<=N/2
				|| (j<=i+N/2 && i<=N/2 || i<=N-j-1+N/2 && i>N/2) && j > N/2 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//----------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i==j || N-i-1 == j 
				|| i == N/2 || j == N/2 ?'\xDB':'\xFA');		
		putchar('\n');									
	}
	system("pause");
	system("cls");
//------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(j%2==1 && i%2==1 ?'\xFA':'\xDB');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//---------------------------------------

	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i%2 && j%2==0 || !(i%2) && j%2!=0 ?'\xFA':'\xDB');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
	//------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((j>=abs(N/2 -i) && j<=N/2
				|| (j<=i+N/2 && i<=N/2 || i<=N-j-1+N/2 && i>N/2) && j > N/2)
				&& (i%2 && j%2!=0 || !(i%2) && j%2==0) ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//--------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar((((j==abs(N/2 -i) || (j==(N/2 -i+3) || j==(N/2 -i+6) || j==(N/2 -i+9)) && i<=N/2
			    || ((j==i-N/2+3 || j==i-N/2+6 || j==i-N/2+9)&& i>N/2)) && j<=N/2)
				|| ((j==i+N/2 || j==i-3+N/2|| j==i-6+N/2|| j==i-9+N/2) && i<=N/2 
				|| (i==N-j-1+N/2 || i==N-j-1+N/2-3 || i==N-j-1+N/2-6 || i==N-j-1+N/2-9) && i>N/2) && j > N/2) ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
//-------------------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(((j-N/2)*(j-N/2) + (i-N/2)*(i-N/2))<= N*N/4 ?'\xDB':'\xFA');					
		putchar('\n');									
	}
	system("pause");
	system("cls");
	//------------------------
	for(i=0; i<N; ++i)									
	{													
		for(j=0; j<N; ++j)								
			putchar(i==j || N-i-1 == j 
				|| j==abs(N/2 -i) && j<=N/2
				|| (j==i+N/2 && i<=N/2 || i==N-j-1+N/2 && i>N/2) && j > N/2 ?'\xDB':'\xFA');		
		putchar('\n');									
	}
	system("pause");
	system("cls");
}