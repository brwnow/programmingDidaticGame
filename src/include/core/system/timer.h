/**
 * @file timer.h
 * @brief Timer useful functions API
 *
 * API for handling timers. All basic useful timer functions are present in this API
 */

#ifndef _DIDATIC_GAME_SYSTEM_TIMER_H_
#define _DIDATIC_GAME_SYSTEM_TIMER_H_

#include "definitions/global.h"

#include <SDL_timer.h>

/**
 * @brief Timer typedef for _Timer struct
 */
typedef struct _Timer Timer;

/**
 * @brief Timer possible states
 */
typedef enum _TimerState {
    TIMER_INVALID = -1, /**< Timer is in invalid state. Some critical error occurred or timer object is null pointer */
    TIMER_STOPPED, /**< Timer is stopped. Time count is zero */
    TIMER_PAUSED, /**< Timer is paused. Time count is that of the moment of pausing */
    TIMER_RUNNING /**< Timer is running and time count is updating */
} TimerState;

/**
 * @brief Initialize timer module and enable its functions
 * 
 * @return true if timer wwas succesfully initialized
 * @return false otherwise
 */
bool timerInit(void);

/**
 * @brief Disable timer module. Its functions stop working
 */
void timerEnd(void);

/**
 * @brief Checks if timer module is initialized
 * 
 * @return true if timer is already initialized
 * @return false otherwise
 */
bool timerIsInitialized(void);

/**
 * @brief Gets the time in ms since the timer module has been initialized
 * 
 * @return The time in ms since timer module initialized on success
 * @return 0 otherwise (since there is no meaningful moment where this function would return 0, it's ok to return 0 on fail)
 */
unsigned long timerGlobalTime(void);

/**
 * @brief Creates a new timer object.
 * 
 * @return The timer object on success
 * @return NULL otherwise
 */
Timer* createTimer(void);

/**
 * @brief Properly destroys a given timer
 */
void destroyTimer(Timer *timer);

/**
 * @brief Starts or resumes the timer depending on its current state.
 * 
 * * If current state is stopped, starts the timer.
 * * If current state is paused, resumes the timer.
 * 
 * @param timer A pointer to the timer object which will be started/resumed.
 */
void timerStart(Timer *timer);

/**
 * @brief Pauses the timer. If its already paused, do nothing
 * 
 * Paused timer returns the elapsed time at the moment of the pause
 * when #timerGetElapsedTime is called.
 * 
 * @param timer A pointer to the timer object which will be paused.
 */
void timerPause(Timer *timer);

/**
 * @brief Stops the timer.
 * 
 * When the timer is stopped, its elapsed time is reseted.
 * 
 * Also calls to #timerGetElapsedTime returns always zero.
 * 
 * If the timer is already stopped, nothing happens.
 * 
 * @param timer A pointer to the timer object which will be stopped.
 */
void timerStop(Timer *timer);

/**
 * @brief Resets the timer but does not change its current state
 * 
 * If a running timer is reseted, its elapsed time resets to zero but
 * it keeps running.
 * 
 * If a paused timer is reseted, its elapsed time is reseted and its continue
 * paused.
 * 
 * If a stopped timer is reseted, nothing happens.
 * 
 * @param timer A pointer to the timer object which will be reseted.
 */
void timerReset(Timer *timer);

/**
 * @brief Get the current state of the timer
 * 
 * See #_TimerState for more details about the states of timer
 * 
 * @param timer A pointer to the timer object from which to get the current state.
 */
TimerState timerGetState(Timer *timer);

/**
 * @brief Get the current elapsed time of the timre.
 * 
 * @param timer A pointer to the timer object from which to get the current elapsed time.
 * 
 * @return The current elapsed timer that the timer was running. If
 * the timer has been paused at least one time, the total paused time is discardaded. It
 * counts only elapsed time during runnings.
 * @return The elapsed time (considering the calculation of the running state)
 * at the momment of the pause.
 * @return Zero.
 */
unsigned long timerGetElapsedTime(Timer *timer);

#endif // _DIDATIC_GAME_SYSTEM_TIMER_H_