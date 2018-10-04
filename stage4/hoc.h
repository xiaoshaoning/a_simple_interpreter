typedef struct Symbol
{
    char * name;
	short type;           /* VAR, BLTIN, UHDEF */
	union
	{
	    double val;
	    double (*ptr)();  /* if BLTIN */
	} u;
	struct Symbol * next; /* to link to another */
} Symbol;

Symbol * install(char *s, int t, double d);
Symbol * lookup(char *s);

typedef union Datum
{
    double val;
	Symbol * sym;
} Datum;

extern Datum pop();

typedef void (*Inst)();  /* interpreter stack type */
#define STOP (Inst) 0

extern Inst prog[];
extern void eval(), add(), sub(), mul(), division(), negate(), power();
extern void assign(), bltin(), varpush(), constpush(), print();

Inst *code(Inst f);
void init();
void initcode();
void execute(Inst *p);
void *emalloc(unsigned int n);
void yyerror(char *s, ...);
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();
int yylex();
