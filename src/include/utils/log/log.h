#ifndef _DIDATIC_GAME_UTILS_LOG_H_
#define _DIDATIC_GAME_UTILS_LOG_H_

#include "definitions/global.h"

#include <SDL_log.h>

void logInit(void);

#ifdef _DEBUG_BUILD_
    #define logVerbose(x, ...) SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
    #define logDebug(x, ...) SDL_LogDebug(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
    #define logInfo(x, ...) SDL_LogInfo(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
    #define logWarn(x, ...) SDL_LogWarn(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
    #define logError(x, ...) SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
    #define logCritical(x, ...) SDL_LogCritical(SDL_LOG_CATEGORY_CUSTOM, x, ##__VA_ARGS__)
#else // _DEBUG_BUILD_
    #define logVerbose(...)
    #define logDebug(...)
    #define logInfo(...)
    #define logWarn(...)
    #define logError(...)
    #define logCritical(...)
#endif // _DEBUG_BUILD_

#endif // _DIDATIC_GAME_UTILS_LOG_H_