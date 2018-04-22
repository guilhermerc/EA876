#ifndef PILHA_H
#define PILHA_H

typedef struct no_pilha
{
	char * string;
	struct no_pilha * prox;
}
no_pilha;

void empilha(no_pilha ** np, char * string);
no_pilha * desempilha(no_pilha ** pp_np);
no_pilha * inicializa_no();

#endif
