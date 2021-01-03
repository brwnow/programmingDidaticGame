#include "utils/log/log.h"
#include "utils/datastructure/list_tests.h"
#include "core/system/timer/timer_tests.h"

#define TEST_SUITES_NUMBER 2
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
    allTestSuites[1] = timerTestsGetSuite();

    logInit();

    return munit_suite_main(&suite, NULL, argc, argv);
}