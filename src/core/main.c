#include "main.h"

#include <SDL.h>

#include "utils/log.h"
#include "core/video/video.h"
#include "core/input/events.h"
#include "core/input/keyboard.h"
#include "core/video/window.h"

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    if(appInit() == false)
        return 0;

    if(keyboardInit() == false)
        return 0;

    if(windowStartup("Breno Game", 800, 600) == false)
        return 0;

    while(isKeyPressed(SDL_SCANCODE_ESCAPE) == false) {
        SDL_PumpEvents();

        SDL_Delay(25);
    }

    windowClose();
    keyboardEnd();
    appEnd();

    return 0;
}

bool appInit(void) {
    logInfo("Initializing application");

    logInit();

    if(SDL_Init(SDL_INIT_TIMER) != 0) {
        logCritical("SDL initialization failed - reason: %s", SDL_GetError());

        return false;
    } else if(videoInit() == false) {
        return false;
    } else if(eventsInit() == false) {
        return false;
    } else {
        logInfo("Application succesfully initialized");

        return true;
    }
}

void appEnd(void) {
    logInfo("Stopping application");

    videoEnd();
    SDL_Quit();
}