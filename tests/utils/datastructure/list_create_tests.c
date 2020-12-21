#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listCreate) {
    List *list = listCreate();

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);
    munit_assert_null(list->firstNode);
    munit_assert_null(list->lastNode);

    listDestroy(list);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listCreate", listCreate),

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