#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/list_test_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listGetBeginNullPtr) {
    // Testing all combinations off null pointer passed to parameter
    munit_assert_long(listGetBegin(NULL, NULL), ==, LIST_FAIL);
    munit_assert_long(listGetBegin(NULL, (ListIterator**)1UL), ==, LIST_FAIL);
    munit_assert_long(listGetBegin((List*)1UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetBeginEmptyList, listEmpty) {
    List *list = (List*)user_data_or_fixture;
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listGetBegin(list, &iterator), ==, LIST_FIND_NOT_FOUND);
    munit_assert_null(iterator);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetBeginSingleElementList, listSingleElement) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    int singleValue = *(int*)FIXTURE_INDEX(user_data_or_fixture, 1);
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 1UL);

    munit_assert_long(listGetBegin(list, &iterator), ==, LIST_OK);
    munit_assert_not_null(iterator);
    munit_assert_int(*(int*)(iterator->data), ==, singleValue);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetBegin, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    int expectedValue = ((int*)FIXTURE_INDEX(user_data_or_fixture, 1))[0];
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, >, 1UL);

    munit_assert_long(listGetBegin(list, &iterator), ==, LIST_OK);
    munit_assert_not_null(iterator);
    munit_assert_int(*(int*)(iterator->data), ==, expectedValue);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listGetEndNullPtr) {
    // Testing all combinations off null pointer passed to parameter
    munit_assert_long(listGetEnd(NULL, NULL), ==, LIST_FAIL);
    munit_assert_long(listGetEnd(NULL, (ListIterator**)1UL), ==, LIST_FAIL);
    munit_assert_long(listGetEnd((List*)1UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetEndEmptyList, listEmpty) {
    List *list = (List*)user_data_or_fixture;
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listGetEnd(list, &iterator), ==, LIST_FIND_NOT_FOUND);
    munit_assert_null(iterator);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetEndSingleElementList, listSingleElement) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const int singleValue = *(int*)FIXTURE_INDEX(user_data_or_fixture, 1);
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 1UL);

    munit_assert_long(listGetEnd(list, &iterator), ==, LIST_OK);
    munit_assert_not_null(iterator);
    munit_assert_int(*(int*)(iterator->data), ==, singleValue);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listGetEnd, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t setupArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);
    const int expectedValue = ((int*)FIXTURE_INDEX(user_data_or_fixture, 1))[setupArraySize - 1];
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, >, 1UL);

    munit_assert_long(listGetEnd(list, &iterator), ==, LIST_OK);
    munit_assert_not_null(iterator);
    munit_assert_int(*(int*)(iterator->data), ==, expectedValue);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listFindElementNullPtr) {
    // Testing all combinations off null pointer passed to parameter
    munit_assert_long(listFindElement(NULL, 0UL, NULL), ==, LIST_FAIL);
    munit_assert_long(listFindElement(NULL, 0UL, (ListIterator**)1UL), ==, LIST_FAIL);
    munit_assert_long(listFindElement((List*)1UL, 0UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listFindElementEmptyList, listEmpty) {
    List *list = (List*)user_data_or_fixture;
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listFindElement(list, 0UL, &iterator), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_null(iterator);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listFindElementOutOfBounds, listSingleElement) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 1UL);

    munit_assert_long(listFindElement(list, 1UL, &iterator), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_null(iterator);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listFindElement, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const int *setupArray = (int*)FIXTURE_INDEX(user_data_or_fixture, 1);
    const size_t setupArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);
    ListIterator *iterator = NULL;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, setupArraySize);

    for(size_t i = 0; i < setupArraySize; ++i) {
        munit_assert_long(listFindElement(list, i, &iterator), ==, MUNIT_OK);
        munit_assert_not_null(iterator);
        munit_assert_int(*((int*)iterator->data), ==, setupArray[i]);

        free(iterator);
    }

    return MUNIT_OK;
}

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetBegin-nullPtr", listGetBeginNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetBegin-emptyList", listGetBeginEmptyList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetBegin-singleElementList", listGetBeginSingleElementList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetBegin-fewElementsList", listGetBegin),

    GET_TEST_FUNC_ARRAY_ENTRY("/listGetEnd-nullPtr", listGetEndNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetEnd-emptyList", listGetEndEmptyList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetEnd-singleElementList", listGetEndSingleElementList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetEnd-fewElementsList", listGetEnd),

    GET_TEST_FUNC_ARRAY_ENTRY("/listFindElement-nullPtr", listFindElementNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listFindElement-emptyList", listFindElementEmptyList),
    GET_TEST_FUNC_ARRAY_ENTRY("/listFindElement-outOfBounds", listFindElementOutOfBounds),
    GET_TEST_FUNC_ARRAY_ENTRY("/listFindElement-fewElementsList", listFindElement),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/searching",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listFindTestsGetSuite(void) {
    return listTestsSuite;
}