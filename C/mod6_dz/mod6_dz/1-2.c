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
		printf("����� %d ������� �������\n", i);
		scanf("%d", &a[i]);
	}

	
	//++++++++===============
	//������ ����� �������
	printf("������� ��������� � ������ ��������? \n");
	scanf("%d", &k);

	//===========================
	//������ �������
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