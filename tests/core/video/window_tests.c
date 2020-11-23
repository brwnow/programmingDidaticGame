#include <munit.h>

static MunitResult windowGetScreenUninitedVideo(const MunitParameter params[], void* user_data_or_fixture);

static MunitTest windowTests[] = {
    {
        "/windowGetScreen-unitializedVideo",
        windowGetScreenUninitedVideo,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitSuite windowTestsSuite = {
    "/core/video/window",
    windowTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

static MunitResult windowGetScreenUninitedVideo(const MunitParameter params[], void* user_data_or_fixture) {
    (void)params;
    (void)user_data_or_fixture;

    return MUNIT_FAIL;
}

MunitSuite windowTestsGetSuite(void) {
    return windowTestsSuite;
}
