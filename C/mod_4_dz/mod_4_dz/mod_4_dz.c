#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	int i,j,k,h,a,b,x,y,m,x1,y1,x2,x3,y3,y2,i_max/*,x_max, y_max*/;
	//char c;
	//double n,r;
	const int N = 50, KOL = 4;
	system("chcp 1251 > nul");	
	
	//12.	���������� ������� �������� � ��������� ASCII, ��������� ��:
//a)	4 �������� � ������, ��� 10-�, 8-� � 16-� ���;
//b)	16 ��������, ��������� � ���������� �������� ������� �����, � � ���������� ����� � ������� ����� 16-�� ���� �������.
/*		
	j = 0;
	for (i=0; i<=15; i++)
		printf("  %X",i);
	printf("%c", '\n');
	for (x=0; x<=255; x++)
	{
		y = (x & 0xF) << 4 | (x & 0xF0) >> 4;
		switch(y)
		{
			case 0x7:
			case 0x8:
			case 0x9:
			case 0xA:
			case 0xD: c=' '; break; 
			default: c=y; break;
		}
		if ( !(y & 0xF0)) 
			{
				printf ("%X ", j);
				j++;
		}
		printf("%c %c",	 c,
			(y & 0xF0) != 0xF0 ? '\xBA' : '\n');
	}

	for (i=0; i<=255; i++)
	{
		switch(i)
		{
			case 0x7:
			case 0x8:
			case 0x9:
			case 0xA:
			case 0xD: c=' '; break; 
			default: c=i; break;
		}
		printf("%c %3d %#04o %02X\n", c,i,i,i);
	}
	
	//����������� ������� ASCII
	for (x=0; x<=255; x++)
	{
		switch(x)
		{
			case 0x7:
			case 0x8:
			case 0x9:
			case 0xA:
			case 0xD: c=' '; break; 
			default: c=x; break;
		}
		printf("%c %02X%c", c,x,
			(x & 0x0F) != 0xF ? '\xBA' : '\n');
	}
	puts("==================================================");	
	for (x=0; x<=255; x++)
		{
			y = (x & 0xF) << 4 | (x & 0xF0) >> 4;
			switch(y)
			{
				case 0x7:
				case 0x8:
				case 0x9:
				case 0xA:
				case 0xD: c=' '; break; 
				default: c=y; break;
			}
			printf("%c %02X%c", c,y,
				(y & 0xF0) != 0xF0 ? '\xBA' : '\n');
		}	
	

	//1. ����� N �����, �������� ������ ������������ �� ���������, ���������� ����� ������� ����� �� ������ ���������. ���������� ����� �������� � ���������� ��� ���������� ��� ������ ���������� ��������� �����.
	printf("����� ���������� %d �����\n", N);
	for (i=1; i<=N; i++)
	{
		scanf("%d %d", &x, &y);
		r = sqrt(pow((double)x,2)+pow((double)y,2));
		if(r>=m)
		{
			m=r;
			x_max = x;
			y_max = y;
			i_max = i;
		}
	}
	printf("�� ������ ��������� �������� ������� %d �����, � ������������ x = %d � y = %d\n",
		i_max, x_max, y_max);

	//2. ��������� ��������� ����� � ������, �������� �� ��������� (�������, ����, �����������, ����, ��������, ����������� �� ����� � ������������).
	printf("Select figure: 1-square, 2 - circle, 3-triangle, 4-romb, 5-mishen\n");
	scanf("%d", &i_max);
	srand((unsigned)time(NULL)); rand(); rand();
	x = rand() % N;
	y = rand() % N;
	x1 = rand() % N;
	y1 = rand() % N;
	x2 = rand() % N;
	y2 = rand() % N;
	switch (i_max)
	{
	case 4: for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
			putchar(j==abs(N/2 -i) && j<=N/2
				|| (j==i+N/2 && i<=N/2 || i==N-j-1+N/2 && i>N/2) && j > N/2 ?'\xFA':
				i==y && j==x 
				|| i==y1 && j==x1
				|| i==y2 && j==x2 ? '\xDB' : ' ');
		putchar('\n');
	} break;
	case 1: for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
		{
			putchar((i==5 || i==19) && j>=5 && j<20
				||( j==5 || j==19) && i>=5 && i<20 ?'\xFA': 
				i==y && j==x 
				|| i==y1 && j==x1
				|| i==y2 && j==x2 ? '\xDB' : ' ');
		}
		putchar('\n');
	} break;
	case 2: for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
			putchar(((j-N/2)*(j-N/2) + (i-N/2)*(i-N/2)) <= (N*N/9)
				&& ((j-N/2)*(j-N/2) + (i-N/2)*(i-N/2)) >= (N*N/11) ?'\xFA':
				i==y && j==x 
				|| i==y1 && j==x1
				|| i==y2 && j==x2 ? '\xDB' : ' ');
		putchar('\n');
	} break;
	case 3: for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
			putchar(i==j && j<=N && j>N/2
				|| (i==N-j-1) && j<=N/2
				||i==N-1 ?'\xFA':
				i==y && j==x 
				|| i==y1 && j==x1
				|| i==y2 && j==x2 ? '\xDB' : ' ');
		putchar('\n');
	} break;
	case 5: for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
			putchar(i==j && j<=N && j>N/2
				|| (i==N-j-1) && j<=N/2
				||i==N-1 
				|| ((j-N/2)*(j-N/2) + (i-(N-6))*(i-(N-6))) <= (N*N/28)
				&& ((j-N/2)*(j-N/2) + (i-(N-6))*(i-(N-6))) >= (N*N/35) ?'\xFA':
				i==y && j==x 
				|| i==y1 && j==x1
				|| i==y2 && j==x2 ? '\xDB' : ' ');
		putchar('\n');
	} break;
	default: printf("You select wrond figure, stuppid boy!\n");
		break;
	}
*/
	//3.	���� �����. ������� � ��������� �� ������� ������ ����, ������� �� ����, ��������� �� N ���������, �� 1 �� K ����. ����������� ���, ��� ������ ��������� �������. 
