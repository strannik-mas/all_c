//1.	Написать программу «Калькулятор» (отложенные/ленивые/скользящие вычисления -Фибоначчи):
//a)	примитивный:
//b)	Кнопочный (4 переменные):
//c)	анализатор приоритетов: (6 переменных)
//d)	анализатор формул (с goto)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MYDEBUG

#ifndef MYDEBUG
#define DUMP(ival, fval);
#else
#define DUMP(ival, fval) printf(#ival"=%.3f\t"#fval"=%c\n",ival,fval);
#endif

#define MYDEBUG2

#ifndef MYDEBUG2
#define DUMP2(ival);
#else
#define DUMP2(ival) printf(#ival"=[%.3f]\n",ival);
#endif

int main()
{
	
	double x,y, otv, otv_pr;
	char znak, znak_pr, znak_prior;

	system("chcp 1251 > nul");
	/*
	//а
	do
	{
		printf("Введи формулу вида 12.5 + 32.56\n");
		
		fflush(stdin); 
		
	}while(scanf("%lf %c %lf", &x, &znak,&y) != 3 && printf("Нужно только 2 числа и знак операции между ними!\n")
		|| (znak & 0x00FF) != 0x002B && (znak & 0x00FF) != 0x002F
		&& (znak & 0x00FF) != 0x002A && (znak & 0x00FF) != 0x002D && printf("Введи верный знак операции!\n"));
	//----------------------------------------
	switch(znak)
	{
	case '+': otv = x+y; break;
	case '-': otv = x-y; break;
	case '*': otv = x*y; break;
	case '/': otv = x/y; break;
	}
	DUMP(x,y);
	//----------------------------------------
	printf("выражение %G %c %G = %G\n", x,znak,y,otv);

	//б
	otv = 0;
	fflush(stdin); 
	printf("Введи произвольную формулу вида 2.5 + 32 *5.1 =\n");
	do
	{
		
		scanf("%lf %c", &x, &znak);
		//----------------------------------------
		if(otv)
		{
			DUMP2(otv);
			switch(znak_pr)
			{
				case '+': otv += x; break;
				case '-': otv -= x; break;
				case '*': otv *= x; break;
				case '/': otv /= x; break;
			}
			
		}else	otv = x;
		znak_pr = znak;		
	}while((znak & 0x00FF) != 0x003D);
	//----------------------------------------
	printf("выражение равно %G\n", otv);
	*/

	//c
	otv = 0;
	otv_pr = 0;
	znak_prior =0;
	znak_pr =0;
	fflush(stdin); 
	printf("Введи произвольную формулу вида 2.5 + 32 *5.1 =\n");
	do
	{
		
		scanf("%lf %c", &x, &znak);
		//----------------------------------------
		if(otv || otv_pr)
		{
			DUMP2(otv);
			if(znak == '*' || znak == '/')
			{
				if(znak_prior)
				{
					switch(znak_prior)
					{
						case '*': otv_pr *= x; break;
						case '/': otv_pr /= x; break;
					}
				}
				if(!otv_pr) otv_pr = x;
				znak_prior = znak;
				continue;
			}
			else
			{
				if(znak_prior)
				{
					switch(znak_prior)
					{
						case '*': otv_pr *= x; break;
						case '/': otv_pr /= x; break;
						
					}
					if (!otv) 
						{
							otv += otv_pr;
							znak_pr = znak;	
							znak_prior =0;
							otv_pr = 0;
							continue;
						}
					switch(znak_pr)
					{
						case '+': otv += otv_pr; break;
						case '-': otv -= otv_pr; break;				
					}
					
					otv_pr = 0;
					znak_prior = 0;
				}else
				{
					switch(znak_pr)
					{
						case '+': otv += x; break;
						case '-': otv -= x; break;
				
					}
				}
			}			
		}else	
		{
			if(znak == '*' || znak == '/') 
			{
				otv_pr = x; 
				znak_prior=znak; 
				continue;
			}	else otv = x;
		}
		znak_pr = znak;					
	}while((znak & 0x00FF) != 0x003D);
	//----------------------------------------
	printf("выражение равно %G\n", otv);

}