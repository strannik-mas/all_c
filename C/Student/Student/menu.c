#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

void menu(const menu_item list[], int n)
{
	int i, r, k;

	while(1)
	{
		system("cls");

		for (i = 0; i < n; i++)
			printf("%d. %s\n", i+1, list[i].text);
		printf("%d. %s\n", 0, "Выход");

		do
		{
			printf("\nВведите номер комманды: ");
			fflush(stdin);
		}while (scanf("%d", &r)!=1 || r<0 || r>i);
		

		if(--r<0) break;
		k = list[r].command(pstud, nstud);
		printf("\nОбработано записей %d\n", k);
		system("pause");
	}
}