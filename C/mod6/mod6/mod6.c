#include<stdio.h>
//�� �� 3�
int main()
{
	int a[]={5,9,6,3,5,7,9,1,2,4};
	const int n=sizeof a / sizeof a[0];
	int i,x;

	//������ �������
	for(i=0; i<n; ++i)
		printf("%d, ", a[i]);
	printf("\b\b \n"); //��� ���� ���� ���������� ������ ��� ��������� �������, ��������� ������ � ���� �� ����� ������

	//������ ���� ������ � ����� ��� ��� ��������� � �������
	printf("Enter value: \n");
	scanf("%d", &x);

	//�������� ����� (��� ��������� ��������� ����� ��������� ����� ������� - �������� ��������� ������� �� x)
	for(i=0; i<n && a[i] != x; ++i)
		;
	/*
	for(i=0; i<n; ++i)
		if (a[i] == x) 
			break;
*/
	if(i<n)
		printf("a[%d] = %d\n", i, x);
	else 
		printf("%d not found\n", x);

		
}