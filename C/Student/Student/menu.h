#ifndef MENU_H
#define MENU_H
#include"data.h"

typedef struct
{
	const char *text;
	int (*command)(student *pstud, int nstud);
} menu_item;

void menu(const menu_item list[], int n);

#endif