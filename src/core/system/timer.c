#include "core/system/timer.h"

#include <stdlib.h>
#include <SDL.h>

#include "utils/log/log.h"

// ===============
// PRIVATE SECTION
// ===============

#include "core/system/timer_private.h"

static bool timerInitialized = false;

// ==============
// PUBLIC SECTION
// ==============

bool timerInit(void) {
    logInfo("Initializing timer");

    if(SDL_InitSubSystem(SDL_INIT_TIMER) != 0) {
        logCritical("Timer initialization failed - reason: %s", SDL_GetError());

        timerInitialized = false;
    } else {
        logInfo("Timer succesfully initialized");

        timerInitialized = true;
    }

    return timerInitialized;
}

void timerEnd(void) {
    logInfo("Stopping timer");

    SDL_QuitSubSystem(SDL_INIT_TIMER);
}

bool timerIsInitialized(void) {
    return timerInitialized;
}

unsigned long timerGlobalTime(void) {
    return (unsigned long)SDL_GetTicks();
}

Timer* createTimer(void) {
    Timer *newTimer = malloc(sizeof(Timer));

    if(newTimer == NULL)
        return NULL;

    newTimer->state = TIMER_STOPPED;
    newTimer->startTimemark = 0UL;
    newTimer->pauseTimemark = 0UL;

    return newTimer;
}

void destroyTimer(Timer *timer) {
    free(timer);
}

void timerStart(Timer *timer) {
    if(timer == NULL)
        return;

    Uint32 currentTimemark = timerGlobalTime();

    switch(timer->state) {
    case TIMER_PAUSED:
        timer->startTimemark += currentTimemark - timer->pauseTimemark;
        timer->pauseTimemark = 0UL;
        timer->state = TIMER_RUNNING;
        break;

    case TIMER_STOPPED:
        timer->pauseTimemark = 0UL;
        timer->startTimemark = currentTimemark;
        timer->state = TIMER_RUNNING;
        break;

    default:
        break;
    }
}

void timerPause(Timer *timer) {
    if(timer == NULL)
        return;

    if(timer->state == TIMER_RUNNING) {
        timer->pauseTimemark = timerGlobalTime();
        timer->state = TIMER_PAUSED;
    }
}

void timerStop(Timer *timer) {
    if(timer == NULL)
        return;

    timer->startTimemark = 0UL;
    timer->pauseTimemark = 0UL;
    timer->state = TIMER_STOPPED;
}

void timerReset(Timer *timer) {
    if(timer == NULL)
        return;

    if(timer->state == TIMER_STOPPED)
        return;

    timer->startTimemark = timerGlobalTime();

    if(timer->state == TIMER_PAUSED)
        timer->pauseTimemark = timer->startTimemark;
}

TimerState timerGetState(Timer *timer) {
    if(timer == NULL)
        return TIMER_INVALID;

    return timer->state;
}

unsigned long timerGetElapsedTime(Timer *timer) {
    if(timer == NULL)
        return 0UL;

    unsigned long elapsedTime = 0UL;

    switch(timer->state) {
    case TIMER_RUNNING:
        elapsedTime = timerGlobalTime() - timer->startTimemark;
        break;

    case TIMER_PAUSED:
        elapsedTime = timer->pauseTimemark - timer->startTimemark;
        break;

    default:
        elapsedTime = 0UL;
        break;
    }

    return elapsedTime;
}