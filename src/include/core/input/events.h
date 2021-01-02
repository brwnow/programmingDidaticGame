/**
 * @file events.h
 * @brief Events handling API
 *
 * API for handling application events (I/O and others)
 */

#ifndef _DIDATIC_GAME_INPUT_EVENTS_H_
#define _DIDATIC_GAME_INPUT_EVENTS_H_

#include "definitions/global.h"

#include <SDL_events.h>

/**
 * @brief Initialize events module and enable its functions
 * 
 * @return true if events were succesfully initialized
 * @return false otherwise
 */
bool eventsInit(void);

/**
 * @brief Disable events module. Its functions stop working
 */
void eventsEnd(void);

/**
 * @brief Checks if events module is initialized
 * 
 * @return true if events are already initialized
 * @return false otherwise
 */
bool eventsIsInitialized(void);

/**
 * @brief Adds an event listener callback
 * 
 * Adds a callback to event handling pool. Everytime an event occurs
 * the callback \p listener will be called passing \p data
 * 
 * @param[in] listener An event callback
 * @param[in] data Pointer to block of data that will be passed to listener when calling it
 */
void eventsAddListener(SDL_EventFilter listener, void *data);

#endif // _DIDATIC_GAME_INPUT_EVENTS_H_