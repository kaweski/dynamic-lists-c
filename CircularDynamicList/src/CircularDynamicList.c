/*
 ============================================================================
 Name        : LDC.c
 Author      : Natasha Kaweski
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista TLista;
struct lista {
	char dado;
	TLista* prox;
};

TLista* inicializa() {
	return NULL;
}

TLista* insereCirc(TLista *lista, char ch) {
	TLista *aux;
	aux = (TLista*) malloc( sizeof(TLista) );
	aux->dado = ch;

	if ( lista == NULL ) {
		aux->prox = aux;
	} else {
		aux->prox = lista;

		// Encontra o último registro
		TLista * aux2 = lista;

		do {
			aux2 = aux2->prox;
		} while ( aux2->prox != lista );

		// Returna pro último registro da lista (topo)
		aux2->prox = aux;
	}

	return aux;
}

void imprimeCirc(TLista* lista) {
	TLista *aux = lista;

	// Se a lista for vazia, não entra no loop
	if(aux)
	do {
		printf("lista --> %c\n", aux->dado);
		aux = aux->prox;
	} while ( aux != lista );
}

void imprime (TLista* lista) {
	while (lista != NULL) {
		printf( "lista--> %c\n", lista->dado );
		lista = lista->prox;
	}
}

int vaziaCirc(TLista* lista){
	return !lista;
}

TLista* buscaCirc(TLista* lista, char ch) {
	TLista *aux = lista;

	if(aux)
	do {
		if ( aux->dado == ch ) return aux;
		aux = aux->prox;
	} while ( aux != lista );

	return NULL;
}

TLista* liberaCirc(TLista* lista);

int main(void) {

	TLista *listac;
	listac = inicializa();

//	imprime(listac);

	listac = insereCirc(listac, 'F');
	listac = insereCirc(listac, 'A');
	listac = insereCirc(listac, 'C');
	listac = insereCirc(listac, 'E');

//	imprime(listac);

//	imprimeCirc(listac);

	printf("%d", buscaCirc(listac, 'J'));

	return EXIT_SUCCESS;

}
