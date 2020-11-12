#ifndef _DIDATIC_GAME_INPUT_KEYBOARD_H_
#define _DIDATIC_GAME_INPUT_KEYBOARD_H_

#include "definitions/global.h"

#include <SDL_events.h>

bool keyboardInit(void);
void keyboardEnd(void);

bool isKeyPressed(unsigned scancode);

#endif // _DIDATIC_GAME_INPUT_KEYBOARD_H_