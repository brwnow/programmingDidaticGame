#include <munit.h>
#include <testsdefs.h>

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
MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty);

static MunitTest listTests[] = {
    {
        "/listCreate",
        listCreate,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-emptyList",
        listEmptyInsert,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-notEmptyList",
        listNotEmptyInsert,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertingLargeAmount",
        listInsertLargeAmount,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertInValidPosition",
        listInsertInValidPosition,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-insertInvalidPosition",
        listInsertInInvalidPosition,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsertSublist-insertInValidPosition",
        listInsertSublist,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsertSublist-insertInvalidPosition",
        listInsertSublistInInvalidPosition,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeValidPositionFromNotEmptyList",
        listRemoveFromNotEmptyValidPosition,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeInvalidPositionFromNotEmptyList",
        listRemoveFromNotEmptyInvalidPosition,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeAllElements",
        listRemoveAllElements,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-removeFromEmptyList",
        listRemoveFromEmpty,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyNotEmptyList",
        listDestroyNotEmpty,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listDestroy-destroyEmptyList",
        listDestroyEmpty,
        NULL,
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

MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty) {
    return MUNIT_FAIL;
}

MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty) {
    return MUNIT_FAIL;
}

MunitSuite listTestsGetSuite(void) {
    return listTestsSuite;
}