#include <munit.h>

#include "utils/log/log.h"

MunitSuite listTestsGetSuite(void);

#define TEST_SUITES_NUMBER 1
static MunitSuite allTestSuites[TEST_SUITES_NUMBER];

static const MunitSuite suite = {
    "/game",
    NULL,
    allTestSuites,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
    allTestSuites[0] = listTestsGetSuite();

    logInit();

    return munit_suite_main(&suite, NULL, argc, argv);
}