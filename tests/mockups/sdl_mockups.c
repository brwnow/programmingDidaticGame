#include "mockups/sdl_mockups.h"

// ======================
// == MOCKUPS CONTROLS ==
// ======================

static int SDL_InitSubSystem_retVal = 0;
static Uint32 SDL_GetTicks_retVal = 0UL;

void set_SDL_InitSubSystem_retVal(int retVal) {
    SDL_InitSubSystem_retVal = retVal;
}

void set_SDL_GetTicks_retVal(Uint32 retVal) {
    SDL_GetTicks_retVal = retVal;
}

// =============================
// == MOCKUPS IMPLEMENTATIONS ==
// =============================

int SDL_InitSubSystem(Uint32 flags) {
    (void)flags;

    return SDL_InitSubSystem_retVal;
}

void SDL_QuitSubSystem(Uint32 flags) {
    (void)flags;
}

Uint32 SDL_GetTicks(void) {
    return SDL_GetTicks_retVal;
}