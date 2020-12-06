#include "core/input/keyboard.h"

#include <SDL_mutex.h>

#include "utils/log/log.h"
#include "core/input/events.h"

// ===============
// PRIVATE SECTION
// ===============

// Array that holds the state of each possible key. A given index i represents

// the key with keycode i. True means key pressed and false means key is not pressed
static volatile bool keysState[SDL_NUM_SCANCODES];
static SDL_mutex *keysStateMutex = NULL;

static void setKeyState(unsigned scancode, bool state) {
    if(keysStateMutex == NULL) {
        logError("Error while setting state for key %d because its mutex is NULL", scancode);

        return;
    }

    if(SDL_LockMutex(keysStateMutex) == 0) {
        keysState[scancode] = state;

        SDL_UnlockMutex(keysStateMutex);
    } else {
        logError("Error while setting state for key %d because it was not possible to lock its mutex - reson: %s", scancode, SDL_GetError());
    }
}

static int keyboardInputListener(void *data, SDL_Event *event) {
    Uint32 eventType = event->type;

    UNUSED(data);

    if(eventType == SDL_KEYDOWN || eventType == SDL_KEYUP) {
        SDL_KeyboardEvent *keyEvent = &(event->key);

        logVerbose("Key event captured | event type %u | key scancode %d", eventType, keyEvent->keysym.scancode);

        if(keyEvent->repeat == 0) {
            setKeyState(keyEvent->keysym.scancode, eventType == SDL_KEYDOWN);
        }
    }

    // This is expected by SDL event manager to process internally this event
    return 1;
}

// ==============
// PUBLIC SECTION
// ==============

bool keyboardInit(void) {
    logInfo("Initializing keyboard");

    eventsAddListener(keyboardInputListener, NULL);

    // Initialize keysState array with all keys not pressed
    for(unsigned i = 0; i < SDL_NUM_SCANCODES; ++i)
        keysState[i] = false;

    keysStateMutex = SDL_CreateMutex();

    if(keysStateMutex == NULL) {
        logCritical("Failed to create keys state mutex - reason: %s", SDL_GetError());

        return false;
    }

    return true;
}

void keyboardEnd(void) {
    logInfo("Stopping keyboard");

    SDL_DestroyMutex(keysStateMutex);
    keysStateMutex = NULL;
}

bool isKeyPressed(unsigned scancode) {
    if(keysStateMutex == NULL) {
        logError("Error while getting state of key %d because its mutex is NULL - reason: %s", scancode, SDL_GetError());

        return false;
    }

    if(SDL_LockMutex(keysStateMutex) == 0) {
        bool keyState = keysState[scancode];

        SDL_UnlockMutex(keysStateMutex);

        return keyState;
    } else {
        logError("Error while getting state of key %d because it was not possible to lock its mutex - reson: %s", scancode, SDL_GetError());

        return false;
    }
}
