#include<stdio.h>

int main()

{

	int x, y, z, a[]={10,20,30,40,50}, i;

	int * p; //указатель может хранить адрес переменной
	char *q; 
	x=10;
	p = &x; //"настройка" указателя
	printf(" x = %d\t &x = %p\n", x, &x); 
	printf("*p = %d\t p = %p\n", *p, p );

	*p = 100; //изменить содержимое по адресу
	printf(" x = %d\t &x = %p\n", x, &x);

	p = &y; 

	*p = 1000;
	printf(" y = %d\t &y = %p\n", y, &y);

	q = p;
	printf("*q = %d\t q = %p\n", *q, q );

	q = NULL;

	p == q ? printf("p == q\n") : printf("p != q\n");
	p != q ? printf("p != q\n") : printf("p == q\n");
	p > q ? printf("p > q\n") : printf("p <= q\n");

	//p >= q

	p == NULL	? printf("p == NULL\n") : printf("p != NULL\n");
	!p			? printf("p == NULL\n") : printf("p != NULL\n");
	q != NULL	? printf("q != NULL\n") : printf("q == NULL\n");
	q			? printf("q != NULL\n") : printf("q == NULL\n");

	printf("a[] = {");
	for (i = 0; i < sizeof a / sizeof *a; i++) 
		printf("%d ", a[i]);
	printf("\b }\n");
	
	p = a;

	z = *p; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = *p+1; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = *(p+1); printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = ++*p; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = *++p; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = *p++; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);
	z = (*p)++; printf("z = %d\t *p = %d\t p = %p\n", z, *p, p);

	printf("a[] = {");
	for (i = 0; i < sizeof a / sizeof *a; i++) 
		printf("%d ", a[i]);
	printf("\b }\n");
}
