#ifndef _DIDATIC_GAME_LIST_H_
#define _DIDATIC_GAME_LIST_H_

#include "definitions/global.h"

typedef struct _List List;
typedef struct _Node Node;

typedef struct _ListIterator {
    void *data;
    Node *currentNode;
} ListIterator;

/**
 * Result codes for list operations
 * Codes smaller than 0 means ERROR
 * Codes greater than 0 means WARNING
 * 0 means OK
 */
typedef enum _ListResultCode {

/* *** ERROR CODES *** */

    // Memory error code
    LIST_OUT_OF_MEMORY = -1999, /**< List operation failed due to lack of memory */

    // Generic error code
    LIST_OUT_OF_BOUNDS = -999, /**< List operation range out of bounds */
    LIST_FAIL = -1, /**< List operation failed */

/* *** SUCCESS CODE *** */

    // Generic success code
    LIST_OK = 0, /**< List operation succeed */

/* *** WARNING CODES *** */

    // Warning codes related to removing elements
    LIST_REMOVE_ALREADY_EMPTY = 9000, /**< Remove operation not performed due to list is already empty */

    // Warning codes related to searching elements
    LIST_FIND_NOT_FOUND = 7000, /**< Element is not in the list */
    LIST_ITERATOR_BEGIN_REACHED, /**< Iterator has reached the beginning of the list */
    LIST_ITERATOR_END_REACHED /**< Iterator has reached the end of the list */

} ListResultCode;

typedef enum _ListRelativePosition {
    LIST_BEFORE, /**< Insert before current node */
    LIST_AFTER, /**< Insert after current node */
    LIST_REPLACE /**< Replace current node data */
} ListRelativePosition;

/**
 * @brief Create an empty list and return its memory address
 * 
 * This function creates an empty list and return its address.
 * The caller of this function is responsible for calling #listDestroy
 * to deallocate it
 * 
 * @return On success returns the address of the List structure
 * @return Returns NULL otherwise
 */
List* listCreate(void);

/**
 * @brief Destroy a List and clean its allocated memory
 * 
 * This function destroys the List passed and clean up the memory
 * that was being allocated by the list
 * 
 * @param list The address of the list to be destroyed
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_FAIL if unable to destroy the list
 */
ListResultCode listDestroy(List *list);

/**
 * @brief Get the number of elements in the list
 * 
 * @param list The address of the list from which to get
 * the number of elements
 * 
 * @return On success returns the numbers of elements in the list
 * @return Returns 0 if it fails
 */
unsigned long listGetElementsCount(List *list);

/**
 * @brief Get an iterator for the first element
 * 
 * @param list The address of the list to get the first element
 * @param iterator The address of a pointer of ListIterator where to store
 * the result ListIterator address
 * 
 * @return On success returns LIST_OK and sets @p iterator with iterator for first element
 * @return On element not found returns LIST_FIND_NOTFOUND
 * @return On other errros returns LIST_FAIL
 */
ListResultCode listGetBegin(List *list, ListIterator **iterator);

/**
 * @brief Get an iterator for the last element
 * 
 * @param list The address of the list to get the last element
 * @param iterator The address of a pointer of ListIterator where to store
 * the result ListIterator address
 * 
 * @return On success returns LIST_OK and sets @p iterator with iterator for last element
 * @return On element not found returns LIST_FIND_NOTFOUND
 * @return On other errros returns LIST_FAIL
 */
ListResultCode listGetEnd(List *list, ListIterator **iterator);

/**
 * @brief Find an element in the given position
 * 
 * @param list The address of the list to search for an element
 * @param position The position to be found in the list
 * @param iterator The address of a pointer of ListIterator where to store
 * the result ListIterator address
 * 
 * @return On success returns LIST_OK and sets @p iterator with the result iterator
 * @return On element not found returns LIST_FIND_NOTFOUND
 * @return On other errros returns LIST_FAIL
 */
ListResultCode listFindElement(List *list, unsigned long position, ListIterator **iterator);

/**
 * @brief Updates iterator with next element
 * 
 * @param iterator Pointer to a ListIterator which will be moved forward
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_ITERATOR_END_REACHED if iterator has reached the last element
 * @return On other errros returns LIST_FAIL
 */
ListResultCode listMoveNext(ListIterator *iterator);

/**
 * @brief Updates iterator with previous element
 * 
 * @param iterator Pointer to a ListIterator which will be moved backward
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_ITERATOR_BEGIN_REACHED if iterator has reached the first element
 * @return On other errros returns LIST_FAIL
 */
ListResultCode listMoveBack(ListIterator *iterator);

