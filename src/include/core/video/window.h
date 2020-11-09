#ifndef _DIDATIC_GAME_VIDEO_WINDOW_H_
#define _DIDATIC_GAME_VIDEO_WINDOW_H_

#include "definitions/global.h"

bool windowStartup(const char *title, int width, int height);
void windowClose(void);

bool windowIsStarted(void);

#endif // _DIDATIC_GAME_VIDEO_WINDOW_H_