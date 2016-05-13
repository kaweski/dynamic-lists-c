/*
 ============================================================================
 Name        : DynamicList.c
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

int emptyList(DList* list);

/*
 * Inserts a char and return the memory address
 * of the previous pointer of the list.
 */
DList* insertChar(DList* list, char ch) {
	DList* aux;
	aux = (DList*) malloc(sizeof(DList));
	aux->data = ch; // Inserts the char value.
	aux->next = list; // Puts the memory address of the list at the auxiliary list pointer.
	return aux; // Returns the auxiliary pointer created.
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
 * Search a character within a list.
 */
DList* search(DList* list, char ch) {
	while ( emptyList(list) ) {
		if ( list->data == ch )
			return list; // Must return the address memory of a register.
		list = list->next;
	}
	return list; // Can be replaced by "NULL"
}

/*
 * Returns if a data belongs to the list or not.
 */
int belongs(DList* list, char ch) {
	while ( emptyList(list) ) {
		if ( list->data == ch ) // Check if the list have the char
			return 1; // If it belongs, returns true.
		list = list->next;
	}
	return 0; // If not, return false.
}

/*
 * Returns if the data value belongs to the list or not.
 * This function is the same as before,
 * but has just one line. :)
 */
int belongsRecursOneLine(DList* list, char ch) {
	return ( belongs(list->next, ch) && NULL );
}

/*
 * Checks if the list is empty or not,
 * and return a "boolean" value.
 */
int emptyList(DList* list) {
	if ( (list != NULL) )
		return 0;
	return 1;
}

/*
 * Removes the data value of the pointer.
 */
DList* removeChar(DList* list) {
	if ( !emptyList(list) ) {
		DList* aux = list;
		list = list->next;
		free(aux); // Removes the value
	}
	return list; // Returns the next pointer of the list.
}

/*
 * Removes the pointer where the chosen char is.
 */
DList* removeByChar(DList* list, char ch) {
	if ( !emptyList(list) ){
		DList* aux = list;
		DList* aux2 = list;

		if ( aux->data == ch ) {
			/*
			 * If the char of the current pointer is the char selected,
			 * it will be removed, calling the function that removes
			 * the data in memory.
			 */
			return removeChar(list);

		} else {
			while ( aux->next != NULL ) {
				// Checks the data value of next pointer.
				if ( aux->next->data == ch ) {
					// The auxiliary list receive the next pointer of the list.
					aux2 = aux->next;
					// The current pointer gets the next pointer of the following auxiliary pointer.
					aux->next = aux2->next;
					// Frees the data in memory of value selected.
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

/*
 * Removes the entire list.
 */
DList* freeList(DList* list) {
	DList* aux;
	while ( !emptyList(list) ) {
		aux = list;
		list = list->next; // Next pointer of the list.
		free(aux); // Frees the last pointer.
	}
	return list; // Returns the new pointer of the list.
}

/*
 * Removes the entire list,
 * but this function has less lines of code.
 */
DList* freeListLessLine(DList* list) {
	while(!emptyList(list)) // Checks if the list is empty.
		list = removeChar(list); // Store the new pointer made by the function removeChar()
	return list; // Returns this list when it exits the loop.
}

/*
 * Removes the entire list,
 * using recursive logic.
 */
DList* freeListRecursive(DList* list) {
	if ( !emptyList(list) ) {
		DList* aux = list;
		list = list->next;
		free(aux);

		// Returns the same function until the list is empty.
		return freeListRecursive(list);
	}
	return list;
}

/*
 * Removes the entire list,
 * using recursive logic,
 * with less lines of code.
 */
DList* freeListRecursiveLessLine(DList* list) {
	if ( !emptyList(list) )
		return freeListRecursiveLessLine( removeChar(list) );
	return list;
}

/*
 * Function turns the list in infinite loop.
 */
DList* loop(DList* list) {
	DList* aux = list;
	while ( aux->next != NULL ) {
		aux = aux->next;
	}
	aux->next = list; // Turns back to list.
	return list;
}

/*
 * Inverts the first two list data
 */
DList* invertTwoData(DList* list) {
	DList* aux = list;
	DList* aux2 = list->next;
	aux->next = aux2->next; // Gets the third list data
	aux2->next = aux; // Turns back to list.
	return aux2; // Returns a new list with the first data.
}

/*
 * Mixes two lists.
 */
DList* mixLists(DList* list1, DList* list2){
	DList* aux;
	DList* aux2;

	// Check if exists an empty list.
	if ( !emptyList(list1) ) {
		aux = list1;
		list1 = list1->next;
		aux2 = aux;

	} else if ( !emptyList(list2) ) {
		aux = list2;
		list2 = list2->next;
		aux2 = aux;

	} else {
		return NULL;
	}

	// Then mix the lists
	while( emptyList(list1) || emptyList(list2) ) {

		if ( emptyList(list2) ) {
			aux2->next = list2;
			list2 = list2->next;
			aux2 = aux2->next;
		}

		if ( emptyList(list1) ) {
			aux2->next = list1;
			list1 = list1->next;
			aux2 = aux2->next;
		}
	}

	return NULL;
}

int main(void) {

	DList* list1 = NULL;
	DList* list2 = NULL;
	DList* listMix = NULL;

	list1 = insertChar(list1,'C');
	list1 = insertChar(list1,'H');
	list1 = insertChar(list1,'E');
	list1 = insertChar(list1,'R');
	list1 = insertChar(list1,'R');
	list1 = insertChar(list1,'Y');

	list2 = insertChar(list2,'E');
	list2 = insertChar(list2,'C');
	list2 = insertChar(list2,'A');
	list2 = insertChar(list2,'F');

	listMix = mixLists(list1, list2);
	printList(listMix);

	return EXIT_SUCCESS;
}
