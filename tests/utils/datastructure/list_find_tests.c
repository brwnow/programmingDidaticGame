#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/list_test_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listGetBeginNullPtr) {
    // Testing all combinations off null pointer passed to parameter
    munit_assert_long(listGetBegin(NULL, NULL), ==, LIST_FAIL);
    munit_assert_long(listGetBegin(NULL, (ListIterator**)1UL), ==, LIST_FAIL);
    munit_assert_long(listGetBegin((List*)1UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listGetBegin-nullPtr", listGetBeginNullPtr),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/destroying",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listFindTestsGetSuite(void) {
    return listTestsSuite;
}