#include "core/system/timer/timer_tests.h"

static MunitSuite timerSubsuites[TIMER_SUBSUITES_NUMBER];

static MunitSuite timerTestsSuite = {
    "/core/system/timer",
    NULL,
    timerSubsuites,
    1,
    MUNIT_SUITE_OPTION_NONE
};

static inline void fillupTimerSubsuitesArray(void) {
    timerSubsuites[0] = timerAllTestsGetSuite();
}

MunitSuite timerTestsGetSuite(void) {
    fillupTimerSubsuitesArray();

    return timerTestsSuite;
}