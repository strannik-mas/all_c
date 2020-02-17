#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <string.h>

/*
void qsort(void *base, size_t nelem, size_t width, 
		   int (*fcmp)(const void * e1, const void *e2)	);
*/

int intcmp(const void * e1, const void *e2)

{

	return *(int *)e1 - *(int *)e2;

}

int main()

{

	char name[4][32]={"Ivanov","Sidorov","Petrov","Azcherov"}; 
	int a[] = {5,3,6,1,8,11,2,3,1,7}; 
	int i, n = sizeof a / sizeof a[0];
	setlocale(LC_CTYPE,".866");

	for(i=0; i<4; ++i) puts(name[i]); 
	putchar('\n');

	qsort(name,4,32,strcmp);

	for(i=0; i<4; ++i) puts(name[i]); 
	putchar('\n');

	for(i=0; i<n; ++i) printf("%4d",a[i]); 
	putchar('\n');

	qsort(a,n,sizeof(int),intcmp);

	for(i=0; i<n; ++i) printf("%4d",a[i]); 
	putchar('\n');

	return 0;
}