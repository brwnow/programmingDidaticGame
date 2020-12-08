#include <munit.h>
#include <testsdefs.h>

#include "utils\datastructure\list.h"

// CREATING

MUNIT_DECLARE_TEST_FUNC(listCreate);

// GETTING INFO

// Getting number of elements from empty list
MUNIT_DECLARE_SETUP_FUNC(listGetElementsCountEmpty);
MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCountEmpty);
MUNIT_DECLARE_TEST_FUNC(listGetElementsCountEmpty);

// Getting number of elements from populated list
MUNIT_DECLARE_SETUP_FUNC(listGetElementsCount);
MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCount);
MUNIT_DECLARE_TEST_FUNC(listGetElementsCount);

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

// Inserting large amount of elements in random positions
MUNIT_DECLARE_SETUP_FUNC(listInsertLargeAmount);
MUNIT_DECLARE_TEARDOWN_FUNC(listInsertLargeAmount);
MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount);

// Inserting an element in an invalid position
MUNIT_DECLARE_SETUP_FUNC(listInsertInInvalidPosition);
MUNIT_DECLARE_TEARDOWN_FUNC(listInsertInInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition);

// REMOVING

// Removing with pop front operation from empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyPopFront);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPopFront);
MUNIT_DECLARE_TEST_FUNC(listEmptyPopFront);

// Removing with pop back operation from empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyPopBack);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPopBack);
MUNIT_DECLARE_TEST_FUNC(listEmptyPopBack);

// Removing with remove from empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyRemove);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyRemove);
MUNIT_DECLARE_TEST_FUNC(listEmptyRemove);

// Removing all elements with remove all elements operations from empty list
MUNIT_DECLARE_SETUP_FUNC(listEmptyRemoveAllElements);
MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyRemoveAllElements);
MUNIT_DECLARE_TEST_FUNC(listEmptyRemoveAllElements);

// Removing with pop front operation from populated list
MUNIT_DECLARE_SETUP_FUNC(listPopFront);
MUNIT_DECLARE_TEARDOWN_FUNC(listPopFront);
MUNIT_DECLARE_TEST_FUNC(listPopFront);

// Removing with pop back operation from populated list
MUNIT_DECLARE_SETUP_FUNC(listPopBack);
MUNIT_DECLARE_TEARDOWN_FUNC(listPopBack);
MUNIT_DECLARE_TEST_FUNC(listPopBack);

// Removing with remove from populated list
MUNIT_DECLARE_SETUP_FUNC(listRemove);
MUNIT_DECLARE_TEARDOWN_FUNC(listRemove);
MUNIT_DECLARE_TEST_FUNC(listRemove);

// Removing with remove from populated list pasing an invalid position
MUNIT_DECLARE_SETUP_FUNC(listRemoveInvalidPosition);
MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveInvalidPosition);
MUNIT_DECLARE_TEST_FUNC(listRemoveInvalidPosition);

// Removing all elements from a populated list with remove all elements operation
MUNIT_DECLARE_SETUP_FUNC(listRemoveAllElements);
MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveAllElements);
MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements);

// MIX INSERT-REMOVE

// Inserting and removing randomly large amount of elements
MUNIT_DECLARE_TEST_FUNC(listInsertAndRemoveLargeAmount);

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

// GETTING INFO

    {
        "/listGetElementsCount-emptyList",
        MUNIT_TEST_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_SETUP_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_TEARDOWN_FUNC_NAME(listGetElementsCountEmpty),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listGetElementsCount-populatedList",
        MUNIT_TEST_FUNC_NAME(listGetElementsCount),
        MUNIT_SETUP_FUNC_NAME(listGetElementsCount),
        MUNIT_TEARDOWN_FUNC_NAME(listGetElementsCount),
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
        "/listInsert-largeAmount",
        MUNIT_TEST_FUNC_NAME(listInsertLargeAmount),
        MUNIT_SETUP_FUNC_NAME(listInsertLargeAmount),
        MUNIT_TEARDOWN_FUNC_NAME(listInsertLargeAmount),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-invalidPosition",
        MUNIT_TEST_FUNC_NAME(listInsertInInvalidPosition),
        MUNIT_SETUP_FUNC_NAME(listInsertInInvalidPosition),
        MUNIT_TEARDOWN_FUNC_NAME(listInsertInInvalidPosition),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

// REMOVING

    {
        "/listPopFront-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyPopFront),
        MUNIT_SETUP_FUNC_NAME(listEmptyPopFront),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyPopFront),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPopBack-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyPopBack),
        MUNIT_SETUP_FUNC_NAME(listEmptyPopBack),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyPopBack),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyRemove),
        MUNIT_SETUP_FUNC_NAME(listEmptyRemove),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyRemove),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemoveAll-emptyList",
        MUNIT_TEST_FUNC_NAME(listEmptyRemoveAllElements),
        MUNIT_SETUP_FUNC_NAME(listEmptyRemoveAllElements),
        MUNIT_TEARDOWN_FUNC_NAME(listEmptyRemoveAllElements),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPopFront-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listPopFront),
        MUNIT_SETUP_FUNC_NAME(listPopFront),
        MUNIT_TEARDOWN_FUNC_NAME(listPopFront),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPopBack-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listPopBack),
        MUNIT_SETUP_FUNC_NAME(listPopBack),
        MUNIT_TEARDOWN_FUNC_NAME(listPopBack),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listRemove),
        MUNIT_SETUP_FUNC_NAME(listRemove),
        MUNIT_TEARDOWN_FUNC_NAME(listRemove),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-invalidPosition",
        MUNIT_TEST_FUNC_NAME(listRemoveInvalidPosition),
        MUNIT_SETUP_FUNC_NAME(listRemoveInvalidPosition),
        MUNIT_TEARDOWN_FUNC_NAME(listRemoveInvalidPosition),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemoveAll-notEmptyList",
        MUNIT_TEST_FUNC_NAME(listRemoveAllElements),
        MUNIT_SETUP_FUNC_NAME(listRemoveAllElements),
        MUNIT_TEARDOWN_FUNC_NAME(listRemoveAllElements),
        MUNIT_TEST_OPTION_NONE,
        NULL
    },

