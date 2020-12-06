#include "core/video/window.h"

#include "utils/log/log.h"

// ===============
// PRIVATE SECTION
// ===============

// Window where to render all the game graphics
static SDL_Window *gameWindow = NULL;

// ==============
// PUBLIC SECTION
// ==============

bool windowStartup(const char *title, int width, int height) {
    logInfo("Creating game window");

    gameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(gameWindow == NULL) {
        logError("Failed creating game window - reason: %s", SDL_GetError());

        return false;
    } else {
        return true;
    }
}

void windowClose(void) {
    logInfo("Closing game window");

    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;
}

bool windowIsStarted(void) {
    return gameWindow != NULL;
}

SDL_Surface* windowGetScreen(void) {
    if(gameWindow != NULL) {
        SDL_Surface *windowSurface = SDL_GetWindowSurface(gameWindow);

        if(windowSurface != NULL) {
            return windowSurface;
        } else {
            logError("Failed getting window surface - reason: %s", SDL_GetError());

            return NULL;
        }
    } else {
        logDebug("Failed getting window screen. Window is not initialized");

        return NULL;
    }
}

void windowFlipPage(void) {
    if(gameWindow != NULL) {
        SDL_UpdateWindowSurface(gameWindow);
    } else {
        logDebug("Failed flipping page. Window is not initialized");
    }
}