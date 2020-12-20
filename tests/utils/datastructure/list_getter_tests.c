#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listGetElementsCountNullPtr) {
    munit_assert_ulong(listGetElementsCount(NULL), ==, 0UL);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountEmpty, listEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountSingleElement, listSingleElement) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 1UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-nullPtr", listGetElementsCountNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-emptyList", listGetElementsCountEmpty),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-singleElement", listGetElementsCountSingleElement),

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
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