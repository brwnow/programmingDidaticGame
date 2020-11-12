#ifndef _DIDATIC_GAME_INPUT_EVENTS_H_
#define _DIDATIC_GAME_INPUT_EVENTS_H_

#include "definitions/global.h"

#include <SDL_events.h>

bool eventsInit(void);
void eventsEnd(void);

bool eventsIsInitialized(void);

void eventsAddListener(SDL_EventFilter listener, void *data);

#endif // _DIDATIC_GAME_INPUT_EVENTS_H_