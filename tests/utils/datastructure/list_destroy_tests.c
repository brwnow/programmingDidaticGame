#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

DEFINE_STANDALONE_TEST_FUNC(listDestroyNullPtr) {
    munit_assert_long(listDestroy(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listDestroyEmpty) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listDestroyEmpty) {
    UNUSED(fixture);
}

DEFINE_FULL_TEST_FUNC(listDestroyEmpty, listDestroyEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listDestroyNotEmpty) {
    List *list = listCreate();
    listPushBack(list, malloc(1));

    return list;
}

DECLARE_TEARDOWN_FUNC(listDestroyNotEmpty) {
    UNUSED(fixture);
}

DEFINE_FULL_TEST_FUNC(listDestroyNotEmpty, listDestroyNotEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), !=, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-nullPtr", listDestroyNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-destroyEmptyList", listDestroyEmpty),
    GET_TEST_FUNC_ARRAY_ENTRY("/listDestroy-destroyNotEmptyList", listDestroyNotEmpty),

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
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