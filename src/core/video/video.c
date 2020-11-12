#include "core/video/video.h"

#include <SDL.h>

#include "utils/log.h"

// ===============
// PRIVATE SECTION
// ===============

static bool videoInitialized = false;

// ==============
// PUBLIC SECTION
// ==============

bool videoInit(void) {
    logInfo("Initializing video");

    if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
        logCritical("Video initialization failed - reason: %s", SDL_GetError());

        videoInitialized = false;
    } else {
        logInfo("Video succesfully initialized");

        videoInitialized = true;
    }

    return videoInitialized;
}

void videoEnd(void) {
    logInfo("Stopping video");

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

bool videoIsInitialized(void) {
    return videoInitialized;
}