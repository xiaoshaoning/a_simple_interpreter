#include "hoc.h"
#include "y.tab.h"

static Symbol * symlist = 0; /* symbol table: linked list */

Symbol * lookup(char *s)
{
    Symbol * sp;
    
	for (sp = symlist; sp != (Symbol *)0; sp=sp->next)
	{
	    if (strcmp(sp->name, s) == 0)
		    return sp;
	}

    return 0;                /* 0 ==> not found */
}

Symbol * install(char * s, int t, double d)
{
    Symbol * sp;
	char * emalloc();

    sp = (Symbol *) emalloc(sizeof(Symbol));
	sp->name = emalloc(strlen(s)+1);
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.val = d;
	sp->next = symlist;
    symlist = sp;

	return sp;
}

char * emalloc(unsigned int n)          /* check return from malloc */
{
    char *p, *malloc();

    p = malloc(n);

	if (p == 0)
		printf("out of memory\n");

	return p;
}
