#include <munit.h>
#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_tests.h"

MUNIT_DECLARE_TEST_FUNC(listPopFrontNullPtr) {
    munit_assert_long(listPopFront(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listPopBackNullPtr) {
    munit_assert_long(listPopBack(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveNullPtr) {
    munit_assert_long(listRemoveFromIndex(NULL, 0UL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

MUNIT_DECLARE_TEST_FUNC(listRemoveAllNullPtr) {
    munit_assert_long(listRemoveAll(NULL), ==, LIST_FAIL);

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

    munit_assert_long(listPopFront(list), ==, LIST_REMOVE_ALREADY_EMPTY);

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

    munit_assert_long(listPopBack(list), ==, LIST_REMOVE_ALREADY_EMPTY);

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

    munit_assert_long(listRemoveFromIndex(list, 0UL), ==, LIST_REMOVE_ALREADY_EMPTY);

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

    munit_assert_long(listRemoveAll(list), ==, LIST_REMOVE_ALREADY_EMPTY);

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
        munit_assert_long(listPopFront(list), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
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
        munit_assert_long(listPopBack(list), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
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
        munit_assert_long(listRemoveFromIndex(list, indexesToRemove[i]), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, remainingElems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
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
        ListResultCode ret = LIST_FAIL;

        switch (removeMethod)
        {
        case 0:
        case 1:
        case 2:
            ret = listRemoveFromIndex(list, position);
            break;

        case 3:
            ret = listPopFront(list);
            break;

        case 4:
            ret = listPopBack(list);
            break;
        }

        munit_assert_long(ret, ==, LIST_OK);
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

    munit_assert_long(listRemoveFromIndex(list, 4UL), ==, LIST_OUT_OF_BOUNDS);
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

    munit_assert_long(listRemoveAll(list), ==, LIST_OK);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
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

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitSuite listTestsSuite = {
    "/removing",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listRemoveTestsGetSuite(void) {
    return listTestsSuite;
}