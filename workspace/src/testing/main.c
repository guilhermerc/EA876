#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_bib.h"

int main()
{	
	no_pilha * pilha = NULL;
	empilha(&pilha, "Teste 00");
	empilha(&pilha, "Teste 01");
	empilha(&pilha, "Teste 02");
	empilha(&pilha, "Teste 03");
	desempilha(&pilha);
	desempilha(&pilha);
	desempilha(&pilha);
	desempilha(&pilha);
	return 0;
}
