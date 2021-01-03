#ifndef _DIDATIC_GAME_TIMER_TESTS_H_
#define _DIDATIC_GAME_TIMER_TESTS_H_

#include <munit.h>

// Controls the amount of subsuites for list tests
#define TIMER_SUBSUITES_NUMBER 1

// Return a MunitSuite filled up with all list subsuites
MunitSuite timerTestsGetSuite(void);

MunitSuite timerAllTestsGetSuite(void);

#endif // _DIDATIC_GAME_TIMER_TESTS_H_