//��������:
//a)	��������� ������ ��������� ���������� ���������.
//b)	����� ��� ���������� ����������� ���������.
	printf("���� ����. ������ ������� ���������:\n1 - �����\n2 - ������\n");
	scanf("%d", &i);
	srand((unsigned)time(NULL)); rand(); rand();
	do
		i_max = rand() % N;
	while (i_max<22);
	printf("���� � ���� ������ ���������� %d ���������\n", i_max);
	k = rand() % 6 +2;
	printf("������ ����� �� 1 �� %d ���������\n", k);
	//i_max = 25;
	x = 0;
	j = 1;
	do 
	{
		if (!x) printf("�������� %d ���������. ��� ���\n", i_max);
		else printf("��������� ������ %d ��������\n�������� %d ���������. ��� ���\n", x, i_max);
		scanf("%d", &y);
		if (y > k) y = k;
		else if (y>i_max) y = i_max;
		if(i_max ==y) 
		{
			j=0;
			break;
		}
		i_max -=y;
		
		//if (i==2 && i_max%(k+1))
		//{
		//	x = i_max%(k+1);
		//}
		if (i==2 && (i_max-1)%(k+1))
		{
			x = (i_max-1)%(k+1);
		}
		else
		{
			srand((unsigned)time(NULL)); rand(); rand();
			x = rand() % k+1;
		}
		
		if (x >=i_max) x = i_max;
		i_max-=x;
		
	}
	while (i_max >= 1);
	if (j) printf("������� ��!\n");
	else printf("������� ���������!\n");
