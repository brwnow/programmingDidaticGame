#include "utils/datastructure/list/list_tests.h"

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
    listSubsuites[3] = listFindTestsGetSuite();
    listSubsuites[4] = listInsertTestsGetSuite();
    listSubsuites[5] = listRemoveTestsGetSuite();
}

MunitSuite listTestsGetSuite(void) {
    fillupListSubsuitesArray();

    return listTestsSuite;
}