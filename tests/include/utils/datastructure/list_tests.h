#ifndef _DIDATIC_GAME_LIST_TESTS_H_
#define _DIDATIC_GAME_LIST_TESTS_H_

#include <munit.h>

// Controls the amount of subsuites for list tests
#define LIST_SUBSUITES_NUMBER 6

// Return a MunitSuite filled up with all list subsuites
MunitSuite listTestsGetSuite(void);

MunitSuite listCreateTestsGetSuite(void);
MunitSuite listDestroyTestsGetSuite(void);
MunitSuite listGetterTestsGetSuite(void);
MunitSuite listFindTestsGetSuite(void);
MunitSuite listInsertTestsGetSuite(void);
MunitSuite listRemoveTestsGetSuite(void);

#endif // _DIDATIC_GAME_LIST_TESTS_H_