#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

MUNIT_DECLARE_TEST_FUNC(listGetElementsCountNullPtr) {
    munit_assert_ulong(listGetElementsCount(NULL), ==, 0UL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listGetElementsCountEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCountEmpty) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listGetElementsCountEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listGetElementsCount) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCount) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listGetElementsCount) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    {
        "/listGetElementsCount-nullPtr",
        MUNIT_TEST_FUNC_NAME(listGetElementsCountNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listGetElementsCount-emptyList",
        MUNIT_TEST_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_SETUP_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_TEARDOWN_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listGetElementsCount-populatedList",
        MUNIT_TEST_FUNC_NAME(listGetElementsCount),
        MUNIT_SETUP_FUNC_NAME(listGetElementsCount),
        MUNIT_TEARDOWN_FUNC_NAME(listGetElementsCount),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

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