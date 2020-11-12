#include "utils/log.h"

void logInit(void) {
    SDL_LogSetPriority(SDL_LOG_CATEGORY_CUSTOM, SDL_LOG_PRIORITY_VERBOSE);
}