#include "hoc.h"
#include "y.tab.h"
#include <math.h>

extern double Log(), Log10(), Exp(), Sqrt(), integer();

static struct
{
    char * name;
	double cval;
} consts[] = {
    "PI", 3.14159265358979323846,
	"E" , 2.71828182845904523536,
	"GAMMA", 0.57721566490153286060,  /* Euler */
	"DEG", 57.29577951308232087680,   /* deg/radian */
	"PHI", 1.61803398874989484820,    /* golden ratio */
	0, 0
};

static struct {
    char * name;
	double (*func)();
} builtins[] = {
    "sin", sin,
	"cos", cos,
	"atan", atan,
	"log", Log,
	"log10", Log10,
	"exp", Exp,
	"sqrt", Sqrt,
	"int", integer,
    "abs", fabs,
	0, 0
};

void init()                          /* install constants and built-ins in table */
{
    int ii;
	Symbol *s;
	
	for(ii = 0; consts[ii].name; ii++)
	{
	    install(consts[ii].name, VAR, consts[ii].cval);
	}

    for(ii = 0; builtins[ii].name; ii++)
	{
	    s = install(builtins[ii].name, BLTIN, 0.0);
		s->u.ptr = builtins[ii].func;
	}
}
