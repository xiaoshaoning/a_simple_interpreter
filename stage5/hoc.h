struct Symbol
{
    char * name;
	short type;           /* VAR, BLTIN, UHDEF */
	union
	{
	    double val;
	    double (*ptr)();  /* if BLTIN */
	} u;
	struct Symbol * next; /* to link to another */
};

union Datum
{
    double val;
	struct Symbol * sym;
};

typedef struct Symbol Symbol;
typedef union Datum Datum;

Symbol * install(char *s, int t, double d);
Symbol * lookup(char * s);

extern Datum pop();

typedef void (*Inst)();  /* interpreter stack type */

#define STOP (Inst)0

extern Inst prog[];
extern Inst * progp;
extern Inst * pc;

extern void eval(), add(), sub(), mul(), division(), negate(), power();
extern void assign(), bltin(), varpush(), constpush(), print();
extern void prexpr();
extern void gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern void ifcode(), whilecode();

Inst *code(Inst f);
void init();
void initcode();
void execute(Inst *p);
int follow(int expect, int ifyes, int ifno);
char *emalloc(unsigned int n);
void yyerror(char *s, ...);
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();
int yylex();
