#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

MUNIT_DECLARE_TEST_FUNC(listCreate) {
    List *list = listCreate();

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    listDestroy(list);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    {
        "/listCreate",
        MUNIT_TEST_FUNC_NAME(listCreate),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitSuite listTestsSuite = {
    "/creating",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listCreateTestsGetSuite(void) {
    return listTestsSuite;
}