/**
 * @file video.h
 * @brief Video basic routines
 *
 * API for video initialization
 */

#ifndef _DIDATIC_GAME_VIDEO_H_
#define _DIDATIC_GAME_VIDEO_H_

#include "definitions/global.h"

/**
 * @brief Initialize video resources. This function must be called before any graphic rendering performs
 * 
 * @return true if video is properly initialized
 * @return false otherwise
 */
bool videoInit(void);

/**
 * @brief Release video resoures and disable video
 * 
 */
void videoEnd(void);

/**
 * @brief Checks if video is already initialized
 * 
 * @return true if video is properly initialized
 * @return false otherwise
 */
bool videoIsInitialized(void);

#endif // _DIDATIC_GAME_VIDEO_H_