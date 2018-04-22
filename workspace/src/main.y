%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha_bib.h"

no_pilha * pilha;

void yyerror(char * s);
int yylex(void);

struct informacoes
{
	char * municipio_gerador;
	char * municipio_prestador;
	char * valor_do_servico;
	char * iss_retido;
};
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
		printf("YACC: TAG_ABRE\n");
		printf("Empilhando %s\n", yylval.s);
		empilhar(&pilha, yylval.s);
	}

TAG_FECHA:
	
	MENOR BARRA TEXTO MAIOR
	{
		printf("YACC: TAG_FECHA\n");
		no_pilha * aux = desempilhar(&pilha);
		printf("Desempilhando %s\n", aux->string);
	}

CONTEUDO:

	TEXTO
	{
		printf("YACC: CONTEUDO\n");
	}
	| CADEIA
	{
		printf("YACC: CONTEUDO\n");
	}
	| CONTEUDO CADEIA
	{
		printf("YACC: CONTEUDO\n");
	}

CADEIA:

	TAG_ABRE CONTEUDO TAG_FECHA 
	{
		printf("YACC: CADEIA\n");
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
