#ifndef _DIDATIC_GAME_LIST_TESTS_H_
#define _DIDATIC_GAME_LIST_TESTS_H_

// Controls the amount of subsuites for list tests
#define LIST_SUBSUITES_NUMBER 5

// Return a MunitSuite filled up with all list subsuites
MunitSuite listTestsGetSuite(void);

MunitSuite listCreateTestsGetSuite(void);
MunitSuite listDestroyTestsGetSuite(void);
MunitSuite listGetterTestsGetSuite(void);
MunitSuite listInsertTestsGetSuite(void);
MunitSuite listRemoveTestsGetSuite(void);

#endif // _DIDATIC_GAME_LIST_TESTS_H_