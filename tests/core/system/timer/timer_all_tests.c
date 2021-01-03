#include <testsdefs.h>

#include "mockups/sdl_mockups.h"

#include "core/system/timer.h"
#include "core/system/timer_private.h"
#include "core/system/timer/timer_tests.h"
#include "core/system/timer/timer_test_setups.h"

DEFINE_STANDALONE_TEST_FUNC(timerInitFailing) {
    set_SDL_InitSubSystem_retVal(-1);

    munit_assert_false(timerInit());

    // Back to success behavior
    set_SDL_InitSubSystem_retVal(0);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(timerInitSuccess) {
    set_SDL_InitSubSystem_retVal(0);

    munit_assert_true(timerInit());

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(timerIsInitialized) {
    set_SDL_InitSubSystem_retVal(-1);

    munit_assert_false(timerInit());
    munit_assert_false(timerIsInitialized());

    timerEnd();

    set_SDL_InitSubSystem_retVal(0);

    munit_assert_true(timerInit());
    munit_assert_true(timerIsInitialized());

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(timerGlobalTime) {
    set_SDL_GetTicks_retVal((Uint32)0UL);
    munit_assert_ulong(timerGlobalTime(), ==, 0UL);

    set_SDL_GetTicks_retVal((Uint32)800UL);
    munit_assert_ulong(timerGlobalTime(), ==, 800UL);

    set_SDL_GetTicks_retVal((Uint32)-1);
    munit_assert_ulong(timerGlobalTime(), ==, (unsigned long)-1);

    // Resets mockup GetTicks
    set_SDL_GetTicks_retVal(0);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(createTimer) {
    Timer *timer = createTimer();

    munit_assert_not_null(timer);

    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    destroyTimer(timer);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerStartEmptyTimer, timerEmpty) {
    Timer *timer = (Timer*)user_data_or_fixture;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    set_SDL_GetTicks_retVal(753UL);

    timerStart(timer);

    munit_assert_ulong(timer->startTimemark, ==, 753UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    set_SDL_GetTicks_retVal(5623UL);

    timerStart(timer);

    munit_assert_ulong(timer->startTimemark, ==, 753UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerStartPausedTimer, timerPaused) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;
    const unsigned long pauseTm = timer->pauseTimemark;
    const unsigned long initialElapsed = pauseTm - startTm;

    munit_assert_not_null(timer);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    set_SDL_GetTicks_retVal(pauseTm + 650UL);

    timerStart(timer);

    munit_assert_ulong(timer->startTimemark, ==, SDL_GetTicks() - initialElapsed);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerPauseEmptyTimer, timerEmpty) {
    Timer *timer = (Timer*)user_data_or_fixture;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    set_SDL_GetTicks_retVal(753UL);

    timerPause(timer);

    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerPauseRunningTimer, timerRunning) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;
    const unsigned long  timeToElapse = 900UL;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    set_SDL_GetTicks_retVal(startTm + timeToElapse);

    timerPause(timer);
    munit_assert_ulong(timer->startTimemark, ==, startTm);
    munit_assert_ulong(timer->pauseTimemark, ==, startTm + timeToElapse);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    set_SDL_GetTicks_retVal(SDL_GetTicks() + 5800UL);

    timerPause(timer);
    munit_assert_ulong(timer->startTimemark, ==, startTm);
    munit_assert_ulong(timer->pauseTimemark, ==, startTm + timeToElapse);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerStopEmptyTimer, timerEmpty) {
    Timer *timer = (Timer*)user_data_or_fixture;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    set_SDL_GetTicks_retVal(753UL);

    timerStop(timer);

    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerStopPausedTimer, timerPaused) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long pauseTm = timer->pauseTimemark;

    munit_assert_not_null(timer);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    set_SDL_GetTicks_retVal(pauseTm + 650UL);

    timerStop(timer);

    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerStopRunningTimer, timerRunning) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    set_SDL_GetTicks_retVal(startTm + 1543UL);

    timerStop(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerResetEmptyTimer, timerEmpty) {
    Timer *timer = (Timer*)user_data_or_fixture;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    set_SDL_GetTicks_retVal(753UL);

    timerReset(timer);

    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerResetPausedTimer, timerPaused) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long pauseTm = timer->pauseTimemark;
    const unsigned long currentTm = pauseTm + 980UL;

    munit_assert_not_null(timer);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    set_SDL_GetTicks_retVal(currentTm);

    timerReset(timer);

    munit_assert_ulong(timer->startTimemark, ==, currentTm);
    munit_assert_ulong(timer->pauseTimemark, ==, currentTm);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerResetRunningTimer, timerRunning) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;
    const unsigned long currentTm = startTm + 1678UL;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    set_SDL_GetTicks_retVal(currentTm);

    timerReset(timer);

    munit_assert_ulong(timer->startTimemark, ==, currentTm);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(timerGetState) {
    Timer timer = {0UL, 0UL, TIMER_STOPPED};

    munit_assert_long(timerGetState(&timer), ==, TIMER_STOPPED);

    timer.state = TIMER_PAUSED;

    munit_assert_long(timerGetState(&timer), ==, TIMER_PAUSED);

    timer.state = TIMER_RUNNING;

    munit_assert_long(timerGetState(&timer), ==, TIMER_RUNNING);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerGetElapsedTimeEmptyTimer, timerEmpty) {
    Timer *timer = (Timer*)user_data_or_fixture;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->startTimemark, ==, 0UL);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_STOPPED);

    set_SDL_GetTicks_retVal(753UL);

    munit_assert_ulong(timerGetElapsedTime(timer), ==, 0UL);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerGetElapsedTimePausedTimer, timerPaused) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;
    const unsigned long pauseTm = timer->pauseTimemark;
    const unsigned long elapsedTime = pauseTm - startTm;
    const unsigned long currentTm = pauseTm + 980UL;

    munit_assert_not_null(timer);
    munit_assert_long(timer->state, ==, TIMER_PAUSED);

    set_SDL_GetTicks_retVal(currentTm);

    munit_assert_ulong(timerGetElapsedTime(timer), ==, elapsedTime);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// ============

