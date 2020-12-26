#include "utils/datastructure/test_list_setups.h"

#include <stdlib.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"

// =======================
// Empty list
DECLARE_SETUP_FUNC(listEmpty) {
    return listCreate();
}

DECLARE_TEARDOWN_FUNC(listEmpty) {
    listDestroy(fixture);
}

DECLARE_SETUP_FUNC(listEmptyStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listEmpty);
}

DECLARE_TEARDOWN_FUNC(listEmptyStubTd) {
    (void)fixture;
}

// =======================
// Single element list
DECLARE_SETUP_FUNC(listSingleElement) {
    const int value = 5;

    List *list = listCreate();
    int *setupValue = malloc(sizeof(int));

    *setupValue = value;

    FIXTURE_CREATE(fixture, 2);
    FIXTURE_INDEX(fixture, 0) = list;
    FIXTURE_INDEX(fixture, 1) = setupValue;

    int *singleElement = malloc(sizeof(int));
    *singleElement = value;

    listPushBack(list, singleElement);

    FIXTURE_RETURN(fixture);
}

DECLARE_TEARDOWN_FUNC(listSingleElement) {
    listDestroy(FIXTURE_INDEX(fixture, 0));
    free(FIXTURE_INDEX(fixture, 1));

    free(fixture);
}

DECLARE_SETUP_FUNC(listSingleElementStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listSingleElement);
}

DECLARE_TEARDOWN_FUNC(listSingleElementStubTd) {
    free(FIXTURE_INDEX(fixture, 1));

    free(fixture);
}

// =======================
// Few elements list
DECLARE_SETUP_FUNC(listFewElements) {
    const int values[] = {0, 10, 3, 99, -250000, 999999, -7, 888, 50, 42};

    List *list = listCreate();
    int *setupArray = malloc(sizeof(values));
    size_t *setupArraySize = malloc(sizeof(size_t));

    memcpy(setupArray, values, sizeof(values));
    *setupArraySize = sizeof(values) / sizeof(int);

    FIXTURE_CREATE(fixture, 3);
    FIXTURE_INDEX(fixture, 0) = list;
    FIXTURE_INDEX(fixture, 1) = setupArray;
    FIXTURE_INDEX(fixture, 2) = setupArraySize;

    for(size_t i = 0; i < *setupArraySize; ++i) {
        int *element = malloc(sizeof(int));
        *element = values[i];
        listPushBack(list, element);
    }

    FIXTURE_RETURN(fixture);
}

DECLARE_TEARDOWN_FUNC(listFewElements) {
    listDestroy(FIXTURE_INDEX(fixture, 0));
    free(FIXTURE_INDEX(fixture, 1));
    free(FIXTURE_INDEX(fixture, 2));

    free(fixture);
}

DECLARE_SETUP_FUNC(listFewElementsStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listFewElements);
}

DECLARE_TEARDOWN_FUNC(listFewElementsStubTd) {
    free(FIXTURE_INDEX(fixture, 1));
    free(FIXTURE_INDEX(fixture, 2));

    free(fixture);
}

// =======================
// Large amount of elements lsit
DECLARE_SETUP_FUNC(listLargeAmountElementsRandomValue) {
    const size_t arraySize = 10000;

    List *list = listCreate();
    int *setupArray = malloc(sizeof(int) * arraySize);
    size_t *setupArraySize = malloc(sizeof(size_t));

    *setupArraySize = arraySize;

    FIXTURE_CREATE(fixture, 3);
    FIXTURE_INDEX(fixture, 0) = list;
    FIXTURE_INDEX(fixture, 1) = setupArray;
    FIXTURE_INDEX(fixture, 2) = setupArraySize;

    for(size_t i = 0; i < arraySize; ++i) {
        int *element = malloc(sizeof(int));
        setupArray[i] = munit_rand_int_range(-999999, 999999);
        *element = setupArray[i];
        listPushBack(list, element);
    }

    FIXTURE_RETURN(fixture);
}

DECLARE_TEARDOWN_FUNC(listLargeAmountElementsRandomValue) {
    listDestroy(FIXTURE_INDEX(fixture, 0));
    free(FIXTURE_INDEX(fixture, 1));
    free(FIXTURE_INDEX(fixture, 2));

    free(fixture);
}

DECLARE_SETUP_FUNC(listLargeAmountElementsRandomValueStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listLargeAmountElementsRandomValue);
}

DECLARE_TEARDOWN_FUNC(listLargeAmountElementsRandomValueStubTd) {
    free(FIXTURE_INDEX(fixture, 1));
    free(FIXTURE_INDEX(fixture, 2));

    free(fixture);
}

// =======================
// Node not owned by list
DECLARE_SETUP_FUNC(listFewElementsAndNodeNotOwnedByList) {
    const int values[] = {5, 8, 11};

    List *list = listCreate();
    int *setupArray = malloc(sizeof(values));
    size_t *setupArraySize = malloc(sizeof(size_t));
    Node *notOwnedByListNode = createNode(NULL, NULL, NULL, (List*)(-1L));

    memcpy(setupArray, values, sizeof(values));
    *setupArraySize = sizeof(values) / sizeof(int);

    FIXTURE_CREATE(fixture, 4);
    FIXTURE_INDEX(fixture, 0) = list;
    FIXTURE_INDEX(fixture, 1) = setupArray;
    FIXTURE_INDEX(fixture, 2) = setupArraySize;
    FIXTURE_INDEX(fixture, 3) = notOwnedByListNode;

    for(size_t i = 0; i < *setupArraySize; ++i) {
        int *element = malloc(sizeof(int));
        *element = values[i];
        listPushBack(list, element);
    }

    FIXTURE_RETURN(fixture);
}

DECLARE_TEARDOWN_FUNC(listFewElementsAndNodeNotOwnedByList) {
    listDestroy(FIXTURE_INDEX(fixture, 0));
    free(FIXTURE_INDEX(fixture, 1));
    free(FIXTURE_INDEX(fixture, 2));
    destroyNode(FIXTURE_INDEX(fixture, 3));

    free(fixture);
}
