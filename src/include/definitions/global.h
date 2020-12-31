#ifndef _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_
#define _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_

#include <stdbool.h>

#define UNUSED(x) (void)x

// For testing porpuse it's necessary to have a way to make static functions public
#ifdef _TESTS_ENABLED_
    #define private
#else // _TESTS_ENABLED_
    #define private static inline
#endif // _TESTS_ENABLED_

#endif // _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_