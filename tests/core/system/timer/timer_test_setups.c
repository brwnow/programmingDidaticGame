#include "core/system/timer/timer_test_setups.h"

#include <stdlib.h>

#include "core/system/timer.h"
#include "core/system/timer_private.h"

// =======================
// Empty timer
DECLARE_SETUP_FUNC(timerEmpty) {
    return createTimer();
}

DECLARE_TEARDOWN_FUNC(timerEmpty) {
    destroyTimer(fixture);
}

// =======================
// Running timer
DECLARE_SETUP_FUNC(timerRunning) {
    Timer *timer = createTimer();

    timer->startTimemark = 500UL;
    timer->state = TIMER_RUNNING;

    return timer;
}

DECLARE_TEARDOWN_FUNC(timerRunning) {
    destroyTimer(fixture);
}

// =======================
// Paused timer
DECLARE_SETUP_FUNC(timerPaused) {
    Timer *timer = createTimer();

    timer->startTimemark = 900UL;
    timer->pauseTimemark = 1200UL;
    timer->state = TIMER_PAUSED;

    return timer;
}

DECLARE_TEARDOWN_FUNC(timerPaused) {
    destroyTimer(fixture);
}
