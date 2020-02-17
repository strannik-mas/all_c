#include<stdlib.h>
#include<stdio.h>
int extern_var = 100;

int * return_ptr(int *p, int choice)
{
	static int static_var = 100;
	int local_var = 100;
	switch (choice)
	{
	case 1:
		return &local_var; //√–”Ѕјя ќЎ»Ѕ ј - нельз€ возвращать адрес локальной переменной (хот€ компил€тор выдаст ошибку типа warning)
	case 2:
		return &static_var;
	case 3:
		return &extern_var;
	case 4:
		return p;
	case 5:
		return malloc(sizeof(int)); //адрес в Heap
	}
	return NULL;
}

int main()
{
	int n=0;
	int *p;

	p = return_ptr(&n,4);
	//...
	return 0;
}