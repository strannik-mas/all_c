#include<stdio.h>
#include<stdlib.h>
#include"data.h"
#include"do_it.h"
#include"in_out.h"

static int min_pos(const int a[], int n)
{
	int i, min, i_min;
	for(min = a[i_min=0], i=1; i<n; ++i)
		if(a[i]<min) min = a[i_min=i];
	return i_min;
}

static int checked(const student *p, int base)
{
	int j = min_pos(p->grade, sizeof(p->grade)/sizeof(p->grade[0]));
	return p->grade[j] == base;

}
int process_all(student *p, int n)
{
	
	int k, i;	
	student * const q = malloc(n*sizeof(student)); //��� ������ �� ������ �������� const
	for (k = i = 0; i < n; i++)
		if(checked(p+i, 5)) q[k++] = p[i];

	if(!q)
	{
		printf("������ ��������� ������������ ������!\n");
		return n;
	}
	printf("���� ���������: \n");
	output(q,k);

	for (k = i = 0; i < n; i++)
		if(checked(p+i, 4)) q[k++] = p[i];
	printf("���� ���������: \n");
	output(q,k);

	for (k = i = 0; i < n; i++)
		if(checked(p+i, 3)) q[k++] = p[i];
	printf("���� ���������: \n");
	output(q,k);

	for (k = i = 0; i < n; i++)
		if(checked(p+i, 2)) q[k++] = p[i];
	printf("����� ����������: \n");
	output(q,k);
	free(q);

	return n;
}