#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listPopFrontNullPtr) {
    munit_assert_long(listPopFront(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listPopBackNullPtr) {
    munit_assert_long(listPopBack(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listRemoveNullPtr) {
    munit_assert_long(listRemoveFromIndex(NULL, 0UL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listRemoveAllNullPtr) {
    munit_assert_long(listRemoveAll(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyPopFront, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listPopFront(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyPopBack, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listPopBack(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyRemove, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listRemoveFromIndex(list, 0UL), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listEmptyRemoveAllElements, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listRemoveAll(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listPopFront, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);
    const size_t numberOfRemoves = 3UL;

    const int *expectedResult = (int*)FIXTURE_INDEX(user_data_or_fixture, 1) + numberOfRemoves;
    const size_t expectedArraySize = initialArraySize - numberOfRemoves;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopFront(list), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedArraySize);
}

// ============

DEFINE_FULL_TEST_FUNC(listPopBack, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);
    const size_t numberOfRemoves = 3UL;

    const int *expectedResult = (int*)FIXTURE_INDEX(user_data_or_fixture, 1);
    const size_t expectedArraySize = initialArraySize - numberOfRemoves;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopBack(list), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedArraySize);
}

// ============

DEFINE_FULL_TEST_FUNC(listRemove, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    const int expectedResult[] = {10, 3, -7, 50};
    const size_t expectedArraySize = sizeof(expectedResult) / sizeof(int);

    const size_t indexesToRemove[] = {9, 0, 2, 3, 4, 2};
    const size_t numberOfRemoves = sizeof(indexesToRemove) / sizeof(size_t);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listRemoveFromIndex(list, indexesToRemove[i]), ==, LIST_OK);
    }

    return compareListToArrayInt(list, expectedResult, expectedArraySize);
}

// ============

DEFINE_FULL_TEST_FUNC(listRemoveRandom, listLargeAmountElementsRandomValue) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    for(size_t i = 0; i < initialArraySize; ++i) {
        int removeMethod = munit_rand_int_range(0, 4);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)(list->elementsCount) - 1);
        ListResultCode ret = LIST_FAIL;

        switch (removeMethod)
        {
        case 0:
        case 1:
        case 2:
            ret = listRemoveFromIndex(list, position);
            break;

        case 3:
            ret = listPopFront(list);
            break;

        case 4:
            ret = listPopBack(list);
            break;
        }

        munit_assert_long(ret, ==, LIST_OK);
    }

    munit_assert_ulong(list->elementsCount, ==, 0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listRemoveInvalidPosition, listFewElements) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    munit_assert_long(listRemoveFromIndex(list, initialArraySize), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listRemoveAllElements, listLargeAmountElementsRandomValue) {
    List *list = (List*)FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t initialArraySize = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, initialArraySize);

    munit_assert_long(listRemoveAll(list), ==, LIST_OK);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-nullPtr", listPopFrontNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-nullPtr", listPopBackNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-nullPtr", listRemoveNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-nullPtr", listRemoveAllNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-emptyList", listEmptyPopFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-emptyList", listEmptyPopBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-emptyList", listEmptyRemove),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-emptyList", listEmptyRemoveAllElements),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-notEmptyList", listPopFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-notEmptyList", listPopBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-notEmptyList", listRemove),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-random", listRemoveRandom),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-invalidPosition", listRemoveInvalidPosition),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-notEmptyList", listRemoveAllElements),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/removing",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listRemoveTestsGetSuite(void) {
    return listTestsSuite;
}