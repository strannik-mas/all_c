#include<stdlib.h>
#include<stdio.h>
#include"menu.h"
#include"in_out.h"
#include"save_to_bin_file.h"
#include"load.h"
#include"sort.h"
#include"do_it.h"

int main()
{
	menu_item list[] = 
	{
		{"����", input},
		{"�����", output},
		{"�����������", sort_by_name},
		{"��������� �����������", process_all},
		{"���������", save},
		{"���������", load}
	};


	system("chcp 1251 > nul");
	menu(list, sizeof list / sizeof *list);	
	system("pause");
}