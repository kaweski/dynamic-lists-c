/*
 ============================================================================
 Name        : CircularDynamicList.c
 Author      : Natasha Kaweski
 Version     : 1.2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list DList;
struct list {
	char data;
	DList* next;
};

/*
 * Starts a list (because any pointer list can start without an value).
 * NULL is a start value to receive other values, as char data values.
 */
DList* startList() {
	return NULL;
}

/*
 * Insert char data values to the list
 * and makes it circular.
 */
DList* insertChar(DList* list, char ch) {
	DList* aux;
	aux = (DList*) malloc(sizeof(DList));
	aux->data = ch;

	if ( list == NULL ) {
		aux->next = aux;
	} else {
		aux->next = list;
		DList* aux2 = list; // Find the last register

		// Make the list circular.
		do {
			aux2 = aux2->next;
		} while ( aux2->next != list );

		/* Return to the last register
		 * at the top of the list. */
		aux2->next = aux;
	}
	return aux; // Top of the list
}

/*
 * Print the values of a circular list.
 */
void printList(DList* list) {
	DList* aux = list;

	// If the list is empty, it doesn't enter the loop
	if(aux) {
		do {
			printf( "List: %c\n", aux->data );
			aux = aux->next;
		} while ( aux != list ); // Exit the loop
	}
}

/*
 * Prints an infinite loop with all the data values inserted
 */
void infinitePrint(DList* list) {
	while (list != NULL) { // Never enters here until the list is really empty
		printf( "List: %c\n", list->data );
		list = list->next;
	}
}

/*
 * Return if the list is empty.
 */
int emptyList(DList* list){
	return !list;
}

/*
 * Search the char param data, and if it finds
 * return its memory address
 */
DList* searchChar(DList* list, char ch) {
	DList* aux = list;

	if(aux) {
		do {
			if ( aux->data == ch ) return aux;
			aux = aux->next;
		} while ( aux != list );  // Exit the loop
	}
	return NULL; // If is doesn't find the char, it returns nothing
}

/*
 * Free space in memory and clean the list.
 */
DList* freeList(DList* list) {

	DList* aux;

	if ( !emptyList(list) && !emptyList(list->next) ) {
		aux = list->next;
		free(list);
		return freeList(aux);
	}
	// Return the memory address list.
	return list;
}

int main(void) {

	DList *mainList;
	mainList = startList(); // Starts the list with NULL value

	mainList = insertChar(mainList, 'C');
	mainList = insertChar(mainList, 'H');
	mainList = insertChar(mainList, 'E');
	//mainList = insertChar(mainList, 'R');
	//mainList = insertChar(mainList, 'R');
	//mainList = insertChar(mainList, 'Y');

	//printList(mainList);
	// printf("\n\nSearch result: %p\n\n", searchChar(mainList, 'A'));

	mainList = freeList(mainList);
	printList(mainList);

	return EXIT_SUCCESS;
}
