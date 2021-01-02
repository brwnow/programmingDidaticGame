/**
 * @file keyboard.h
 * @brief Keyboard API
 *
 * API for keyboard setup and read input functions
 * 
 */

#ifndef _DIDATIC_GAME_INPUT_KEYBOARD_H_
#define _DIDATIC_GAME_INPUT_KEYBOARD_H_

#include "definitions/global.h"

#include <SDL_events.h>

/**
 * @brief Initializes the resources needed by keyboard
 * 
 * It's necessary calling this function in order to enable keyboard support
 * After this function is called, keyboard resources are initialized and
 * all functions from this API will be enabled if it successfully initialize
 * the keybaord resources
 * 
 * @return On success returns true
 * @return Otherwise returns false
 */
bool keyboardInit(void);

/**
 * @brief Free keyboard resources and deinit it
 * 
 * After calling this function keyboard is disabled
 * 
 */
void keyboardEnd(void);

/**
 * @brief Checks if the key with code #scancode is pressed
 * 
 * @param[in] scancode The key of the key to check wheter is pressed
 * 
 * @return true if key with \p scancode is pressed
 * @return false otherwise
 */
bool isKeyPressed(unsigned scancode);

#endif // _DIDATIC_GAME_INPUT_KEYBOARD_H_