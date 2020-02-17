#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

	/*
	int a=2, b=2, c=2, r;
	r = a==b==c;
	printf("%d\n",r);

	//применение коньюнкции
	b=0;
	b!=0 && (r = a/b);
	printf("%d\n",r);

	//f() && g() && h()
	printf("Enter time in format hh:mm:ss\n");
	scanf_s("%2d:%2d:%2d", &a,&b,&c) == 3 
		&& a>=0 && a<24 
		&& b>=0 && b<60 
		&& c>=0 && c<60 
		&& printf("%02d:%02d:%02d\n", a,b,c)
		|| printf("Invalid time format!\n");

	//тернарный оператор
	printf("Enter 2 int values: ");
	scanf("%d %d", &a, &b);

	printf("%d %c %d\n",
		a,
		a>b ? '>' : a<b? '<' : '=',
		b);
		*/

	//битовые операции
	unsigned char a, r, mask;
	a = 0xCA;
	//распечатываем побитно - можно сдвигать, а можно делить
	printf("%02X\t%d%d%d%d%d%d%d%d\n", a, 
		a>>7,(a>>6)%2,(a>>5)%2,(a>>4)%2,a/8%2,a/4%2,(a>>1)%2, a%2);
	
	r = ~a;
	printf("%02X\t%d%d%d%d%d%d%d%d\n", r, 
		r>>7,(r>>6)%2,(r>>5)%2,(r>>4)%2,r/8%2,r/4%2,(r>>1)%2, r%2);
	mask = 0x0F;
	r = a & mask;
	printf("%02X\t%d%d%d%d%d%d%d%d\n", mask, 
		mask>>7,(mask>>6)%2,(mask>>5)%2,(mask>>4)%2,mask/8%2,mask/4%2,(mask>>1)%2, mask%2);
	printf("Pob I %02X\t%d%d%d%d%d%d%d%d\n", r, 
		r>>7,(r>>6)%2,(r>>5)%2,(r>>4)%2,r/8%2,r/4%2,(r>>1)%2, r%2);

	r = a | mask;
	printf("Pob ILI %02X\t%d%d%d%d%d%d%d%d\n", r, 
		r>>7,(r>>6)%2,(r>>5)%2,(r>>4)%2,r/8%2,r/4%2,(r>>1)%2, r%2);

	r = a ^ mask;
	printf("%02X\t%d%d%d%d%d%d%d%d\n", r, 
		r>>7,(r>>6)%2,(r>>5)%2,(r>>4)%2,r/8%2,r/4%2,(r>>1)%2, r%2);

	r = a & ~mask;
	printf("%02X\t%d%d%d%d%d%d%d%d\n", r, 
		r>>7,(r>>6)%2,(r>>5)%2,(r>>4)%2,r/8%2,r/4%2,(r>>1)%2, r%2);
}