// MIX INSERT-REMOVE

    {
        "/listInsertRemove-largeAmount",
        MUNIT_TEST_FUNC_NAME(listInsertAndRemoveLargeAmount),
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

// GETTING INFO

MUNIT_DECLARE_SETUP_FUNC(listGetElementsCountEmpty) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCountEmpty) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listGetElementsCountEmpty) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listGetElementsCount) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));
    listPushBack(list, malloc(sizeof(float)));

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCount) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listGetElementsCount) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// INSERTING

MUNIT_DECLARE_SETUP_FUNC(listEmptyPushFront) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPushFront) {
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

MUNIT_DECLARE_SETUP_FUNC(listInsertLargeAmount) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(int)));

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listInsertLargeAmount) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listInsertLargeAmount) {
    List *list = (List*)user_data_or_fixture;
    const size_t amountToBeInserted = 50000;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 1UL);

    for(size_t i = 0; i < amountToBeInserted; ++i) {
        int insertMethod = munit_rand_int_range(0, 2);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)listGetElementsCount(list));
        ListResultCode ret = LIST_RC_FAIL;

        switch (insertMethod)
        {
        case 0:
            ret = listInsert(list, position, malloc(sizeof(int)));
            break;

        case 1:
            ret = listPushFront(list, malloc(sizeof(int)));
            break;

        case 2:
            ret = listPushBack(list, malloc(sizeof(int)));
            break;
        }

        munit_assert_ulong(ret, ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, amountToBeInserted + 1);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listInsertInInvalidPosition) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(double)));
    listPushBack(list, malloc(sizeof(double)));
    listPushBack(list, malloc(sizeof(double)));

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listInsertInInvalidPosition) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listInsertInInvalidPosition) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    munit_assert_ulong(listInsert(list, 5UL, NULL), ==, LIST_RC_OUT_OF_BOUNDS);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// REMOVING

MUNIT_DECLARE_SETUP_FUNC(listEmptyPopFront) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPopFront) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyPopFront) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    munit_assert_ulong(listPopFront(list), ==, LIST_RC_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listEmptyPopBack) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyPopBack) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyPopBack) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    munit_assert_ulong(listPopBack(list), ==, LIST_RC_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}


// ============

MUNIT_DECLARE_SETUP_FUNC(listEmptyRemove) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyRemove) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyRemove) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    munit_assert_ulong(listRemove(list, 0UL), ==, LIST_RC_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}


// ============

MUNIT_DECLARE_SETUP_FUNC(listEmptyRemoveAllElements) {
    return listCreate();
}

MUNIT_DECLARE_TEARDOWN_FUNC(listEmptyRemoveAllElements) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listEmptyRemoveAllElements) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    munit_assert_ulong(listRemoveAll(list), ==, LIST_RC_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}


// ============

MUNIT_DECLARE_SETUP_FUNC(listPopFront) {
    List *list = listCreate();

    int *elem = malloc(sizeof(int));
    *elem = 20;
    listPushBack(list, elem);
    elem = malloc(sizeof(int));
    *elem = 35;
    listPushBack(list, elem);
    elem = malloc(sizeof(int));
    *elem = 59;
    listPushBack(list, elem);

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listPopFront) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listPopFront) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listPopBack) {
    return NULL;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listPopBack) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listPopBack) {
    return MUNIT_FAIL;
}


// ============

MUNIT_DECLARE_SETUP_FUNC(listRemove) {
    return NULL;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemove) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemove) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemoveInvalidPosition) {
    return NULL;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveInvalidPosition) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemoveInvalidPosition) {
    return MUNIT_FAIL;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemoveAllElements) {
    return NULL;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveAllElements) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements) {
    return MUNIT_FAIL;
}


// MIX INSERT-REMOVE

MUNIT_DECLARE_TEST_FUNC(listInsertAndRemoveLargeAmount) {
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