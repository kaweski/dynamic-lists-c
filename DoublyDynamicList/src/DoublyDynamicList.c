/*
 ============================================================================
 Name        : DoublyDynamicList.c
 Author      : Natasha Kaweski
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list DList;
struct list {
	DList* prev;
	char data;
	DList* next;
};

int emptyList(DList* list);

/*
 * Starts the list
 */
DList* startList() {
	return NULL;
}

DList* insertList(DList* list, char ch) {

	DList* aux;
	aux = (DList*) malloc(sizeof(DList)); // Creates a new pointer
	aux->prev = NULL; // Sets the first value of the list
	aux->data = ch; // Sets the char value
	aux->next = list; // Links the next pointer to list

	if ( !emptyList(list) ) // And if the list is not empty, it links to aux too.
		list->prev = aux;

	return aux;
}

/*
 * Prints the list
 */
void printList(DList* list) {
	while ( !emptyList(list) ) {
		printf("List: %c\n", list->data);
		list = list->next;
	}
}

/*
 * Checks if the list is empty
 */
int emptyList(DList* list) {
	if ( (list != NULL) )
		return 0;
	return 1;
}

/*
 * Searchs a char in the list
 */
DList* searchList(DList* list, char ch) {
	while ( emptyList(list) ) {
		if ( list->data == ch )
			return list; // Must return the address memory of a register.
		list = list->next;
	}
	return list; // Can be replaced by "NULL"
}

// DList* freeList(DList* list)
// DList* removeChar(DList* list, char ch);

int main(void) {

	DList* mainList;
	mainList = startList();

	mainList = insertList(mainList, 'F');
	mainList = insertList(mainList, 'A');
	mainList = insertList(mainList, 'C');
	mainList = insertList(mainList, 'E');

	printList(mainList);

	printf("%c\n", mainList->next->next->next->prev->prev->prev->data);

	return 0;
}
