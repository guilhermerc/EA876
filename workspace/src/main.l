%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

void yyerror(char * s);
%}

%%

\<	{
		//printf("FLEX: <\n");
		return MENOR;
	}

\>	{
		//printf("FLEX: >\n");
		return MAIOR;
	}

[/]	{
		//printf("FLEX: /\n");
		return BARRA;
	}

[\n\ \t]+	;	

[^\<^\>^/][^\<^\>]*	{
				//printf("FLEX: %s\n", yytext);
				yylval.s = strdup(yytext);
				return TEXTO;
			}	


.	;

%%

int yywrap()
{
	return 1;
}
