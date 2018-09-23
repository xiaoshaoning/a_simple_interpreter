typedef struct Symbol /*symbol table entry */
{
    char * name;
	short  type;      /* VAR, BLTIN, UNDEF */
    union
	{
	    double val;   /* if VAR */
		double (*ptr)();  /* if BLTIN */
	} u;
  
    struct Symbol * next; /* to link to another */
} Symbol;

Symbol * install(char *s, int t, double d);
Symbol * lookup(char *s);

char *emalloc(unsigned int n);
void yyerror(char *s);
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();
int yylex();
