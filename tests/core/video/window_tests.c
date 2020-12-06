#include <munit.h>
#include <testsdefs.h>

MUNIT_DECLARE_TEST_FUNC(windowGetScreenUninitedVideo);

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

MUNIT_DECLARE_TEST_FUNC(windowGetScreenUninitedVideo) {
    return MUNIT_FAIL;
}

MunitSuite windowTestsGetSuite(void) {
    return windowTestsSuite;
}
