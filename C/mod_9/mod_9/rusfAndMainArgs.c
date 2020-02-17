//руссификация и аргументы функции main()
#include <stdio.h>

const char * rus(const char *s)

{

static char b[2048]; //статический массив не уничтожается
int i;

for(i=0; b[i] = s[i]; ++i)
	if(b[i] >= 'А' && b[i] <= 'п')		b[i] -= 0x40; //корректировка кода символа
	else if(b[i] >= 'р' && b[i] <= 'я') b[i] -= 0x10; //чет не работает
	return b;
}

int main(int argc,				//счетчик количества переданных аргументов
		 const char **argv,	//массив указателей на строки, можно и так написать *argv[]
		 const char **env		
		 )
{
	int i; 
	if(argc==1)
	{
		puts("Use: prog.exe param1 param2"); 
		return 0;
	}

	
/*
	while(*argv) puts(rus(*argv++));

	puts("\nEnvironment variables:\n");
	while (*env) puts(*env++);
*/	
	printf(rus("Привет русскоязычным программистам %d раз!\n\n"), 510);

	for(i=0; i< argc; ++i)
		puts(rus(argv[i]));
	puts("\n");

	for(i=0; env[i] != NULL; ++i)
		puts(rus(env[i]));
	puts("\n");
	
}