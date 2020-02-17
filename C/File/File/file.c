//������� ������ � �������
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
	//�������� ���������� ����� (����������������� �������)
	FILE *file = fopen("test1.txt", "wt");
	if(!file) {
		perror("test1.txt");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	fputc('*', file);
	fputs("Hello, world!\n", file);
	fprintf(file, "%d\n", 2016);

	fclose(file);
#endif

#if VAR==2
	//������ ���������� ����� ��������� ��������� (����������������� �������)
	FILE *file = fopen("test1.txt", "rt");
	int x;				//����� ��� �������� �������� ����������
	char buf[256];		//���������� ����� ��� �������� ������ ������

	if(!file) {
		perror("test1.txt");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}


	x = fgetc(file); 					putchar(x);
	fgets(buf, sizeof buf, file);		fputs(buf, stdout);//puts(buf);
	fscanf(file, "%d", &x);				printf("%d\n", x);
	//puts ��������� �� ���� ������� �� ����� ������
	fclose(file);
#endif
	//�������, ���� ��������� ��������
#if VAR==3
	//������ ���������� ����� ����������� ���������
	FILE *file = fopen("file.c", "rt");
	int x;				//����� ��� �������� �������� ����������
	

	if(!file) {
		perror("file.c");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}
system("chcp 1251 > nul");
	/*while(!feof(file)) *///��-�� ����� � ���������� ������
	while((x = fgetc(file))!=EOF)
	{
		putchar(x); //���������� ������ ������, �.�. fgetc �������� ������� ����� �����, � �� ����� ��� ������, �.�. ���� ����������� ������ ���
	}
	
	
	//puts ��������� �� ���� ������� �� ����� ������
	fclose(file);
#endif

#if VAR==4
	//�������� ���������� ����� (����������������� �������) � ��������


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
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	for (i = 0; i < n; i++)
	{
		fprintf(file, "%s", group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d"/*�� ����������*/, group[i].grade[j]);
		}
		fprintf(file,"\n");
	}


	fclose(file);
#endif

#if VAR==5
	//�������������� ���������� ����� (����������������� �������) � ��������


	student x;
	int stud_id = 3,	//���������� �����-������ ��������
		grade_id = 1,	//���������� �����-������ ������, ������� ����������
		value = 3;
	int i, j;
	long pos;			//������� ������� � �����
	//��������� ������ � �����

	FILE *file = fopen("test2.txt", "r+t");
	if(!file) {
		perror("test2.txt");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	for (i = 0; i <= stud_id; i++)
	{
		pos = ftell(file);
		fscanf(file, "%s", x.last_name);	//x.last_name - ������, �.�. ����� �� ������
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//��� ����� x.grade + j
		}
		fscanf(file, "\n");
	}

	x.grade[grade_id] = value;

	//����� ������� ��������� �� ����� ������� 
	fseek(file, pos/*+2 ��� ���� ���� ������ ������� ������*/, SEEK_SET);
	fprintf(file, "%s", x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d"/*�� ����������*/, x.grade[j]);
	}
	

	fprintf(file,"\n");
	fclose(file);
#endif

#if VAR==6
	//�������� ���������� ����� (������� �������) � ��������
	//�� �������� ���� 

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
	int stud_id = 3,	//���������� �����-������ ��������
		grade_id = 1,	//���������� �����-������ ������, ������� ����������
		value = 3;

	FILE *file = fopen("test3.txt", "wt");
	if(!file) {
		perror("test3.txt");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	/*pos = (MAXLEN + MAXGRADES*2 +2)*stud_id;
	fseek(file, pos, SEEK_SET);
	fscanf(file, "%s", x.last_name);	//x.last_name - ������, �.�. ����� �� ������
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//��� ����� x.grade + j
		}
		//fscanf(file, "\n");

	x.grade[grade_id] = value;
	fseek(file, pos, SEEK_SET);*/

	for (i = 0; i < n; i++)
	{
		fprintf(file, "%-*s", MAXLEN, group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d"/*�� ����������*/, group[i].grade[j]);
		}
		fprintf(file,"\n");
	}


	fclose(file);
#endif

#if VAR==61
	//�������������� ���������� ����� (������� �������) � ��������


	student x;
	int i, j;
	long pos;
	int stud_id = 3,	//���������� �����-������ ��������
		grade_id = 1,	//���������� �����-������ ������, ������� ����������
		value = 3;

	FILE *file = fopen("test3.txt", "r+t");
	if(!file) {
		perror("test3.txt");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	pos = stud_id * (MAXLEN + MAXGRADES * 2 + 2);
	fseek(file, pos, SEEK_SET);
	fscanf(file, "%s", x.last_name);	//x.last_name - ������, �.�. ����� �� ������
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);	//��� ����� x.grade + j
		}
		fscanf(file, "\n");

	x.grade[grade_id] = value;
	fseek(file, pos, SEEK_SET);

	fprintf(file, "%-*s", MAXLEN, x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d"/*�� ����������*/, x.grade[j]);
	}
	fprintf(file,"\n");


	fclose(file);
#endif

#if VAR==7
	//�������� ��������� ����� (������� �������) � ��������

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
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}
	
	fwrite(&n, sizeof (int), 1 , file);	//���������� ����� ������� � ����
	fwrite(group, sizeof (student), n , file);

	fclose(file);
#endif

#if VAR==8
	//�������������� ��������� ����� (������� �������) � ��������

	student x;
	int stud_id = 3,	//���������� �����-������ ��������
		grade_id = 1,	//���������� �����-������ ������, ������� ����������
		value = 5;
	long pos;			//������� ������� � �����
	//��������� ������ � �����

	FILE *file = fopen("test4.dat", "r+b");
	if(!file) {
		perror("test4.dat");
		exit(1);				//1-��������, ������� ������ main � ������ ���������� ����������
	}

	pos = sizeof(int) + stud_id * sizeof(student);	//���������� ��� ���������� �������
	fseek(file, pos, SEEK_SET);
	fread(&x, sizeof(student), 1, file); //��������� ���������� �� ����� �������
	

	x.grade[grade_id] = value;

	
	fseek(file, pos, SEEK_SET);
	fwrite(&x, sizeof(student), 1, file); 
	fclose(file);
#endif
}