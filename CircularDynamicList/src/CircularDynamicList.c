/*
 ============================================================================
 Name        : CircularDynamicList.c
 Author      : Natasha Kaweski
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

	if ( !emptyList(list) ) {

		DList* aux = list->next; // Next value
		DList* aux2 = aux;

		while ( aux != list ) { // Checks if auxiliary variable is equal to list
			aux2 = aux;
			aux = aux->next;
			free(aux2);
			list->next = aux;
		}

		free(aux);
	}
	return list;
}

/*
 * Remove any pointer.
 */
DList* freeListChar(DList* list, char ch) {

	if ( emptyList(list) )
		return list;

	DList* aux = list;
	DList* aux2;

	/* If his next value is the same address as list, it has just one register
	 * and if the char is the same as the char inside the list, it's the
	 * value we need to free from memory.
	 * */
	if ( aux->data == ch && aux->next == list ) {
		list = startList();
		free(aux);

	} else if ( aux->data == ch && aux->next != list ) { // Check if it is the first element of the list.
		aux2 = list;
		do {
			aux2 = aux2->next;
		} while ( aux2->next != list ); // Finds the last register of the list.

		list = list->next; // Changes the list address

	// Removing any other char
	} else {

		do {
			// Checks the data value of next pointer.
			if ( aux->next->data == ch ) {
				// The auxiliary list receive the next pointer of the list.
				aux2 = aux->next;
				// The current pointer gets the next pointer of the following auxiliary pointer.
				aux->next = aux2->next; // Or use aux->prox->prox
				// Frees the data in memory of value selected.
				free(aux2);
			} else {
				aux = aux->next;
			}
		} while ( aux->next != list );
	}
	return list;
}

int main(void) {

	DList* mainList;
	mainList = startList(); // Starts the list with NULL value

	mainList = insertChar(mainList, 'C');
	//mainList = insertChar(mainList, 'H');
	//mainList = insertChar(mainList, 'E');
	//mainList = insertChar(mainList, 'R');
	//mainList = insertChar(mainList, 'R');
	//mainList = insertChar(mainList, 'Y');

	printList(mainList);

	mainList = freeListChar(mainList, 'C');

	printf("Remove: \n");
	printList(mainList);

	return EXIT_SUCCESS;
}
