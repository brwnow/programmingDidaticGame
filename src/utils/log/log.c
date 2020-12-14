#include "utils/log.h"

#ifdef _ENABLE_LOGS_

void logInit(void) {
    SDL_LogSetPriority(SDL_LOG_CATEGORY_CUSTOM, SDL_LOG_PRIORITY_VERBOSE);
}

#endif // _ENABLE_LOGS_