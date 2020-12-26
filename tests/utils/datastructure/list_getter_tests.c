#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listGetElementsCountNullPtr) {
    munit_assert_ulong(listGetElementsCount(NULL), ==, 0UL);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountEmpty, listEmpty) {
    List *list = user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountSingleElement, listSingleElement) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 1UL);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountFewElements, listFewElements) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t numberOfElements = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, numberOfElements);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountLargeAmountRandom, listLargeAmountElementsRandomValue) {
    List *list = FIXTURE_INDEX(user_data_or_fixture, 0);
    const size_t numberOfElements = *(size_t*)FIXTURE_INDEX(user_data_or_fixture, 2);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, numberOfElements);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-nullPtr", listGetElementsCountNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-emptyList", listGetElementsCountEmpty),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-singleElement", listGetElementsCountSingleElement),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-fewElements", listGetElementsCountFewElements),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-largeAmountRandom", listGetElementsCountLargeAmountRandom),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/getters",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listGetterTestsGetSuite(void) {
    return listTestsSuite;
}