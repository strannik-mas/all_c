#define _CRT_SECURE_NO_WARNINGS
//�������� N ����� ���������: 1 1 2 3 5 8...
#include<stdio.h>

int main()
{
	int N,	//���-�� ����� ���
		i,	//������� �����
		a,b,c;	//����� ���������: c = a+b

	printf("Enter N\n");
	scanf("%d", &N);

	for (a=0, c=b=1, i = 0; i < N; i++, c = a+b, a=b, b=c) //�������� 2-�� ������� f(i) = f(i-1) + f(i-2)		
		printf("%d ", c);
	printf("\n");
}