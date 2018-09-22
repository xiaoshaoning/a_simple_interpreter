%{
double mem[26];
%}
%union {
    double val; /* actual value */
    int index;  /* index into mem[] */
}
%token <val>   NUMBER
%token <index> VAR
%type  <val>   expr
%right '='
%left  '+' '-'
%left  '*' '/'
%left  UNARYMINUS
%%
list:    /* nothing */
     | list '\n'
     | list expr '\n'     { printf("\t%f\n", $2); }
     ;
expr: NUMBER
      | VAR         	{$$ = mem[$1];}
      | VAR '='  expr   {$$ = mem[$1] = $3;}
      | expr '+' expr   {$$ = $1 + $3;}
      | expr '-' expr   {$$ = $1 - $3;}
      | expr '*' expr   {$$ = $1 * $3;}
      | expr '/' expr   {
                         if ($3 == 0.0)
                             printf("division by zero."); 
                         $$ = $1 / $3;}
      | '(' expr ')'    {$$ = $2;}
      | '-' expr %prec UNARYMINUS { $$ = -$2;}
      ;
%%
      /* end of grammar */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
int lineno = 1;
char * progname;

void main(int argc, char * argv[])
{
    int fpecatch();
    
    progname = argv[0];
    setjmp(begin);
    signal(SIGFPE, fpecatch);

    yyparse();
}

int fpecatch()
{
    printf("floating point exception.");
    longjmp(begin, 0);
    return 0;
}


int yylex()
{
    int c;

    while((c = getchar()) == ' ' || c == '\t')
    ;

    if (c == EOF)
        return 0;

    if ((c == '.') || isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%lf", &yylval.val);
        return NUMBER;
    }

    if (islower(c))
    {
        yylval.index = c - 'a';
        return VAR;
    }

    if (c == '\n')
        lineno++;

    return c;
}

int yyerror(char * message)
{
    
    warning(message);
    return 0;
}

void warning(char * s)
{
    fprintf(stderr, "%s, %s", progname, s);
    fprintf(stderr, " near line %d\n", lineno);
}
