#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/test_list_setups.h"

DEFINE_STANDALONE_TEST_FUNC(listPushFrontNullPtr) {
    munit_assert_long(listPushFront(NULL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listPushBackNullPtr) {
    munit_assert_long(listPushBack(NULL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listInsertNullPtr) {
    munit_assert_long(listInsert(NULL, LIST_BEFORE, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listInsertIndexNullPtr) {
    munit_assert_long(listInsertAtIndex(NULL, 0UL, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyPushFront) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyPushFront) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyPushFront, listEmptyPushFront) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {9, 4, 500, 27, 3, -89, 54685, 111, 0, -4585};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listPushFront(list, elem), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);

    for(int i = elemsCount - 1; i >= 0; --i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[(size_t)i]);

        if(i > 0)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyPushBack) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyPushBack) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyPushBack, listEmptyPushBack) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {-856, 41, 0, 23, 158, -89356, 54685, 321, 444, -4585, 84, -2};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listPushBack(list, elem), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);

    for(size_t i = 0; i < elemsCount; --i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[(size_t)i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyInsert) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyInsert) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyInsert, listEmptyInsert) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    munit_assert_long(listInsert(NULL, LIST_BEFORE, NULL), ==, LIST_FAIL);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listEmptyInsertIndex) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmptyInsertIndex) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listEmptyInsertIndex, listEmptyInsertIndex) {
    List *list = (List*)user_data_or_fixture;
    int elems[] = {0, 50, 2, 999, 73};
    size_t elemsCount = sizeof(elems) / sizeof(int);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 0UL);

    for(size_t i = 0; i < elemsCount; ++i) {
        int *elem = (int*)malloc(sizeof(int));
        *elem = elems[i];
        munit_assert_long(listInsertAtIndex(list, i, elem), ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it);
        int val = *((int*)it->data);

        munit_assert_int(val, ==, elems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listNotEmptyInsertIndexVariablePositions) {
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

DECLARE_TEARDOWN_FUNC(listNotEmptyInsertIndexVariablePositions) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listNotEmptyInsertIndexVariablePositions, listNotEmptyInsertIndexVariablePositions) {
    List *list = (List*)user_data_or_fixture;
    char elems[] = {'a', 'b', 'c', 'z', 'i', 'p', 'k'};
    size_t elemsCount = sizeof(elems) / sizeof(char);

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    char *elem = (char*)malloc(sizeof(char));
    *elem = elems[1];
    munit_assert_long(listInsertAtIndex(list, 1, elem), ==, LIST_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[4];
    munit_assert_long(listInsertAtIndex(list, 3, elem), ==, LIST_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[2];
    munit_assert_long(listInsertAtIndex(list, 2, elem), ==, LIST_OK);
    elem = (char*)malloc(sizeof(char));
    *elem = elems[5];
    munit_assert_long(listInsertAtIndex(list, 5, elem), ==, LIST_OK);

    munit_assert_ulong(listGetElementsCount(list), ==, elemsCount);

    ListIterator *it;
    munit_assert_long(listGetBegin(list, &it), ==, LIST_OK);
    munit_assert_not_null(it);

    for(size_t i = 0; i < elemsCount; ++i) {
        munit_assert_not_null(it->data);
        char val = *((char*)it->data);

        munit_assert_int(val, ==, elems[i]);

        if(i < elemsCount - 1)
            munit_assert_long(listMoveNext(it), ==, LIST_OK);
    }

    free(it);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listInsertIndexLargeAmount) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(int)));

    return list;
}

DECLARE_TEARDOWN_FUNC(listInsertIndexLargeAmount) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listInsertIndexLargeAmount, listInsertIndexLargeAmount) {
    List *list = (List*)user_data_or_fixture;
    const size_t amountToBeInserted = 50000;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 1UL);

    for(size_t i = 0; i < amountToBeInserted; ++i) {
        int insertMethod = munit_rand_int_range(0, 2);
        unsigned long position = (unsigned long)munit_rand_int_range(0, (int)listGetElementsCount(list));
        ListResultCode ret = LIST_FAIL;

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

        munit_assert_long(ret, ==, LIST_OK);
    }

    munit_assert_ulong(listGetElementsCount(list), ==, amountToBeInserted + 1);

    return MUNIT_OK;
}

// ============

DECLARE_SETUP_FUNC(listInsertIndexInInvalidPosition) {
    List *list = listCreate();

    listPushBack(list, malloc(sizeof(double)));
    listPushBack(list, malloc(sizeof(double)));
    listPushBack(list, malloc(sizeof(double)));

    return list;
}

DECLARE_TEARDOWN_FUNC(listInsertIndexInInvalidPosition) {
    listDestroy((List*)fixture);
}

DEFINE_FULL_TEST_FUNC(listInsertIndexInInvalidPosition, listInsertIndexInInvalidPosition) {
    List *list = (List*)user_data_or_fixture;

    munit_assert_not_null(list);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    munit_assert_long(listInsertAtIndex(list, 5UL, NULL), ==, LIST_OUT_OF_BOUNDS);
    munit_assert_ulong(listGetElementsCount(list), ==, 3UL);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushFront-nullPtr", listPushFrontNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushBack-nullPtr", listPushBackNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsert-nullPtr", listInsertNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-nullPtr", listInsertIndexNullPtr),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushFront-emptyList", listEmptyPushFront),
    GET_TEST_FUNC_ARRAY_ENTRY("/listPushBack-emptyList", listEmptyPushBack),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsert-emptyList", listEmptyInsert),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-emptyList", listEmptyInsertIndex),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-notEmptyList", listNotEmptyInsertIndexVariablePositions),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-largeAmount", listInsertIndexLargeAmount),
    GET_TEST_FUNC_ARRAY_ENTRY("/listInsertAtIndex-invalidPosition", listInsertIndexInInvalidPosition),

    // Ending of tests array
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitSuite listTestsSuite = {
    "/inserting",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listInsertTestsGetSuite(void) {
    return listTestsSuite;
}