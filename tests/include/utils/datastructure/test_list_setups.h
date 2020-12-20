#ifndef _DIDATIC_GAME_TEST_LIST_SETUPS_H
#define _DIDATIC_GAME_TEST_LIST_SETUPS_H

#include <testsdefs.h>

// =======================
// Empty list
DECLARE_SETUP_FUNC(listEmpty);
DECLARE_TEARDOWN_FUNC(listEmpty);

// =======================
// Empty list with stub teardown (nothing is really cleaned up)
DECLARE_SETUP_FUNC(listEmptyStubTd);
DECLARE_TEARDOWN_FUNC(listEmptyStubTd);

// =======================
// Single element list
// the element is an int with value 5
DECLARE_SETUP_FUNC(listSingleElement);
DECLARE_TEARDOWN_FUNC(listSingleElement);

// =======================
// Single element list with stub teardown (nothing is really cleaned up)
// the element is an int with value 5
DECLARE_SETUP_FUNC(listSingleElementStubTd);
DECLARE_TEARDOWN_FUNC(listSingleElementStubTd);

// =======================

#endif // _DIDATIC_GAME_TEST_LIST_SETUPS_H