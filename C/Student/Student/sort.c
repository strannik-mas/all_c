#include<stdlib.h>
#include<string.h>

#include"data.h"
#include"sort.h"

static int name_cmp(const void *e1, const void *e2)
{
	return strcmp(((const student *)e1)->last_name,
					((const student *)e2)->last_name);
}


int sort_by_name(student *pstud, int nstud)
{
	qsort(pstud, nstud, sizeof(student), name_cmp);
	
	return nstud;
}