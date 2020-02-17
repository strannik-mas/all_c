#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include"triangle.h"
#include"tetragon.h"

int main()
{
	setlocale(LC_CTYPE, ".866");

	
	triangle();
	tetragon();
	return 0;
}