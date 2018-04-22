#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilha_bib.h"

no_pilha * inicializa_no()
{
	no_pilha * no = malloc(sizeof(no_pilha));
	no->string = NULL;
	no->prox = NULL;
	return no;
}

// tentativa recursiva
void empilha(no_pilha ** pp_np, char * string)
{
	
	// caso base
	if((* pp_np) == NULL)
	{
	
		(* pp_np) = inicializa_no();
		(* pp_np)->string = malloc(strlen(string) + 1);
		strcpy((* pp_np)->string, string);
	}
	else
	{
		empilha(&(* pp_np)->prox, string);
	}
	return;
}

// tentativa recursiva
no_pilha * desempilha(no_pilha ** pp_np)
{
	// caso base 1
	if((* pp_np) == NULL)
		return NULL;
	// caso base 2
	if((* pp_np)->prox == NULL)
	{
		no_pilha * aux = (* pp_np);
		(* pp_np) = NULL;
		return aux;
	}
	else
	{
		return desempilha(&((* pp_np)->prox));
	}
}
