#include <munit.h>
#include <testsdefs.h>

#include "utils\datastructure\list.h"

MUNIT_DECLARE_TEST_FUNC(listCreate);
MUNIT_DECLARE_TEST_FUNC(listEmptyInsert);
MUNIT_DECLARE_TEST_FUNC(listNotEmptyInsert);
MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount);
MUNIT_DECLARE_TEST_FUNC(listInsertInValidPosition);
MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listInsertSublist);
MUNIT_DECLARE_TEST_FUNC(listInsertSublistInInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyValidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements);
MUNIT_DECLARE_TEST_FUNC(listRemoveFromEmpty);

MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty);

MUNIT_DECLARE_SETUP_FUNC(listDestroyEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty);

static MunitTest listTests[] = {
    {
        "/listCreate",
        MUNIT_TEST_FUNC_NAME(listCreate),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyInsert),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listNotEmptyInsert),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertingLargeAmount",
        MUNIT_TEST_FUNC_NAME(listInsertLargeAmount),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertInValidPosition",
        MUNIT_TEST_FUNC_NAME(listInsertInValidPosition),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertInvalidPosition",
        MUNIT_TEST_FUNC_NAME(listInsertInInvalidPosition),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsertSublist-insertInValidPosition",
        MUNIT_TEST_FUNC_NAME(listInsertSublist),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsertSublist-insertInvalidPosition",
        MUNIT_TEST_FUNC_NAME(listInsertSublistInInvalidPosition),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeValidPositionFromNotEmptyList",
        MUNIT_TEST_FUNC_NAME(listRemoveFromNotEmptyValidPosition),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeInvalidPositionFromNotEmptyList",
        MUNIT_TEST_FUNC_NAME(listRemoveFromNotEmptyInvalidPosition),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeAllElements",
        MUNIT_TEST_FUNC_NAME(listRemoveAllElements),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeFromEmptyList",
        MUNIT_TEST_FUNC_NAME(listRemoveFromEmpty),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyNotEmptyList",
        MUNIT_TEST_FUNC_NAME(listDestroyNotEmpty),
        MUNIT_SETUP_FUNC_NAME(listDestroyNotEmpty),
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyEmptyList",
        MUNIT_TEST_FUNC_NAME(listDestroyEmpty),
        MUNIT_SETUP_FUNC_NAME(listDestroyEmpty),
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitSuite listTestsSuite = {
    "/utils/datastructure/list",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MUNIT_DECLARE_TEST_FUNC(listCreate) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listEmptyInsert) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listNotEmptyInsert) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listInsertInValidPosition) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listInsertSublist) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listInsertSublistInInvalidPosition) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyValidPosition) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyInvalidPosition) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listRemoveFromEmpty) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty) {
    List *list = (List*)user_data_or_fixture;

    if(list == NULL)
        return MUNIT_ERROR;

    if(listGetElementsCount(list) == 0)
        return MUNIT_ERROR;

    ListResultCode ret = listDestroy(list);

    if(ret == LIST_RC_OK)
        return MUNIT_OK;
    else
        return MUNIT_FAIL;
}

MUNIT_DECLARE_SETUP_FUNC(listDestroyEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty) {
    List *list = (List*)user_data_or_fixture;

    if(list == NULL)
        return MUNIT_ERROR;

    ListResultCode ret = listDestroy(list);

    if(ret == LIST_RC_OK)
        return MUNIT_OK;
    else
        return MUNIT_FAIL;
}

MunitSuite listTestsGetSuite(void) {
    return listTestsSuite;
}