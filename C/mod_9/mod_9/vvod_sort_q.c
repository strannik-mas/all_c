//ввести и отсортировать несколько строк
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define N 21
void PrintName(char *s[], int n); 
void PutName(char **s, char *buf);

int main()
{
	char *pName[N] = {NULL}; // создаем и инициализируем массив указателей
	int i=0; // сколько элементов
	char buf[256], yn; // сюда скачиваем имена
	//ввод строк
A:
	printf("Input name:");
	gets(buf);
	PutName(&pName[i], buf);
	i++;
	//печатаем каждый раз что ввели и длину строки
	("Vi weli slovo:=%s,\tDlina stroki=%d\n", buf, strlen(buf));
	//запрос на продолжение
	printf("\nAgain?(Y/N):"); 
	scanf("%c",&yn);
	fflush(stdin);
	if (yn=='Y'	|| yn=='y') goto A;

	PrintName(pName, i);
	//SortName(pName, i);
	//PrintName(pName, i);

	//освобождаем память

}

void PrintName(char *s[], int n)
{
	int i;
	printf("\n\n");
	for(i=0;i<n;i++) puts(s[i]);
}

void PutName(char **s, char *buf)
{
	*s=(char*)malloc(strlen(buf)+1); //выделить динамическую память
	strcpy(*s,buf); 
}