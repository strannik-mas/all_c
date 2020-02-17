#include<stdio.h>
//из дз 3а
int main()
{
	int a[]={5,9,6,3,5,7,9,1,2,4};
	const int n=sizeof a / sizeof a[0];
	int i,x;

	//печать массива
	for(i=0; i<n; ++i)
		printf("%d, ", a[i]);
	printf("\b\b \n"); //для того чтоб отодвинуть курсор под последнюю запятую, поставить пробел и уйти на новую строку

	//ввести ключ поиска и найти где оно находится в массиве
	printf("Enter value: \n");
	scanf("%d", &x);

	//линейный поиск (для упрощения алгоритма можно применить метод барьера - заменить последний элемент на x)
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