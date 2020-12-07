#include <munit.h>
#include <testsdefs.h>

#include "utils\datastructure\list.h"

// CREATING

MUNIT_DECLARE_TEST_FUNC(listCreate);

// INSERTING

// Inserting with push front operation in an empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyPushFront);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPushFront);
MUNIT_DECLARE_TEST_FUNC(listEmptyPushFront);

// Inserting with push back operation in an empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyPushBack);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPushBack);
MUNIT_DECLARE_TEST_FUNC(listEmptyPushBack);

// Inserting with insert operation in the last possible index
MUNIT_DECLARE_SETUP_FUNC(listEmptyInsert);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyInsert);
MUNIT_DECLARE_TEST_FUNC(listEmptyInsert);

// Inserting with insert operation in variable positions
MUNIT_DECLARE_SETUP_FUNC(listNotEmptyInsertVariablePositions);
MUNIT_DECLARE_TEARDOWN_FUNC(listNotEmptyInsertVariablePositions);
MUNIT_DECLARE_TEST_FUNC(listNotEmptyInsertVariablePositions);


MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount);
MUNIT_DECLARE_TEST_FUNC(listInsertInValidPosition);
MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listInsertSublist);
MUNIT_DECLARE_TEST_FUNC(listInsertSublistInInvalidPosition);

// REMOVING

MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyValidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements);
MUNIT_DECLARE_TEST_FUNC(listRemoveFromEmpty);

// SEARCHING

// DESTROYING

MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty);

MUNIT_DECLARE_SETUP_FUNC(listDestroyEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty);

static MunitTest listTests[] = {

// CREATING

    {
        "/listCreate",
        MUNIT_TEST_FUNC_NAME(listCreate),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

// INSERTING

    {
        "/listPushFront-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyPushFront),
        MUNIT_SETUP_FUNC_NAME(listEmptyPushFront),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyPushFront),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPushBack-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyPushBack),
        MUNIT_SETUP_FUNC_NAME(listEmptyPushBack),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyPushBack),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyInsert),
        MUNIT_SETUP_FUNC_NAME(listEmptyInsert),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyInsert),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listNotEmptyInsertVariablePositions),
        MUNIT_SETUP_FUNC_NAME(listNotEmptyInsertVariablePositions),
        MUNIT_TEARDOWN_FUNC_NAME(listNotEmptyInsertVariablePositions),
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

// REMOVING

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

// SEARCHING



// DESTROYING

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

// CREATING

MUNIT_DECLARE_TEST_FUNC(listCreate) {
    List *list = listCreate();

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    listDestroy(list);

    return MUNIT_OK;
}

// INSERTING

MUNIT_DECLARE_SETUP_FUNC(listEmptyPushFront) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPushFront) {
    if(fixture != NULL)
        listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyPushFront) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listPushFront(list, elem), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);

    for(int i = elemsCount - 1; i >= 0; --i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[(size_t)i]);

        if(i > 0)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listEmptyPushBack) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPushBack) {
    if(fixture != NULL)
        listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyPushBack) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {-856, 41, 0, 23, 158, -89356, 54685, 321, 444, -4585, 84, -2};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listPushBack(list, elem), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);

    for(size_t i = 0; i < elemsCount; --i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[(size_t)i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listEmptyInsert) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyInsert) {
    if(fixture != NULL)
        listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyInsert) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {0, 50, 2, 999, 73};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listInsert(list, i, elem), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listNotEmptyInsertVariablePositions) {
    List *list = listCreate();
    char *pos1 = (char*)malloc(sizeof(char));
    char *pos2 = (char*)malloc(sizeof(char));
    char *pos3 = (char*)malloc(sizeof(char));

    *pos1 = 'a';
    *pos2 = 'z';
    *pos3 = 'k';

    listPushBack(list, pos1);
    listPushBack(list, pos2);
    listPushBack(list, pos3);

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listNotEmptyInsertVariablePositions) {
    if(fixture != NULL)
        listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listNotEmptyInsertVariablePositions) {
    List *list = (List*)user_data_or_fixture;
    char elems[] = {'a', 'b', 'c', 'z', 'i', 'p', 'k'};
    size_t elemsCount = sizeof(elems) / sizeof(char);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    char *elem = (char*)malloc(sizeof(char));
    *elem = elems[1];
    munit_assert_long(listInsert(list, 1, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[4];
    munit_assert_long(listInsert(list, 3, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[2];
    munit_assert_long(listInsert(list, 2, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[5];
    munit_assert_long(listInsert(list, 5, elem), ==, LIST_RC_OK);

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it);
        char val = *((char*)it->data);

        munit_assert_int(val, ==, elems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertInValidPosition) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertSublist) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertSublistInInvalidPosition) {
    return MUNIT_FAIL;
}

// REMOVING

MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyValidPosition) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveFromNotEmptyInvalidPosition) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveFromEmpty) {
    return MUNIT_FAIL;
}

// SEARCHING



// DESTROYING

MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty) {
    List *list = listCreate();
    listPushBack(list, malloc(1));

    return list;
}

MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), !=, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_RC_OK);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listDestroyEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEST_FUNC(listDestroyEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    ListResultCode ret = listDestroy(list);

    munit_assert_long(ret, ==, LIST_RC_OK);

    return MUNIT_OK;
}

MunitSuite listTestsGetSuite(void) {
    return listTestsSuite;
}