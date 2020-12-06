#ifndef _DIDATIC_GAME_LIST_H_
#define _DIDATIC_GAME_LIST_H_

typedef struct _List List;

typedef enum _ListResultCode {
    LIST_RC_FAIL, /**< List operation failed */
    LIST_RC_OK = 0, /**< List operation succeed */
    LIST_RC_REMOVE_ALREADY_EMPTY /**< Remove operation not performed due to list is already empty */
} ListResultCode;

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
 * @return On success returns LIST_RC_OK
 * @return Returns LIST_RC_FAIL if unable to destroy the list
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
 * @brief Removes all elements of a given list
 * 
 * @param list The address of the list from which all elements
 * must be removed
 * 
 * @return On success returns LIST_RC_OK
 * @return Returns LIST_RC_FAIL if unable to remove all elements
 */
ListResultCode listRemoveAll(List *list);

#endif // _DIDATIC_GAME_LIST_H_