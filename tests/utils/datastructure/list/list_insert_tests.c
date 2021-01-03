#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list/list_tests.h"
#include "utils/datastructure/list/list_test_setups.h"
#include "utils/datastructure/list/list_test_utils.h"

DEFINE_STANDALONE_TEST_FUNC(listPushFrontNullPtr) {
    munit_assert_long(listPushFront(NULL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyPushFront, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    const int expectedResult[] ={-4585, 0, 111, 54685, -89, 3, 27, 500, 4, 9};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listPushFront(list, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_FULL_TEST_FUNC(listPushFront, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {-4585, 0, 111, 54685, -89, 3, 27, 500, 4, 9, 0, 10, 3, 99, -250000, 999999, -7, 888, 50, 42};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listPushFront(list, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listPushBackNullPtr) {
    munit_assert_long(listPushBack(NULL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyPushBack, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    const int valuesToInsert[] = {-856, 41, 0, 23, 158, -89356, 54685, 321, 444, -4585, 84, -2};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listPushBack(list, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, valuesToInsert, valuesCount);
}

// ============

DEFINE_FULL_TEST_FUNC(listPushBack, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {0, 10, 3, 99, -250000, 999999, -7, 888, 50, 42, 9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listPushBack(list, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listInsertExNullPtr) {
    munit_assert_long(listInsertEx(NULL, NULL, LIST_AFTER, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertExNodeNotOwnedByList, listFewElementsAndNodeNotOwnedByList) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    Node *notOwnedByListNode = (Node*)FIXTURE_INDEX(user_data_or_fixture, 3);

    munit_assert_not_null(list);
    munit_assert_not_null(notOwnedByListNode);
    munit_assert_ptr_not_equal(list, notOwnedByListNode->parent);

    munit_assert_long(listInsertEx(list, notOwnedByListNode, LIST_AFTER, NULL), ==, LIST_NODE_OWNERSHIP_ERROR);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertExFirstNodeInNotEmptyList, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, >, 0UL);

    munit_assert_long(listInsertEx(list, NULL, LIST_AFTER, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertExEmptyList, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    const int valuesToInsert[] = {0, 50, 2, 999, 73};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];

        if(list->elementsCount == 0UL)
            munit_assert_long(listInsertEx(list, NULL, LIST_AFTER, elem), ==, LIST_OK);
        else
            munit_assert_long(listInsertEx(list, list->lastNode, LIST_AFTER, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, valuesToInsert, valuesCount);
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertEx, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {2, 1, 0, 10, 701, 3, 99, -250000, 999999, -7, 602, 888, 50, 42, 99, 22};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {2, 1, 22, 99, 701, 602};

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    int *elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[0];
    munit_assert_long(listInsertEx(list, list->firstNode, LIST_BEFORE, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[1];
    munit_assert_long(listInsertEx(list, list->firstNode, LIST_AFTER, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[2];
    munit_assert_long(listInsertEx(list, list->lastNode, LIST_AFTER, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[3];
    munit_assert_long(listInsertEx(list, list->lastNode, LIST_BEFORE, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[4];
    munit_assert_long(listInsertEx(list, list->firstNode->next->next->next, LIST_AFTER, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[5];
    munit_assert_long(listInsertEx(list, list->lastNode->prev->prev->prev->prev, LIST_BEFORE, elem), ==, LIST_OK);

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertExReplaceElements, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {22, 10, 2, 99, 1, 999999, -7, 888, 50, 99};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {2, 1, 22, 99};

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    int *elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[0];
    munit_assert_long(listInsertEx(list, list->firstNode->next->next, LIST_REPLACE, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[1];
    munit_assert_long(listInsertEx(list, list->firstNode->next->next->next->next, LIST_REPLACE, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[2];
    munit_assert_long(listInsertEx(list, list->firstNode, LIST_REPLACE, elem), ==, LIST_OK);

    elem = (int*)malloc(sizeof(int));
    *elem = valuesToInsert[3];
    munit_assert_long(listInsertEx(list, list->lastNode, LIST_REPLACE, elem), ==, LIST_OK);

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listInsertNullPtr) {
    munit_assert_long(listInsert(NULL, LIST_BEFORE, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyInsert, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listInsert(NULL, LIST_BEFORE, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listInsert, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {-500, 0, 400, 10, 3, 99, -950, -250000, 951, 999999, -7, 888, 50, 7, 42, 13};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {400, -500, 7, 13, -950, 951};

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    ListIterator *it = createIterator(NULL, list->firstNode);

    int *elem = malloc(sizeof(int));
    *elem = valuesToInsert[0];
    munit_assert_long(listInsert(it, LIST_AFTER, elem), ==, LIST_OK);

    elem = malloc(sizeof(int));
    *elem = valuesToInsert[1];
    munit_assert_long(listInsert(it, LIST_BEFORE, elem), ==, LIST_OK);

    free(it);
    it = createIterator(NULL, list->lastNode);

    elem = malloc(sizeof(int));
    *elem = valuesToInsert[2];
    munit_assert_long(listInsert(it, LIST_BEFORE, elem), ==, LIST_OK);

    elem = malloc(sizeof(int));
    *elem = valuesToInsert[3];
    munit_assert_long(listInsert(it, LIST_AFTER, elem), ==, LIST_OK);

    free(it);
    it = createIterator(NULL, list->firstNode->next->next->next->next->next->next);

    elem = malloc(sizeof(int));
    *elem = valuesToInsert[4];
    munit_assert_long(listInsert(it, LIST_BEFORE, elem), ==, LIST_OK);

    elem = malloc(sizeof(int));
    *elem = valuesToInsert[5];
    munit_assert_long(listInsert(it, LIST_AFTER, elem), ==, LIST_OK);

    free(it);

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listInsertIndexNullPtr) {
    munit_assert_long(listInsertAtIndex(NULL, 0UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertIndexInInvalidPosition, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const int *expectedResult = (int*)FIXTURE_INDEX(user_data_or_fixture, 1);
    const size_t expectedSize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, expectedSize);

    munit_assert_long(listInsertAtIndex(list, expectedSize + 1UL, NULL), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_ulong(list->elementsCount, ==, expectedSize);

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyInsertIndex, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    const int valuesToInsert[] = {0, 50, 2, 999, 73};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listInsertAtIndex(list, i, elem), ==, LIST_OK);
    }

    return compareListToArrayInt(list, valuesToInsert, valuesCount);
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertIndexVariablePositions, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialListSize = *((size_t*)FIXTURE_INDEX(user_data_or_fixture, 2));

    const int expectedResult[] = {40, 0, 2, -7, 10, 3, 99, -250000, -89555, 999999, -7, 888, 50, 99, 42, 65000};
    const size_t expectedSize = sizeof(expectedResult) / sizeof(int);

    const int valuesToInsert[] = {2, -7, 40, 99, 65000, -89555};
    const size_t positionsToInsert[] = {1, 2, 0, 12, 14, 8};
    const size_t valuesCount = sizeof(valuesToInsert) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialListSize);

    for(size_t i = 0; i < valuesCount; ++i) {
        int *elem = malloc(sizeof(int));
        *elem = valuesToInsert[i];
        munit_assert_long(listInsertAtIndex(list, positionsToInsert[i], elem), ==, MUNIT_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedSize);
}

// ============

DEFINE_FULL_TEST_FUNC(listInsertIndexLargeAmount, listSingleElement) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t amountToBeInserted = 50000UL;
    const size_t expectedSize = amountToBeInserted + 1UL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 1UL);

    for(size_t i = 0; i < amountToBeInserted; ++i) {
        int insertMethod = munit_rand_int_range(0, 2);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)(list->elementsCount));
        ListResultCode ret = LIST_FAIL;

        switch (insertMethod)
        {
        case 0:
            ret = listInsertAtIndex(list, position, malloc(sizeof(int)));
            break;

        case 1:
            ret = listPushFront(list, malloc(sizeof(int)));
            break;

        case 2:
            ret = listPushBack(list, malloc(sizeof(int)));
            break;
        }

        munit_assert_long(ret, ==, LIST_OK);
    }

    munit_assert_ulong(list->elementsCount, ==, expectedSize);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushFront-nullPtr", listPushFrontNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushFront-emptyList", listEmptyPushFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushFront-notEmptyList", listPushFront),

    GET_TEST_FUNC_ARRAY_ENTRY("/listPushBack-nullPtr", listPushBackNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushBack-emptyList", listEmptyPushBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushBack-notEmptyList", listPushBack),

    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-nullPtr", listInsertExNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-nodeNotOwnedByList", listInsertExNodeNotOwnedByList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-firstNodeInNotEmptyList", listInsertExFirstNodeInNotEmptyList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-emptyList", listInsertExEmptyList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-notEmptyList", listInsertEx),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertEx-replaceElements", listInsertExReplaceElements),

    GET_TEST_FUNC_ARRAY_ENTRY("/listInsert-nullPtr", listInsertNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsert-emptyList", listEmptyInsert),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsert-notEmptyList", listInsert),

    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-nullPtr", listInsertIndexNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-invalidPosition", listInsertIndexInInvalidPosition),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-emptyList", listEmptyInsertIndex),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-notEmptyList", listInsertIndexVariablePositions),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-largeAmount", listInsertIndexLargeAmount),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/inserting",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listInsertTestsGetSuite(void) {
    return listTestsSuite;
}