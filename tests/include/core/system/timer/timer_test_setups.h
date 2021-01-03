#ifndef _DIDATIC_GAME_TEST_TIMER_SETUPS_H
#define _DIDATIC_GAME_TEST_TIMER_SETUPS_H

#include <testsdefs.h>

// =======================
/* Empty timer
 *
 * fixture format: pointer to a timer object
 */
DECLARE_SETUP_FUNC(timerEmpty);
DECLARE_TEARDOWN_FUNC(timerEmpty);

// =======================
/* Running timer
 * startTimemark is at 500, pauseTimemark is 0
 *
 * fixture format: pointer to a timer object
 */
DECLARE_SETUP_FUNC(timerRunning);
DECLARE_TEARDOWN_FUNC(timerRunning);

// =======================
/* Paused timer
 * startTimemark is at 900, pauseTimemark is at 1200
 *
 * fixture format: pointer to a timer object
 */
DECLARE_SETUP_FUNC(timerPaused);
DECLARE_TEARDOWN_FUNC(timerPaused);

#endif // _DIDATIC_GAME_TEST_TIMER_SETUPS_H
