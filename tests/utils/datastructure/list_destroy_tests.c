#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

MUNIT_DECLARE_TEST_FUNC(listDestroyNullPtr) {
    munit_assert_long(listDestroy(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty) {
    List *list = listCreate();
    listPushBack(list, malloc(1));

    return list;
}

MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), !=, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listDestroyEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_OK);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    {
        "/listDestroy-nullPtr",
        MUNIT_TEST_FUNC_NAME(listDestroyNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyNotEmptyList",
        MUNIT_TEST_FUNC_NAME(listDestroyNotEmpty),
        MUNIT_SETUP_FUNC_NAME(listDestroyNotEmpty),
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyEmptyList",
        MUNIT_TEST_FUNC_NAME(listDestroyEmpty),
        MUNIT_SETUP_FUNC_NAME(listDestroyEmpty),
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

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