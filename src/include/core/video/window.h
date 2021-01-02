/**
 * @file window.h
 * @brief Windowing API
 *
 * API for managing window
 */

#ifndef _DIDATIC_GAME_VIDEO_WINDOW_H_
#define _DIDATIC_GAME_VIDEO_WINDOW_H_

#include "definitions/global.h"

#include <SDL.h>

/**
 * @brief Create the game window
 * 
 * This function allows the creating of only a single window
 * 
 * @param[in] title The title of the string
 * @param[in] width The inner width of the window, in pixels
 * @param[in] height The inner height of the window, in piexels
 * 
 * @return true if the window was succesfully created
 * @return false otherwise
 */
bool windowStartup(const char *title, int width, int height);

/**
 * @brief Close the current opened window and release its resources
 * 
 */
void windowClose(void);

/**
 * @brief Checks if there is a window already opened
 * 
 * @return true if the window is already created and opened
 * @return false otherwise
 */
bool windowIsStarted(void);

/**
 * @brief Get the drawable surface of the current opened window
 * 
 * This surface is where to draw all the game graphics, in order to be rendered to
 * the actual screen when #windowFlipPage is called
 * 
 * @return A pointer the the window screen on success
 * @return NULL otherwise
 */
SDL_Surface* windowGetScreen(void);

/**
 * @brief Flips the window buffer page and update the actual screen
 * 
 * When this function is called. Everything that was bufferred in the window
 * buffer page(got by calling #windowGetScreen), is showed in the actual screen
 * and the back buffer is cleared
 */
void windowFlipPage(void);

#endif // _DIDATIC_GAME_VIDEO_WINDOW_H_