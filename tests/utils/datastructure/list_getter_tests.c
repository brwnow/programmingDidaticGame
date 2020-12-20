#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

DEFINE_STANDALONE_TEST_FUNC(listGetElementsCountNullPtr) {
    munit_assert_ulong(listGetElementsCount(NULL), ==, 0UL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listGetElementsCountEmpty) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listGetElementsCountEmpty) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listGetElementsCountEmpty, listGetElementsCountEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listGetElementsCount) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));

    return list;
}

DECLARE_TEARDOWN_FUNC(listGetElementsCount) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listGetElementsCount, listGetElementsCount) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-nullPtr", listGetElementsCountNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-emptyList", listGetElementsCountEmpty),
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetElementsCount-populatedList", listGetElementsCount),

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