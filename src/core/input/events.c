#include "core/input/events.h"

#include <SDL.h>

#include "utils/log/log.h"

// ===============
// PRIVATE SECTION
// ===============

static bool eventsInitialized = false;

// ==============
// PUBLIC SECTION
// ==============

bool eventsInit(void) {
    logInfo("Initializing events");

    if(SDL_InitSubSystem(SDL_INIT_EVENTS) != 0) {
        logCritical("Failed to initialize events - reason: %s", SDL_GetError());

        return false;
    } else {
        logInfo("Events succesfully initialized");

        eventsInitialized = true;

        return true;
    }
}

void eventsEnd(void) {
    logInfo("Stopping events");

    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

bool eventsIsInitialized(void) {
    return eventsInitialized;
}

void eventsAddListener(SDL_EventFilter listener, void *data) {
    logInfo("Trying to add listener");

    SDL_AddEventWatch(listener, data);
}