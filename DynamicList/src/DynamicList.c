/*
 ============================================================================
 Name        : DynamicList.c
 Author      : Natasha Kaweski
 Version     : 2.0
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// List struct
typedef struct lista TLista;
struct lista {
	char dado;
	TLista *prox;
};

TLista* insere(TLista *lista, char ch);
//                    250 ->E->C->A->F->NULL
void imprime(TLista *lista);
TLista* busca (TLista* lista, char ch);
int pertence(TLista* lista, char ch);
//int vazia(TLista*);

// Função que retorna um ponteiro da letra anterior
TLista* insere(TLista *lista, char ch) {

	TLista *aux;
	aux = (TLista *) malloc( sizeof(TLista) );
	aux->dado = ch;
	aux->prox = lista;

	return aux;
}

// Função que imprime os dados do ponteiro
void imprime(TLista *lista) {
	while ( lista != NULL ) {
		printf("%c\n", lista->dado);
		lista = lista->prox;
	}
}

// Função que pesquisa o char dentor do ponteiro
TLista* busca(TLista* lista, char ch) {
	while ( lista != NULL ) {
		if ( lista->dado == ch )
			return lista; // Tem que retornar o endereço do registro

		lista = lista->prox;
	}
	return lista; // Pode ser substituido por NULL
}

// Função que retorna se o dado pertence ou não
int pertence(TLista* lista, char ch) {
	while ( lista != NULL ) {
		if ( lista->dado == ch )
			return 1;

		lista = lista->prox;
	}
	return 0;

//	return ( pertence(lista->prox, ch) && NULL );
}

// Função que verifica se a lista está vazia
int vazia(TLista* lista) {

	if ( (lista != NULL) )
		return 0;
	return 1;

}

// Função que remove o início da lista
TLista* removeIni(TLista* lista) {
	if ( !vazia(lista) ) {
		TLista* aux = lista;
		lista = lista->prox;
		free(aux);
	}

	return lista;
}

// Função que remove qualquer caractere
TLista* removeQQ(TLista* lista, char ch) {
	if ( !vazia(lista) ){
		TLista* aux = lista;
		TLista* aux2 = lista;

		if ( aux->dado == ch ) {
			return removeIni(lista);
		} else {
			while ( aux->prox != NULL ) {
				if ( aux->prox->dado == ch ) {
					aux2 = aux->prox;
					aux->prox = aux2->prox;
					free(aux2);
				} else {
					aux = aux->prox;
				}
			}
		}
	}
	return lista;
}

// Função que libera a lista inteira
TLista* libera(TLista* lista) {

// FUNÇÃO NORMAL

// 	Meu código


//	TLista* aux = lista;
//	while ( aux != NULL ) {
//		lista = aux->prox;
//		free(aux);
//		aux = lista->prox;
//	}
//	return aux;

// ++++++++++++++++++++++++
// ++++++++++++++++++++++++
// ++++++++++++++++++++++++

// Código do Xulambs

//	TLista* aux;
//	while ( !vazia(lista) ) {
// 		aux = lista;
//		lista = lista->prox;
//		free(aux);
//	}
//	return lista;

// ++++++++++++++++++++++++
// ++++++++++++++++++++++++
// ++++++++++++++++++++++++

//	while(!vazia(lista)){
//		lista = removeIni(lista);
//	}
//	return lista;

// ++++++++++++++++++++++++
// ++++++++++++++++++++++++
// ++++++++++++++++++++++++

// RECURSIVA

//	Código do Xulambs
//	if ( !vazia(lista) ) {
//		TLista* aux = lista;
//		lista = lista->prox;
//		free(aux);
//		return libera(lista);
//	}
//	// Caso base
//	return lista;

// 	Função melhorada
	if ( !vazia(lista) ) {
		return libera( removeIni(lista) );
	}
	return lista;

// 	Meu código

//	TLista* aux = lista;
//	if ( aux != NULL ) {
//		lista = lista->prox;
//		free(aux);
//		return libera( lista );
//	}
//	return lista;

}

// Função que coloca a lista em loop
//                   lista -> E -> C -> A -> F -> NULL
TLista* loop(TLista* lista) {

	TLista* aux = lista;

	while ( aux->prox != NULL ) {
		aux = aux->prox;
	}

	//aux ja esta no F
	aux->prox = lista;

	return lista;

}

// Função da prova que inverte os dois primeiros dados
TLista* invertePrimeiroSegundo(TLista* lista) {
	TLista* aux = lista;
	TLista* aux2 = lista->prox;

	// Inverte
	aux->prox = aux2->prox;
	aux2->prox = aux;

	return aux2;
}

// Função da prova que mescla as duas listas
TLista* mescla(TLista* lista1, TLista* lista2){
	TLista* aux;
	TLista* aux2;

	// Verifica se existe vazia
	if ( lista1 != NULL ) {
		aux = lista1;
		lista1 = lista1->prox;
		aux2 = aux;
	} else if ( lista2 != NULL ) {
		aux = lista2;
		lista2 = lista2->prox;
		aux2 = aux;
	} else
		return NULL;

	// Mescla
	while(lista1 != NULL || lista2 != NULL) {

		if ( lista2 != NULL ) {
			aux2->prox = lista2;
			lista2 = lista2->prox;
			aux2 = aux2->prox;
		}
		if ( lista1 != NULL ) {
			aux2->prox = lista1;
			lista1 = lista1->prox;
			aux2 = aux2->prox;
		}
	}

	// Escolhe o primeiro registro
}

int main(void) {
	TLista* listax = NULL;
	TLista* lista2 = NULL;

	listax = insere(listax,'C');
	listax = insere(listax,'E');
	listax = insere(listax,'M');
	listax = insere(listax,'U');
	listax = insere(listax,'F');

	lista2 = insere(listax,'E');
	lista2 = insere(listax,'C');
	lista2 = insere(listax,'A');
	lista2 = insere(listax,'F');

//	imprime(listax);
//	imprime(lista2);

	printf("\n----------------------------\n");
//	listax = mescla(listax, lista2);
	imprime(listax);
	imprime(lista2);

//	listax = invertePrimeiroSegundo(listax);
//	imprime(listax);

//	listax = removeIni(listax);
//	listax = removeQQ(listax, 'A');
//	imprime(listax);

//	listax = libera(listax);
//	imprime(listax);
//	listax = loop(listax);

//	imprime(listax);

	printf("\n----------------------------\n");

//	printf("Busca: %p\n\n", (busca(listax, 'F')));
//	printf("Pertence: %d\n\n", (pertence(listax, 'F')));
//	printf("Vazia: %d\n\n", (vazia(listax)));

	return EXIT_SUCCESS;
}
