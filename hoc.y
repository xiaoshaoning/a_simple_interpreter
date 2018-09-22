%{
#define YYSTYPE double
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
list:    /* nothing */
     | list '\n'
     | list expr '\n' { printf("\t%f\n", $2); }
     ;
expr: NUMBER       {$$ = $1;}
      | expr '+' expr {$$ = $1 + $3;}
      | expr '-' expr {$$ = $1 - $3;}
      | expr '*' expr {$$ = $1 * $3;}
      | expr '/' expr {$$ = $1 / $3;}
      | '(' expr ')' {$$ = $2;}
      ;
%%
      /* end of grammar */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char * progname; /* for error message */
int lineno = 1;

void main(int argc, char * argv[])
{
    progname = argv[0];
    yyparse();
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
        scanf("%lf", &yylval);
        return NUMBER;
    }

    if (c == '\n')
        lineno++;

    return c;
}

int yyerror(char * message)
{
    
    warning(s);
    return 0;
}

void warning(char * s)
{
    fprintf(stderr, "%s, %s", progname, s);
    fprintf(stderr, " near line %d\n", lineno);
}
