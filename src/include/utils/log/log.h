#ifndef _DIDATIC_GAME_UTILS_LOG_H_
#define _DIDATIC_GAME_UTILS_LOG_H_

#include "definitions/global.h"

#include <SDL_log.h>

#ifdef _ENABLE_LOGS_
    #define MAX_LOG_INDENTATION 65

    // Public log functions declarations
    void logInit(void);

    // Log static functions and variables, also logs macros definitions
    static char logIndentation[MAX_LOG_INDENTATION] = { '\0' };
    static size_t logIndentationPos = 0;
    static size_t logIndentationStep = 4;

    static inline void logForwardIndentation(void) {
        if(logIndentationPos >= MAX_LOG_INDENTATION - 1)
            return;

        for(register size_t i = 0; i < logIndentationStep; ++i)
            logIndentation[logIndentationPos + i] = ' ';

        logIndentationPos += logIndentationStep;
        logIndentation[logIndentationPos] = '\0';
    }

    static inline void logBackwardIndentation(void) {
        if(logIndentationPos <= 0)
            return;

        for(register size_t i = 1; i <= logIndentationStep; ++i)
            logIndentation[logIndentationPos - i] = '\0';

        logIndentationPos -= logIndentationStep;
    }

    #define logVerboseEnter(x, ...) do { \
                                        SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, "%s< %s " #x " >", logIndentation, __func__, ##__VA_ARGS__); \
                                        logForwardIndentation(); \
                                    } while(0)
    #define logVerboseExit0()   do { \
                                    logBackwardIndentation(); \
                                    SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, "%s< /%s >", logIndentation, __func__); \
                                } while(0)
    #define logVerboseExit1(x, ...)   do { \
                                    logBackwardIndentation(); \
                                    SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, "%s< /%s " #x " >", logIndentation, __func__, ##__VA_ARGS__); \
                                } while(0)

    #define logVerbose(x, ...) SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)
    #define logDebug(x, ...) SDL_LogDebug(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)
    #define logInfo(x, ...) SDL_LogInfo(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)
    #define logWarn(x, ...) SDL_LogWarn(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)
    #define logError(x, ...) SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)
    #define logCritical(x, ...) SDL_LogCritical(SDL_LOG_CATEGORY_CUSTOM, "%s" #x, logIndentation, ##__VA_ARGS__)

#else // _ENABLE_LOGS_
    // Stubbing log public functions
    #define logInit()

    // Stubbing logs macros
    #define logVerboseEnter(...)
    #define logVerboseExit0()
    #define logVerboseExit1(ret)
    #define logVerbose(...)
    #define logDebug(...)
    #define logInfo(...)
    #define logWarn(...)
    #define logError(...)
    #define logCritical(...)
#endif // _ENABLE_LOGS_

#endif // _DIDATIC_GAME_UTILS_LOG_H_