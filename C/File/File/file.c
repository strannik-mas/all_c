//примеры работы с файлами
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXLEN		32
#define MAXGRADES	 3

typedef struct{
	char last_name[MAXLEN];
	int grade[MAXGRADES];
} student;

#define VAR 61

int main()
{
#if VAR==1
	//создание текстового файла (последовательного доступа)
	FILE *file = fopen("test1.txt", "wt");
	if(!file) {
		perror("test1.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	fputc('*', file);
	fputs("Hello, world!\n", file);
	fprintf(file, "%d\n", 2016);

	fclose(file);
#endif

#if VAR==2
	//чтение текстового файла известной структуры (последовательного доступа)
	FILE *file = fopen("test1.txt", "rt");
	int x;				//буфер для хранения читаемой информации
	char buf[256];		//символьный буфер для хранения строки текста

	if(!file) {
		perror("test1.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}


	x = fgetc(file); 					putchar(x);
	fgets(buf, sizeof buf, file);		fputs(buf, stdout);//puts(buf);
	fscanf(file, "%d", &x);				printf("%d\n", x);
	//puts добавляет от себя переход на новую строку
	fclose(file);
#endif
	//сделать, чтоб удалялись комменты
#if VAR==3
	//чтение текстового файла неизвестной структуры
	FILE *file = fopen("file.c", "rt");
	int x;				//буфер для хранения читаемой информации
	

	if(!file) {
		perror("file.c");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}
system("chcp 1251 > nul");
	/*while(!feof(file)) *///из-за этого и появляется ошибка
	while((x = fgetc(file))!=EOF)
	{
		putchar(x); //печатается лишний символ, т.к. fgetc печатает признак конца файла, а он отобр как пробел, т.е. цикл выполняется лишний раз
	}
	
	
	//puts добавляет от себя переход на новую строку
	fclose(file);
#endif

#if VAR==4
	//создание текстового файла (последовательного доступа) с записями


	student group[] = 
	{
		{"Ivanov",			{5,4,4}},
		{"Petrashevsky",	{4,3,4}},
		{"Kim",				{5,3,5}},
		{"Pupkin",			{4,2,3}},
		{"Kuzin",			{5,5,5}}
	};

	const int n = sizeof group/ sizeof *group;
	int i, j;


	FILE *file = fopen("test2.txt", "wt");
	if(!file) {
		perror("test2.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	for (i = 0; i < n; i++)
	{
		fprintf(file, "%s", group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d"/*не приклеится*/, group[i].grade[j]);
		}
		fprintf(file,"\n");
	}


	fclose(file);
#endif

#if VAR==5
	//редактирование текстового файла (последовательного доступа) с записями


	student x;
	int stud_id = 3,	//порядковый номер-индекс студента
		grade_id = 1,	//порядковый номер-индекс оценки, которую исправляем
		value = 3;
	int i, j;
	long pos;			//позиция курсора в файле
	//изменение записи в файле

	FILE *file = fopen("test2.txt", "r+t");
	if(!file) {
		perror("test2.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	for (i = 0; i <= stud_id; i++)
	{
		pos = ftell(file);
		fscanf(file, "%s", x.last_name);	//x.last_name - массив, т.е. адрес не ставим
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//или можно x.grade + j
		}
		fscanf(file, "\n");
	}

	x.grade[grade_id] = value;

	//нужно вернуть указатель на длину пупкина 
	fseek(file, pos/*+2 для того чтоб учесть перевод строки*/, SEEK_SET);
	fprintf(file, "%s", x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d"/*не приклеится*/, x.grade[j]);
	}
	

	fprintf(file,"\n");
	fclose(file);
#endif

#if VAR==6
	//создание текстового файла (прямого доступа) с записями
	//не работает пока 

	student group[] = 
	{
		{"Ivanov",			{5,4,4}},
		{"Petrashevsky",	{4,3,4}},
		{"Kim",				{5,3,5}},
		{"Pupkin",			{4,2,3}},
		{"Kuzin",			{5,5,5}}
	};
	student x;
	const int n = sizeof group/ sizeof *group;
	int i, j;
	long pos;
	int stud_id = 3,	//порядковый номер-индекс студента
		grade_id = 1,	//порядковый номер-индекс оценки, которую исправляем
		value = 3;

	FILE *file = fopen("test3.txt", "wt");
	if(!file) {
		perror("test3.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	/*pos = (MAXLEN + MAXGRADES*2 +2)*stud_id;
	fseek(file, pos, SEEK_SET);
	fscanf(file, "%s", x.last_name);	//x.last_name - массив, т.е. адрес не ставим
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//или можно x.grade + j
		}
		//fscanf(file, "\n");

	x.grade[grade_id] = value;
	fseek(file, pos, SEEK_SET);*/

	for (i = 0; i < n; i++)
	{
		fprintf(file, "%-*s", MAXLEN, group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d"/*не приклеится*/, group[i].grade[j]);
		}
		fprintf(file,"\n");
	}


	fclose(file);
#endif

#if VAR==61
	//редактирование текстового файла (прямого доступа) с записями


	student x;
	int i, j;
	long pos;
	int stud_id = 3,	//порядковый номер-индекс студента
		grade_id = 1,	//порядковый номер-индекс оценки, которую исправляем
		value = 3;

	FILE *file = fopen("test3.txt", "r+t");
	if(!file) {
		perror("test3.txt");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	pos = stud_id * (MAXLEN + MAXGRADES * 2 + 2);
	fseek(file, pos, SEEK_SET);
	fscanf(file, "%s", x.last_name);	//x.last_name - массив, т.е. адрес не ставим
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//или можно x.grade + j
		}
		fscanf(file, "\n");

	x.grade[grade_id] = value;
	fseek(file, pos, SEEK_SET);

	fprintf(file, "%-*s", MAXLEN, x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d"/*не приклеится*/, x.grade[j]);
	}
	fprintf(file,"\n");


	fclose(file);
#endif

#if VAR==7
	//создание бинарного файла (прямого доступа) с записями

	student group[] = 
	{
		{"Ivanov",			{5,4,4}},
		{"Petrashevsky",	{4,3,4}},
		{"Kim",				{5,3,5}},
		{"Pupkin",			{4,2,3}},
		{"Kuzin",			{5,5,5}}
	};
	const int n = sizeof group/ sizeof *group;
	

	FILE *file = fopen("test4.dat", "wb");
	if(!file) {
		perror("test4.dat");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}
	
	fwrite(&n, sizeof (int), 1 , file);	//записываем число записей в файл
	fwrite(group, sizeof (student), n , file);

	fclose(file);
#endif

#if VAR==8
	//редактирование бинарного файла (прямого доступа) с записями

	student x;
	int stud_id = 3,	//порядковый номер-индекс студента
		grade_id = 1,	//порядковый номер-индекс оценки, которую исправляем
		value = 5;
	long pos;			//позиция курсора в файле
	//изменение записи в файле

	FILE *file = fopen("test4.dat", "r+b");
	if(!file) {
		perror("test4.dat");
		exit(1);				//1-значение, которое вернет main в случае аварийного завершения
	}

	pos = sizeof(int) + stud_id * sizeof(student);	//продвинули для количества записей
	fseek(file, pos, SEEK_SET);
	fread(&x, sizeof(student), 1, file); //прочитана информация об одном пупкине
	

	x.grade[grade_id] = value;

	
	fseek(file, pos, SEEK_SET);
	fwrite(&x, sizeof(student), 1, file); 
	fclose(file);
#endif
}