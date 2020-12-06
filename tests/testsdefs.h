#ifndef _DIDATIC_GAME_TESTS_DEFS_H
#define _DIDATIC_GAME_TESTS_DEFS_H

#define MUNIT_DECLARE_SETUP_FUNC(funcName) static void* funcName ## _setup(const MunitParameter params[] MUNIT_UNUSED, void* user_data MUNIT_UNUSED)
#define MUNIT_DECLARE_TEARDOWN_FUNC(funcName) static void funcName ## _teardown(void* fixture)
#define MUNIT_DECLARE_TEST_FUNC(funcName) static MunitResult funcName ## _test(const MunitParameter params[] MUNIT_UNUSED, void* user_data_or_fixture MUNIT_UNUSED)

#define MUNIT_TEST_FUNC_NAME(funcName) funcName ## _test
#define MUNIT_SETUP_FUNC_NAME(funcName) funcName ## _setup
#define MUNIT_TEARDOWN_FUNC_NAME(funcName) funcName ## _teardown

#endif // _DIDATIC_GAME_TESTS_DEFS_H