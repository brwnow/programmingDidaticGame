#include "utils/datastructure/list_test_utils.h"

MunitResult compareListToArrayInt(const List *list, const int *array, size_t arraySize) {
    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, arraySize);

    const Node *current = list->firstNode;

    for(size_t i = 0; i < arraySize; ++i) {
        munit_assert_not_null(current);
        munit_assert_not_null(current->data);

        munit_assert_int(*(int*)(current->data), ==, array[i]);

        current = current->next;
    }

    return MUNIT_OK;
}