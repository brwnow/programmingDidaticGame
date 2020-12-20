#include "utils/datastructure/test_list_setups.h"

#include <stdlib.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"

// =======================
// Empty list
DECLARE_SETUP_FUNC(listEmpty) {
    List *list = malloc(sizeof(List));

    list->elementsCount = 0;
    list->firstNode = list->lastNode = NULL;

    return list;
}

DECLARE_TEARDOWN_FUNC(listEmpty) {
    listDestroy(fixture);
}

// =======================
// Empty list with stub teardown
DECLARE_SETUP_FUNC(listEmptyStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listEmpty);
}

DECLARE_TEARDOWN_FUNC(listEmptyStubTd) {
    (void)fixture;
}

// =======================
// Single element list
DECLARE_SETUP_FUNC(listSingleElement) {
    List *list = malloc(sizeof(List));
    Node *singleNode = malloc(sizeof(Node));
    int *singleElement = malloc(sizeof(int));

    *singleElement = 5;

    singleNode->data = singleElement;
    singleNode->next = NULL;
    singleNode->prev = NULL;
    singleNode->parent = list;

    list->elementsCount = 1UL;
    list->firstNode = list->lastNode = singleNode;

    return list;
}

DECLARE_TEARDOWN_FUNC(listSingleElement) {
    listDestroy(fixture);
}

// =======================
// Single element list with stub teardown (nothing is really cleaned up)
DECLARE_SETUP_FUNC(listSingleElementStubTd) {
    RETURN_EXISTING_SETUP_FUNC(listSingleElement);
}

DECLARE_TEARDOWN_FUNC(listSingleElementStubTd) {
    (void)fixture;
}