/*
	//5.   ��������� ����� ����������� ����� �� m �� n, ��������������� ������������ ��������, ��������, ������� �� 3 � 7, �� ������� �� 3 � 7, ����� ���������� ����� ���� � �.�.
	printf("����� ������ � ��������� �����\n");
	scanf("%d %d", &m, &n);
	j = 0;
	i_max =0;
	for (i=m; i<=n; i++)
	{
		if ((i%3 == 0) || (i%7 == 0)) j += i;
		else i_max += i;
	}
	printf ("����� ����, ������� ������� �� 3 � 7 ����� %d\n", j);
	printf ("����� ����, ������� ��������� �� 3 � 7 ����� %d\n", i_max);

	//6.	��������� ����� ���� ����������  � ���������� ������ �����.
	j = 0;
	m = 0;
	printf("����� �����\n");
	scanf("%d", &m);	
	do
	{
		i = m%10;
		n = m/10;
		if(n<10) j += i + n;
		else j += i;
	}
	while (n >= 10);
	printf ("����� ���� ����� ����� %d\n", j);

	//7.	������������� ��������� � ���������� ����� �����, �.�. �������� ������� ���� �� ��������
	j = 0;
	m = 0;
	printf("����� �����\n");
	scanf("%d", &m);
	do
	{
		i = m%10;
		n = m/10;
		if(n<10) 
		{
			j *=10;
			j += i;
			j *=10;
			j += n;
		}
		else 
		{
			j *=10;
			j += i;
		}
		m /= 10; 
	}
	while (n >= 10);
	printf ("��������������� ����� %d\n", j);

	//8.	� ������ ���� ��������� �������� 10 ��. ������ ��������� ���� �� �������� �� 10% ������, ��� � ����������.
//����������:
//a)	������� �� �� �������� � 10-� ����; 
//b)	� ����� ���� �� ������� �������� ������ 20 ��;
//c)	� ����� ���� ���  ��������� ������ �������� 100 ��.
	
	r = n = 10.0;
	j = 0;
	m = 0;
	for (i=1; i<=100; i++)
	{
		if(i<=10) 
		{
			r *= 1.1;
			if (r<=20) j++;
		}
		n +=r;
		if (n <=100) m++;
	}
	printf("�� 10 ���� �� �������� %G ��\n", r);
	printf("�� %d ���� �� �������� ������� ������ 20 ��\n", j);
	printf("�� %d ���� ��� ��������� ������ �������� 100 ��\n", m);

	//13.	���������� ������� �������� �������, ��������, y = (x-3)*(x+2), ������� x �� ��������� �� a �� b � ����� h.
	printf("����� ������ � ��������� ����� � ���\n");
	scanf("%d %d %d", &a, &b, &h);
	printf("X  Y\n");
	for(x=a; x<=b; x += h)
	{
		y = (x-3)*(x+2);
		printf("%d | %d\n", x, y);
		
	}
	//14.	���������� ��� ������ ������� ���������� ������ ������� �� ��������� �� a �� b � ����� h, ����� ��� y �� �����������, � ��� x � �� ��������� (���� ������ ������ ������������� �������� h):
//a)	��������� �������� a � b ���, ����� ������ ��������� �� ������ ��������;
//b)	���������� ��������� ����������� ��������������� �������� ������� ���, ����� ������ ��������� �� ������ ��������.

	printf("����� ������ � ��������� ����� � ���\n");
	scanf("%d %d %d", &a, &b, &h);
	for(x=a; x<b; x+=h)

		{
			for(y=0; y<=(b-3)*(b+2); y++)
				putchar(y == (x-3)*(x+2) ? '*' : ' ' );
			putchar('\n');
		}

//21.	���������� ������������������ ����� ��������� 1, 1, 2, 3, 5 � � �.�., ��� ������ ����� ����� ����� ���� ����������:
//a)	����� N �����;
//b)	���� ����� �������� �� ����� N.
	a = 1, b = 0;
	for (i=1; i<=N; i++)
	{
		k = a + b;
		a = b;
		b = k;
		if (k<=N)
			printf("%d \n", k);
	}
	//19.	����� ���������� ����� �������� (���)  � ���������� ����� ������� (���) ���� ����� �����.
	printf("����� ������ � ��������� �����\n");
	scanf("%d %d", &a, &b);
	i=1;
	a<b ? (h = a) : (h=b);
	do
	{
		k=a*i;
		i++;
		if (!(k%b)) printf ("%d - ���\n", k);
	}
	while (k%b);
	for(j=h; j>=1; j--)
	{
		if (!(a%j) && !(b%j)) 
		{printf("%d - ���\n", j); break;}
	}

	//20.	���������� ����������� ������. ������ ��� ����������� �����, ��������, 1/2 � 2/3, � ���������� � ���� ����������� �� ������ �� �����, ��������, ������������ � �������, �������� ��� ������������� ��������� � ����������� �� �� ����� ���������.
	printf("����� ����������� ����� \n");
	scanf_s("%d/%d %d/%d", &x, &x1, &y, &y1);
	i=0;
	do
	{
		i++;
		k=x1*i;			
	}
	while (k%y1);
	j = k/y1;
	x2 = x*i;
	y2 = y*j;
	m = x2 + y2;
	h = x2-y2;
	a = x * y;
	b = x1 * y1;
	x3 = x*y1;
	y3 = x1 * y;
	printf ("����� ������ ����� %d/%d\n", m, k);
	printf ("�������� ������ ����� %d/%d\n", h, k);
	printf ("������������ ������ ����� %d/%d\n", a, b);
	printf ("������� ������ ����� %d/%d\n", x3, y3);*/
}