#include "utils/datastructure/list.h"

#include <stdlib.h>

typedef struct _Node {
    void *data;
    struct _Node *prev;
    struct _Node *next;
} Node;

struct _List {
    Node *firstNode;
    Node *lastNode;
    unsigned long elementsCount;
};

List* listCreate(void) {
    List *newList = (List*)malloc(sizeof(List));

    if(newList == NULL)
        return NULL;

    newList->firstNode = NULL;
    newList->lastNode = NULL;
    newList->elementsCount = 0UL;

    return newList;
}

ListResultCode listDestroy(List *list) {
    ListResultCode ret = listRemoveAll(list);

    if(ret < LIST_RC_OK)
        return LIST_RC_FAIL;

    free(list);

    return LIST_RC_OK;
}

unsigned long listGetElementsCount(List *list) {
    if(list == NULL)
        return 0;

    return list->elementsCount;
}

ListResultCode listRemoveAll(List *list) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->firstNode == NULL)
        return LIST_RC_REMOVE_ALREADY_EMPTY;

    Node *currentNode = list->firstNode;
    while(currentNode != NULL) {
        Node *nextNode = currentNode->next;

        free(currentNode->data);
        free(currentNode);

        currentNode = nextNode;
    }

    list->firstNode = NULL;
    list->lastNode = NULL;
    list->elementsCount = 0UL;

    return LIST_RC_OK;
}