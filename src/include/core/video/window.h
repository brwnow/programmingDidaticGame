#ifndef _DIDATIC_GAME_VIDEO_WINDOW_H_
#define _DIDATIC_GAME_VIDEO_WINDOW_H_

#include "definitions/global.h"

#include <SDL.h>

bool windowStartup(const char *title, int width, int height);
void windowClose(void);

bool windowIsStarted(void);

SDL_Surface* windowGetScreen(void);

void windowFlipPage(void);

#endif // _DIDATIC_GAME_VIDEO_WINDOW_H_