DEFINE_FULL_TEST_FUNC(timerGetElapsedTimeRunningTimer, timerRunning) {
    Timer *timer = (Timer*)user_data_or_fixture;
    const unsigned long startTm = timer->startTimemark;

    munit_assert_not_null(timer);
    munit_assert_ulong(timer->pauseTimemark, ==, 0UL);
    munit_assert_long(timer->state, ==, TIMER_RUNNING);

    set_SDL_GetTicks_retVal(startTm + 851UL);
    munit_assert_ulong(timerGetElapsedTime(timer), ==, 851UL);

    set_SDL_GetTicks_retVal(startTm + 4658UL);
    munit_assert_ulong(timerGetElapsedTime(timer), ==, 4658UL);

    set_SDL_GetTicks_retVal(startTm + 99999999UL);
    munit_assert_ulong(timerGetElapsedTime(timer), ==, 99999999UL);

    // Reset mockup state
    set_SDL_GetTicks_retVal(0UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest timerTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/timerInit-failing", timerInitFailing),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerInit-success", timerInitSuccess),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerIsInitialized", timerIsInitialized),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerGlobalTime", timerGlobalTime),
    GET_TEST_FUNC_ARRAY_ENTRY("/createTimer", createTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerStart-emptyTimer", timerStartEmptyTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerStart-pausedTimer", timerStartPausedTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerPause-emptyTimer", timerPauseEmptyTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerPause-runningTimer", timerPauseRunningTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerStop-emptyTimer", timerStopEmptyTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerStop-pausedTimer", timerStopPausedTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerStop-runningTimer", timerStopRunningTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerReset-emptyTimer", timerResetEmptyTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerReset-pausedTimer", timerResetPausedTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerReset-runningTimer", timerResetRunningTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerGetState", timerGetState),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerGetElapsedTime-emptyTimer", timerGetElapsedTimeEmptyTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerGetElapsedTime-pausedTimer", timerGetElapsedTimePausedTimer),
    GET_TEST_FUNC_ARRAY_ENTRY("/timerGetElapsedTime-runningTimer", timerGetElapsedTimeRunningTimer),

    TEST_FUNC_ARRAY_END
};

static MunitSuite timerTestsSuite = {
    "/all",
    timerTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite timerAllTestsGetSuite(void) {
    return timerTestsSuite;
}