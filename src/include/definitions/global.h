#ifndef _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_
#define _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_

#define UNUSED(x) (void)x

#ifndef bool
    #define bool int
#endif // bool

#ifndef true
    #define true 1
#endif // true

#ifndef false
    #define false 0
#endif // false

#define bool_cast(x) x ? true : false

#endif // _DIDATIC_GAME_DEFINITIONS_GLOBAL_H_