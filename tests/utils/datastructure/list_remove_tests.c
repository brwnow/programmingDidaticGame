#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listPopFrontNullPtr) {
    munit_assert_long(listPopFront(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listPopBackNullPtr) {
    munit_assert_long(listPopBack(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listRemoveNullPtr) {
    munit_assert_long(listRemoveFromIndex(NULL, 0UL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listRemoveAllNullPtr) {
    munit_assert_long(listRemoveAll(NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyPopFront) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyPopFront) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyPopFront, listEmptyPopFront) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listPopFront(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyPopBack) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyPopBack) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyPopBack, listEmptyPopBack) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listPopBack(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyRemove) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyRemove) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyRemove, listEmptyRemove) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listRemoveFromIndex(list, 0UL), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyRemoveAllElements) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyRemoveAllElements) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyRemoveAllElements, listEmptyRemoveAllElements) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    munit_assert_long(listRemoveAll(list), ==, LIST_REMOVE_ALREADY_EMPTY);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listPopFront) {
    List *list = listCreate();
    int elems[] = {20, 35, 59, -85, 1, 289, 999999};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listPopFront) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listPopFront, listPopFront) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {-85, 1, 289, 999999};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    const size_t numberOfRemoves = 3;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 7UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopFront(list), ==, LIST_OK);
    }

    munit_assert_ulong(list->elementsCount, ==, elemsCount);

    Node *current = list->firstNode;

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(current);
        munit_assert_not_null(current->data);
        int val = *((int*)(current->data));

        munit_assert_int(val, ==, remainingElems[i]);

        current = current ->next;
    }

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listPopBack) {
    List *list = listCreate();
    int elems[] = {20, 35, 59, -85, 1, 289, 999999};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listPopBack) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listPopBack, listPopBack) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {20, 35, 59, -85};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    const size_t numberOfRemoves = 3;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 7UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listPopBack(list), ==, LIST_OK);
    }

    munit_assert_ulong(list->elementsCount, ==, elemsCount);

    Node *current = list->firstNode;

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(current);
        munit_assert_not_null(current->data);
        int val = *((int*)(current->data));

        munit_assert_int(val, ==, remainingElems[i]);

        current = current ->next;
    }

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listRemove) {
    List *list = listCreate();
    int elems[] = {20, 35, 59, -85, 1, 289, 999999, -456888, 0, 2, 4, 6, 8, 7, 3, 5};

    for(size_t i = 0; i < sizeof(elems) / sizeof(int); ++i) {
        int *elem = malloc(sizeof(int));
        *elem = elems[i];
        listPushBack(list, elem);
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listRemove) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listRemove, listRemove) {
    List *list = (List*)user_data_or_fixture;
    int remainingElems[] = {35, -85, 289, -456888, 2, 4, 6, 8, 3};
    const size_t elemsCount = sizeof(remainingElems) / sizeof(int);
    size_t indexesToRemove[] = {15, 0, 3, 1, 5, 3, 8};
    const size_t numberOfRemoves = sizeof(indexesToRemove) / sizeof(size_t);

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 16UL);

    for(size_t i = 0; i < numberOfRemoves; ++i) {
        munit_assert_long(listRemoveFromIndex(list, indexesToRemove[i]), ==, LIST_OK);
    }

    munit_assert_ulong(list->elementsCount, ==, elemsCount);

    Node *current = list->firstNode;

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(current);
        munit_assert_not_null(current->data);
        int val = *((int*)(current->data));

        munit_assert_int(val, ==, remainingElems[i]);

        current = current ->next;
    }

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listRemoveRandom) {
    List *list = listCreate();
    const size_t listElemsCount = 25000;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listRemoveRandom) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listRemoveRandom, listRemoveRandom) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 25000UL);

    for(size_t i = 0; i < 25000; ++i) {
        int removeMethod = munit_rand_int_range(0, 4);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)(list->elementsCount) - 1);
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

    munit_assert_ulong(list->elementsCount, ==, 0UL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listRemoveInvalidPosition) {
    List *list = listCreate();
    const size_t listElemsCount = 3;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listRemoveInvalidPosition) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listRemoveInvalidPosition, listRemoveInvalidPosition) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 3UL);

    munit_assert_long(listRemoveFromIndex(list, 4UL), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_ulong(list->elementsCount, ==, 3UL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listRemoveAllElements) {
    List *list = listCreate();
    const size_t listElemsCount = 75000;

    for(size_t i = 0; i < listElemsCount; ++i) {
        listPushBack(list, malloc(sizeof(int)));
    }

    return list;
}

DECLARE_TEARDOWN_FUNC(listRemoveAllElements) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listRemoveAllElements, listRemoveAllElements) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 75000UL);

    munit_assert_long(listRemoveAll(list), ==, LIST_OK);
    munit_assert_ulong(list->elementsCount, ==, 0UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-nullPtr", listPopFrontNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-nullPtr", listPopBackNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-nullPtr", listRemoveNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-nullPtr", listRemoveAllNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-emptyList", listEmptyPopFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-emptyList", listEmptyPopBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-emptyList", listEmptyRemove),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-emptyList", listEmptyRemoveAllElements),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopFront-notEmptyList", listPopFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPopBack-notEmptyList", listPopBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-notEmptyList", listRemove),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-random", listRemoveRandom),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemove-invalidPosition", listRemoveInvalidPosition),
    GET_TEST_FUNC_ARRAY_ENTRY("/listRemoveAll-notEmptyList", listRemoveAllElements),

    TEST_FUNC_ARRAY_END
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