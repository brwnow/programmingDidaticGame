#ifndef _DIDATIC_GAME_TEST_LIST_SETUPS_H
#define _DIDATIC_GAME_TEST_LIST_SETUPS_H

#include <testsdefs.h>

// =======================
/* Empty list
 *
 * fixture format: pointer to a list
 */
DECLARE_SETUP_FUNC(listEmpty);
DECLARE_TEARDOWN_FUNC(listEmpty);

DECLARE_SETUP_FUNC(listEmptyStubTd);
DECLARE_TEARDOWN_FUNC(listEmptyStubTd);

// =======================
/* Single element list
 * the element is an int with value 5
 * 
 * fixture format: array of void* with 2 positions
 *      [0] -> pointer to list
 *      [1] -> pointer to int with value 5
 */
DECLARE_SETUP_FUNC(listSingleElement);
DECLARE_TEARDOWN_FUNC(listSingleElement);

DECLARE_SETUP_FUNC(listSingleElementStubTd);
DECLARE_TEARDOWN_FUNC(listSingleElementStubTd);

// =======================
/* Few elements list
 * List with 10 ints. Values -> 0, 10, 3, 99, -250000, 999999, -7, 888, 50, 42
 * 
 * fixture format: array of void* with 3 positions
 *      [0] -> pointer to list
 *      [1] -> pointer to an array of int with the values in the description of this setup
 *      [2] -> pointer to size_t with the number of elements in the array above
 */
DECLARE_SETUP_FUNC(listFewElements);
DECLARE_TEARDOWN_FUNC(listFewElements);

DECLARE_SETUP_FUNC(listFewElementsStubTd);
DECLARE_TEARDOWN_FUNC(listFewElementsStubTd);

// =======================
/* Large amount of elements lsit
 * List with 10000 ints. Values are random
 * 
 * fixture format: array of void* with 3 positions
 *      [0] -> pointer to list
 *      [1] -> pointer to an array of int with random values
 *      [2] -> pointer to size_t with the number of elements in the array above
 */
DECLARE_SETUP_FUNC(listLargeAmountElementsRandomValue);
DECLARE_TEARDOWN_FUNC(listLargeAmountElementsRandomValue);

DECLARE_SETUP_FUNC(listLargeAmountElementsRandomValueStubTd);
DECLARE_TEARDOWN_FUNC(listLargeAmountElementsRandomValueStubTd);

#endif // _DIDATIC_GAME_TEST_LIST_SETUPS_H