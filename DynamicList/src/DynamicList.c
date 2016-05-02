/*
 ============================================================================
 Name        : DynamicList.c
 Author      : Natasha Kaweski
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list DList;
struct list {
	char data;
	DList* next;
};

int emptyList(DList* list);

/*
 * Insert a char and return the memory address
 * of the before pointer of the list.
 */
DList* insertChar(DList* list, char ch) {
	DList* aux;
	aux = (DList*) malloc(sizeof(DList*));
	aux->data = ch; // Insert the char value.
	aux->next = list; // Put the memory address of the list at the auxiliar list pointer.

	// Return the auxiliar pointer created.
	return aux;
}

/*
 * Prints the data values of the list.
 */
void printList(DList* list) {
	while ( emptyList(list) ) {
		printf("List: %c\n", list->data);
		list = list->next;
	}
}

/*
 * Search a char inside a pointer list
 */
DList* search(DList* list, char ch) {
	while ( emptyList(list) ) {
		if ( list->data == ch )
			return list; // Must return the register address memory.
		list = list->next;
	}
	return list; // Can be placed by an "NULL"
}

/*
 * Returns if the data value belongs to the list or not.
 */
int belongs(DList* list, char ch) {
	while ( emptyList(list) ) {
		if ( list->data == ch ) // Check of the list has the char
			return 1; // If belongs, return true.
		list = list->next;
	}
	return 0; // If it's not, return false.
}

/*
 * Return if the data value belongs to the list or not.
 * This function is the same as before,
 * but has just one line. :)
 */
int belongsRecursOneLine(DList* list, char ch) {
	return ( belongs(list->next, ch) && NULL );
}

/*
 * Check if the list is empty or not,
 * and return a "boolean" value.
 */
int emptyList(DList* list) {
	if ( (list != NULL) )
		return 0;
	return 1;
}

/*
 * Remove the data value of the pointer selected.
 */
DList* removeChar(DList* list) {
	if ( !emptyList(list) ) {
		DList* aux = list;
		list = list->next;
		free(aux); // Remove the value
	}
	return list; // Return the next pointer of the list.
}

/*
 * Remove the pointer where the char selected is.
 */
DList* removeByChar(DList* list, char ch) {
	if ( !emptyList(list) ){
		DList* aux = list;
		DList* aux2 = list;

		if ( aux->data == ch ) {
			/*
			 * If the char of the current pointer is the char selected,
			 * it will be removed, calling the function that removes
			 * memory allocation.
			 */
			return removeChar(list);

		} else {
			while ( aux->next != NULL ) {
				// Check the next pointer data value.
				if ( aux->next->data == ch ) {

					// Auxiliar pointer list receive the next pointer of the list.
					aux2 = aux->next;

					// The actual pointer receive the next pointer of the next auxiliar pointer.
					aux->next = aux2->next;

					// Free the memory allocation of the data value selected.
					free(aux2);
				} else {
					aux = aux->next;
				}
			}
		}
	}

	// Returns the new list.
	return list;
}

// Função que libera a lista inteira
DList* libera(DList* list) {

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
	if ( !vazia(list) ) {
		return libera( removeChar(list) );
	}
	return list;

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
DList* loop(DList* list) {

	DList* aux = list;

	while ( aux->next != NULL ) {
		aux = aux->next;
	}

	//aux ja esta no F
	aux->next = list;

	return list;

}

// Função da prova que inverte os dois primeiros dados
DList* invertePrimeiroSegundo(DList* list) {
	DList* aux = list;
	DList* aux2 = list->next;

	// Inverte
	aux->next = aux2->next;
	aux2->next = aux;

	return aux2;
}

// Função da prova que mescla as duas listas
DList* mescla(DList* list1, DList* list2){
	DList* aux;
	DList* aux2;

	// Verifica se existe vazia
	if ( list1 != NULL ) {
		aux = list1;
		list1 = list1->next;
		aux2 = aux;
	} else if ( list2 != NULL ) {
		aux = list2;
		list2 = list2->next;
		aux2 = aux;
	} else
		return NULL;

	// Mescla
	while(list1 != NULL || list2 != NULL) {

		if ( list2 != NULL ) {
			aux2->next = list2;
			list2 = list2->next;
			aux2 = aux2->next;
		}
		if ( list1 != NULL ) {
			aux2->next = list1;
			list1 = list1->next;
			aux2 = aux2->next;
		}
	}

	// Escolhe o primeiro registro
}

int main(void) {
	DList* listax = NULL;
	DList* lista2 = NULL;

	listax = insertChar(listax,'C');
	listax = insertChar(listax,'E');
	listax = insertChar(listax,'M');
	listax = insertChar(listax,'U');
	listax = insertChar(listax,'F');

	lista2 = insertChar(listax,'E');
	lista2 = insertChar(listax,'C');
	lista2 = insertChar(listax,'A');
	lista2 = insertChar(listax,'F');

//	imprime(listax);
//	imprime(lista2);

	printf("\n----------------------------\n");
//	listax = mescla(listax, lista2);
	printList(listax);
	printList(lista2);

//	listax = invertePrimeiroSegundo(listax);
//	imprime(listax);

//	listax = removeChar(listax);
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
