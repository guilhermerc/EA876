%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha_bib.h"

no_pilha * pilha;

void yyerror(char * s);
int yylex(void);

%}

%token MENOR MAIOR BARRA TEXTO

%union
{
	char * s;
	float f;
}
%%

PROGRAMA:
	
	PROGRAMA CADEIA
	|
	;

TAG_ABRE:
	
	MENOR TEXTO MAIOR
	{
		//printf("YACC: TAG_ABRE\n");
		printf("0\n");
		printf("%s\n", yylval.s);
		printf("0!\n");
		//empilha(&pilha, yylval.s);
	}

TAG_FECHA:
	
	MENOR BARRA TEXTO MAIOR
	{
		printf("2\n");
		//printf("%s\n", yylval.s);
		//no_pilha * aux = desempilha(&pilha);
		//printf("%s\n", aux->string);
	}

CONTEUDO:

	TEXTO
	{
		printf("1\n");
		printf("%s\n", yylval.s);
		printf("1!\n");
		//printf("YACC: CONTEUDO\n");
	}
	| CADEIA
	{
		//printf("YACC: CONTEUDO\n");
	}
	| CONTEUDO CADEIA
	{
		//printf("YACC: CONTEUDO\n");
	}

CADEIA:

	TAG_ABRE CONTEUDO TAG_FECHA 
	{
		//printf("YACC: CADEIA\n");
	}
	| TAG_ABRE TAG_FECHA

%%

void yyerror(char * s)
{
	// printf("Meu erro foi: %s\n", s);
}

int main()
{
  	yyparse();
	return 0;
}
