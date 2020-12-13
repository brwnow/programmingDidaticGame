#include <munit.h>
#include <testsdefs.h>

#include "utils\datastructure\list.h"

// CREATING

MUNIT_DECLARE_TEST_FUNC(listCreate);

// GETTING INFO

// Passing null pointer to listGetElementsCount
MUNIT_DECLARE_TEST_FUNC(listGetElementsCountNullPtr);

// Getting number of elements from empty list
MUNIT_DECLARE_SETUP_FUNC(listGetElementsCountEmpty);
MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCountEmpty);
MUNIT_DECLARE_TEST_FUNC(listGetElementsCountEmpty);

// Getting number of elements from populated list
MUNIT_DECLARE_SETUP_FUNC(listGetElementsCount);
MUNIT_DECLARE_TEARDOWN_FUNC(listGetElementsCount);
MUNIT_DECLARE_TEST_FUNC(listGetElementsCount);

// INSERTING

// Passing null pointer to listPushFront
MUNIT_DECLARE_TEST_FUNC(listPushFrontNullPtr);

// Passing null pointer to listPushBack
MUNIT_DECLARE_TEST_FUNC(listPushBackNullPtr);

// Passing null pointer to listInsertAtIndex
MUNIT_DECLARE_TEST_FUNC(listInsertNullPtr);

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

// Passing null pointer to listPopFront
MUNIT_DECLARE_TEST_FUNC(listPopFrontNullPtr);

// Passing null pointer to listPopBack
MUNIT_DECLARE_TEST_FUNC(listPopBackNullPtr);

// Passing null pointer to listRemove
MUNIT_DECLARE_TEST_FUNC(listRemoveNullPtr);

// Passing null pointer to listRemoveAll
MUNIT_DECLARE_TEST_FUNC(listRemoveAllNullPtr);

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

// Removing with remove random index from populated list
MUNIT_DECLARE_SETUP_FUNC(listRemoveRandom);
MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveRandom);
MUNIT_DECLARE_TEST_FUNC(listRemoveRandom);

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

// Passing null pointer to listDestroy
MUNIT_DECLARE_TEST_FUNC(listDestroyNullPtr);

// Destroying populated list
MUNIT_DECLARE_SETUP_FUNC(listDestroyNotEmpty);
MUNIT_DECLARE_TEST_FUNC(listDestroyNotEmpty);