/**
 * @brief Insert an element in the list at the current position of the given iterator
 *
 * Once an element is inserted in the list, its ownership is transferred
 * to the list. It will be removed from memory in operations like
 * #listRemoveAll, #listRemoveFromIndex or #listRemove
 *
 * @param list The address of the list to which the element
 * must be inserted
 * @param iterator An iterator holding the position where to insert
 * the element. The element will be inserted before the current element pointed
 * by the iterator
 * @param element A pointer to the memory that holds the element
 * to be inserted
 *
 * @return On success returns LIST_OK
 * @return Returns LIST_OUT_OF_MEMORY if failed to allocate memory for new node
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listInsert(List *list, ListIterator *iterator, ListRelativePosition relativePos, void *element);

/**
 * @brief Insert an element in the list at a given position
 * 
 * Once an element is inserted in the list, its ownership is transferred
 * to the list. It will be removed from memory in operations like
 * #listRemoveAll, #listRemoveFromIndex or #listRemove
 * 
 * @param list The address of the list to which the element
 * must be inserted
 * @param position The position in the list in which the element
 * must be inserted
 * @param element A pointer to the memory that holds the element
 * to be inserted
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_INSERT_OUT_OF_BOUNDS if trying to insert
 * in invalid position in list
 * @return Returns LIST_OUT_OF_MEMORY if failed to allocate memory for new node
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listInsertAtIndex(List *list, unsigned long position, void *element);

/**
 * @brief Insert an element to the front of the list
 * 
 * This operation insert an element in the position 0.
 * If the list is not empty it makes the first element the be
 * the second one and the inserted element becomes the first one
 * 
 * @param list The address of the list to which the element
 * must be inserted
 * @param element A pointer to the memory that holds the element
 * to be inserted
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_OUT_OF_MEMORY if failed to allocate memory for new node
 * @return Otherwise returns LIST_FAIL
 */
ListResultCode listPushFront(List *list, void *element);

/**
 * @brief Insert an element to the back of the list
 * 
 * This operation insert an element in the last position.
 * 
 * @param list The address of the list to which the element
 * must be inserted
 * @param element A pointer to the memory that holds the element
 * to be inserted
 * 
 * @return On success returns LIST_OK
 * @return Returns LIST_OUT_OF_MEMORY if failed to allocate memory for new node
 * @return Otherwise returns LIST_FAIL
 */
ListResultCode listPushBack(List *list, void *element);

/**
 * @brief Remove an element from the list at the position pointed by an iterator
 * 
 * This operation remove an element
 * When an element is removed from the list, it's data is
 * removed from memory because it's ownership belongs to
 * the list
 * 
 * @param list The address of the list from which the element
 * must be removed
 * @param iterator An iterator pointing to the position of
 * the list where to remove an element
 * 
 * @return On success returns LIST_OK
 * @return LIST_REMOVE_ALREADY_EMPTY if list is empty
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listRemove(List *list, ListIterator *iterator);

/**
 * @brief Remove an element from the list
 * 
 * This operation remove an element
 * When an element is removed from the list, it's data is
 * removed from memory because it's ownership belongs to
 * the list
 * 
 * @param list The address of the list from which the element
 * must be removed
 * @param position The position in the list from which the element
 * must be removed
 * 
 * @return On success returns LIST_OK
 * @return LIST_REMOVE_ALREADY_EMPTY if list is empty
 * @return Returns LIST_INSERT_OUT_OF_BOUNDS if trying to remove
 * from an invalid position in list
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listRemoveFromIndex(List *list, unsigned long position);

/**
 * @brief Remove the first element from the list
 * 
 * @param list The address of the list from which the element
 * must be removed
 * 
 * @return On success returns LIST_OK
 * @return LIST_REMOVE_ALREADY_EMPTY if list is empty
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listPopFront(List *list);

/**
 * @brief Remove the last element from the list
 * 
 * @param list The address of the list from which the element
 * must be removed
 * 
 * @return On success returns LIST_OK
 * @return LIST_REMOVE_ALREADY_EMPTY if list is empty
 * @return Returns LIST_FAIL if failed for generic reasons
 */
ListResultCode listPopBack(List *list);

/**
 * @brief Removes all elements of a given list
 * 
 * @param list The address of the list from which all elements
 * must be removed
 * 
 * @return On success returns LIST_OK
 * @return LIST_REMOVE_ALREADY_EMPTY if list is empty
 * @return Returns LIST_FAIL if unable to remove all elements
 */
ListResultCode listRemoveAll(List *list);

#endif // _DIDATIC_GAME_LIST_H_