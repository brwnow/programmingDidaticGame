#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list/list_tests.h"
#include "utils/datastructure/list/list_test_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listDestroyNullPtr) {
    munit_assert_long(listDestroy(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listDestroyEmpty, listEmptyStubTd) {
    List *list = user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listDestroySingleElement, listSingleElementStubTd) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 1UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listDestroyFewElements, listFewElementsStubTd) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, >, 1UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(listDestroyLargeAmountRandom, listLargeAmountElementsRandomValueStubTd) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t numberOfElements = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, numberOfElements);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-nullPtr", listDestroyNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-emptyList", listDestroyEmpty),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-singleElement", listDestroySingleElement),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-fewElements", listDestroyFewElements),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-largeAmountRandom", listDestroyLargeAmountRandom),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/destroying",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listDestroyTestsGetSuite(void) {
    return listTestsSuite;
}