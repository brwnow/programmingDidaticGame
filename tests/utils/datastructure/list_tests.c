#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list_tests.h"

static MunitSuite listSubsuites[LIST_SUBSUITES_NUMBER];

static MunitSuite listTestsSuite = {
    "/utils/datastructure/list",
    NULL,
    listSubsuites,
    1,
    MUNIT_SUITE_OPTION_NONE
};

static inline void fillupListSubsuitesArray(void) {
    listSubsuites[0] = listCreateTestsGetSuite();
    listSubsuites[1] = listDestroyTestsGetSuite();
    listSubsuites[2] = listGetterTestsGetSuite();
    listSubsuites[3] = listInsertTestsGetSuite();
    listSubsuites[4] = listRemoveTestsGetSuite();
}

MunitSuite listTestsGetSuite(void) {
    fillupListSubsuitesArray();

    return listTestsSuite;
}