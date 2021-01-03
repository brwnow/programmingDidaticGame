#ifndef _DIDATIC_GAME_LIST_TEST_UTILS_H_
#define _DIDATIC_GAME_LIST_TEST_UTILS_H_

#include <stddef.h>
#include <munit.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"

MunitResult compareListToArrayInt(const List *list, const int *array, size_t arraySize);

#endif // _DIDATIC_GAME_LIST_TEST_UTILS_H_