// Destroying empty lit
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
        "/listGetElementsCount-nullPtr",
        MUNIT_TEST_FUNC_NAME(listGetElementsCountNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
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
        "/listPushFront-nullPtr",
        MUNIT_TEST_FUNC_NAME(listPushFrontNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPushBack-nullPtr",
        MUNIT_TEST_FUNC_NAME(listPushBackNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listInsert-nullPtr",
        MUNIT_TEST_FUNC_NAME(listInsertNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
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
        "/listPopFront-nullPtr",
        MUNIT_TEST_FUNC_NAME(listPopFrontNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listPopBack-nullPtr",
        MUNIT_TEST_FUNC_NAME(listPopBackNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemove-nullPtr",
        MUNIT_TEST_FUNC_NAME(listRemoveNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/listRemoveAll-nullPtr",
        MUNIT_TEST_FUNC_NAME(listRemoveAllNullPtr),
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
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
        "/listRemove-random",
        MUNIT_TEST_FUNC_NAME(listRemoveRandom),
        MUNIT_SETUP_FUNC_NAME(listRemoveRandom),
        MUNIT_TEARDOWN_FUNC_NAME(listRemoveRandom),
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
        "/listDestroy-nullPtr",
        MUNIT_TEST_FUNC_NAME(listDestroyNullPtr),
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

// CREATING

MUNIT_DECLARE_TEST_FUNC(listCreate) {
    List *list = listCreate();

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    listDestroy(list);

    return MUNIT_OK;
}

// GETTING INFO

MUNIT_DECLARE_TEST_FUNC(listGetElementsCountNullPtr) {
    munit_assert_ulong(listGetElementsCount(NULL), ==, 0UL);

    return MUNIT_OK;
}

// ============

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

MUNIT_DECLARE_TEST_FUNC(listPushFrontNullPtr) {
    munit_assert_long(listPushFront(NULL, NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listPushBackNullPtr) {
    munit_assert_long(listPushBack(NULL, NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listInsertNullPtr) {
    munit_assert_long(listInsertAtIndex(NULL, 0UL, NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

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
        munit_assert_long(listInsertAtIndex(list, i, elem), ==, LIST_RC_OK);
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
    munit_assert_long(listInsertAtIndex(list, 1, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[4];
    munit_assert_long(listInsertAtIndex(list, 3, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[2];
    munit_assert_long(listInsertAtIndex(list, 2, elem), ==, LIST_RC_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[5];
    munit_assert_long(listInsertAtIndex(list, 5, elem), ==, LIST_RC_OK);

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
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
            ret = listInsertAtIndex(list, position, malloc(sizeof(int)));
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

    munit_assert_ulong(listInsertAtIndex(list, 5UL, NULL), ==, LIST_RC_OUT_OF_BOUNDS);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// REMOVING

MUNIT_DECLARE_TEST_FUNC(listPopFrontNullPtr) {
    munit_assert_long(listPopFront(NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listPopBackNullPtr) {
    munit_assert_long(listPopBack(NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveNullPtr) {
    munit_assert_long(listRemove(NULL, 0UL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveAllNullPtr) {
    munit_assert_long(listRemoveAll(NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

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
    int elems[] = {20, 35, 59, -85, 1, 289, 999999};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listPopFront) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listPopFront) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {-85, 1, 289, 999999};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    const size_t numberOfRemoves = 3;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 7UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopFront(list), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listPopBack) {
    List *list = listCreate();
    int elems[] = {20, 35, 59, -85, 1, 289, 999999};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listPopBack) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listPopBack) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {20, 35, 59, -85};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    const size_t numberOfRemoves = 3;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 7UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopBack(list), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemove) {
    List *list = listCreate();
    int elems[] = {20, 35, 59, -85, 1, 289, 999999, -456888, 0, 2, 4, 6, 8, 7, 3, 5};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemove) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemove) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {35, -85, 289, -456888, 2, 4, 6, 8, 3};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    size_t indexesToRemove[] = {15, 0, 3, 1, 5, 3, 8};
    const size_t numberOfRemoves = sizeof(indexesToRemove) / sizeof(size_t);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 16UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listRemove(list, indexesToRemove[i]), ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_RC_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_RC_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemoveRandom) {
    List *list = listCreate();
    const size_t listElemsCount = 25000;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveRandom) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemoveRandom) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 25000UL);

    for(size_t i = 0; i < 25000; ++i) {
        int removeMethod = munit_rand_int_range(0, 4);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)listGetElementsCount(list) - 1);
        ListResultCode ret = LIST_RC_FAIL;

        switch (removeMethod)
        {
        case 0:
        case 1:
        case 2:
            ret = listRemove(list, position);
            break;

        case 3:
            ret = listPopFront(list);
            break;

        case 4:
            ret = listPopBack(list);
            break;
        }

        munit_assert_ulong(ret, ==, LIST_RC_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemoveInvalidPosition) {
    List *list = listCreate();
    const size_t listElemsCount = 3;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveInvalidPosition) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemoveInvalidPosition) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    munit_assert_ulong(listRemove(list, 4UL), ==, LIST_RC_OUT_OF_BOUNDS);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_SETUP_FUNC(listRemoveAllElements) {
    List *list = listCreate();
    const size_t listElemsCount = 75000;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

MUNIT_DECLARE_TEARDOWN_FUNC(listRemoveAllElements) {
    listDestroy((List*)fixture);
}

MUNIT_DECLARE_TEST_FUNC(listRemoveAllElements) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 75000UL);

    munit_assert_ulong(listRemoveAll(list), ==, LIST_RC_OK);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// MIX INSERT-REMOVE

MUNIT_DECLARE_TEST_FUNC(listInsertAndRemoveLargeAmount) {
    return MUNIT_FAIL;
}

// SEARCHING



// DESTROYING

MUNIT_DECLARE_TEST_FUNC(listDestroyNullPtr) {
    munit_assert_long(listDestroy(NULL), ==, LIST_RC_FAIL);

    return MUNIT_OK;
}

// ============

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