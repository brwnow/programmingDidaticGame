#ifndef _DIDATIC_GAME_SYSTEM_TIMER_PRIV_H_
#define _DIDATIC_GAME_SYSTEM_TIMER_PRIV_H_

#include <SDL_timer.h>

struct _Timer {
    unsigned long startTimemark;
    unsigned long pauseTimemark;
    TimerState state;
};

#endif // _DIDATIC_GAME_SYSTEM_TIMER_PRIV_H_