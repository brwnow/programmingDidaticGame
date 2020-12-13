#include "utils/datastructure/list.h"

#include <stdlib.h>
#include <stdbool.h>

// ===============
// PRIVATE SECTION
// ===============

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

static Node* createNode(void *data, Node *previous, Node *next) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->prev = previous;
    newNode->next = next;

    return newNode;
}

static ListResultCode insertFirstNode(List *list, void *element) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount > 0UL)
        return LIST_RC_FAIL; // List not empty. First node was already inserted

    Node *firstNode = createNode(element, NULL, NULL);

    if(firstNode == NULL)
        return LIST_RC_OUT_OF_MEMORY; // Failed to allocated memory for the first node

    list->firstNode = list->lastNode = firstNode;
    list->elementsCount = 1UL;

    return LIST_RC_OK;
}

// Insert a node in place of a given positionNode.
static inline ListResultCode insertAtNode(List *list, Node *positionNode, void *element) {
    if(list == NULL || positionNode == NULL)
        return LIST_RC_FAIL;

    // If inserting in first position of the list
    if(positionNode->prev == NULL)
        return listPushFront(list, element);

    Node *newNode = createNode(element, NULL, NULL);
    if(newNode == NULL)
        return LIST_RC_OUT_OF_MEMORY;

    // Attaching new node to the d-linked list
    newNode->prev = positionNode->prev;
    newNode->next = positionNode;
    positionNode->prev->next = newNode;
    positionNode->prev = newNode;

    return LIST_RC_OK;
}

// ==============
// PUBLIC SECTION
// ==============

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
        return 0UL;

    return list->elementsCount;
}

ListResultCode listGetBegin(List *list, ListIterator **iterator) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_RC_FIND_NOT_FOUND;

    *iterator = (ListIterator*)malloc(sizeof(ListIterator));

    if(*iterator == NULL)
        return LIST_RC_OUT_OF_MEMORY;

    (*iterator)->data = list->firstNode->data;
    (*iterator)->currentNode = list->firstNode;

    return LIST_RC_OK;
}

ListResultCode listGetEnd(List *list, ListIterator **iterator) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_RC_FIND_NOT_FOUND;

    *iterator = (ListIterator*)malloc(sizeof(ListIterator));

    if(*iterator == NULL)
        return LIST_RC_OUT_OF_MEMORY;

    (*iterator)->data = list->lastNode->data;
    (*iterator)->currentNode = list->lastNode;

    return LIST_RC_OK;
}

ListResultCode listFindElement(List *list, unsigned long position, ListIterator **iterator) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(position >= list->elementsCount)
        return LIST_RC_OUT_OF_BOUNDS;

    // Whether the search must happend forward or backward
    bool moveForward = position <= list->elementsCount / 2UL;

    Node *currentNode = moveForward ? list->firstNode : list->lastNode;
    unsigned long i = moveForward ? 0UL : list->elementsCount - 1UL;
    while(i != position) {
        if(moveForward) {
            currentNode = currentNode->next;
            ++i;
        } else {
            currentNode = currentNode->prev;
            --i;
        }
    }

    *iterator = (ListIterator*)malloc(sizeof(ListIterator));

    if(*iterator == NULL)
        return LIST_RC_OUT_OF_MEMORY;

    (*iterator)->data = currentNode->data;
    (*iterator)->currentNode = currentNode;
    return LIST_RC_OK;
}

ListResultCode listMoveNext(ListIterator *iterator) {
    if(iterator == NULL)
        return LIST_RC_FAIL;

    Node *currentNode = iterator->currentNode;

    if(currentNode == NULL)
        return LIST_RC_FAIL;

    if(currentNode->next == NULL)
        return LIST_RC_ITERATOR_END_REACHED;

    currentNode = currentNode->next;
    iterator->data = currentNode->data;
    iterator->currentNode = currentNode;

    return LIST_RC_OK;
}

ListResultCode listMoveBack(ListIterator *iterator) {
    if(iterator == NULL)
        return LIST_RC_FAIL;

    Node *currentNode = iterator->currentNode;

    if(currentNode == NULL)
        return LIST_RC_FAIL;

    if(currentNode->prev == NULL)
        return LIST_RC_ITERATOR_BEGIN_REACHED;

    currentNode = currentNode->prev;
    iterator->data = currentNode->data;
    iterator->currentNode = currentNode;

    return LIST_RC_OK;
}

ListResultCode listInsert(List *list, ListIterator *iterator, void *element) {
    if(iterator == NULL)
        return LIST_RC_FAIL;

    return insertAtNode(list, iterator->currentNode, element);
}

ListResultCode listInsertAtIndex(List *list, unsigned long position, void *element) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(position > list->elementsCount)
        return LIST_RC_OUT_OF_BOUNDS;

    if(list->elementsCount == 0UL) { // List is empty, inserting first element
        return insertFirstNode(list, element);
    } else if(position == 0UL) { // Pushing the element in front
        return listPushFront(list, element);
    } else if(position == list->elementsCount) { // Pushing the element in back
        return listPushBack(list, element);
    } else { // Defult insertion case
        ListIterator *iterator;
        ListResultCode ret = LIST_RC_FAIL;

        ret = listFindElement(list, position, &iterator);
        if(ret != LIST_RC_FAIL)
            ret = listInsert(list, iterator, element);

        if(iterator != NULL)
            free(iterator);

        return ret;
    }
}

ListResultCode listPushFront(List *list, void *element) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL) {
        return insertFirstNode(list, element);
    } else {
        Node *newNode = createNode(element, NULL, list->firstNode);

        if(newNode == NULL)
            return LIST_RC_FAIL;

        list->firstNode->prev = newNode;
        list->firstNode = newNode;
        ++(list->elementsCount);

        return LIST_RC_OK;
    }
}

ListResultCode listPushBack(List *list, void *element) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL) {
        return insertFirstNode(list, element);
    } else {
        Node *newNode = createNode(element, list->lastNode, NULL);

        if(newNode == NULL)
            return LIST_RC_FAIL;

        list->lastNode->next = newNode;
        list->lastNode = newNode;
        ++(list->elementsCount);

        return LIST_RC_OK;
    }
}

ListResultCode listRemove(List *list, unsigned long position) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_RC_REMOVE_ALREADY_EMPTY;

    if(position >= list->elementsCount)
        return LIST_RC_OUT_OF_BOUNDS;

    if(position == 0UL) { // Popping the element from front
        return listPopFront(list);
    } else if(position == list->elementsCount - 1) { // Popping the element from back
        return listPopBack(list);
    } else { // Defult insertion case
        ListIterator *iterator;
        ListResultCode ret = LIST_RC_FAIL;

        ret = listFindElement(list, position, &iterator);
        if(ret != LIST_RC_OK) {
            // Note that it's not the case of inserting out of bounds
            // because it was previsouly verified if position is greater than
            // list number of elements
            ret = LIST_RC_FAIL;
        }

        if(ret == LIST_RC_OK) { // If everything went ok, effectively remove the node
            Node *foundNode = iterator->currentNode;
            foundNode->prev->next = foundNode->next;
            foundNode->next->prev = foundNode->prev;

            free(foundNode->data);
            free(foundNode);
            --(list->elementsCount);
        }

        if(iterator != NULL)
            free(iterator);

        return ret;
    }
}

ListResultCode listPopFront(List *list) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_RC_REMOVE_ALREADY_EMPTY;

    Node *nodeToPop = list->firstNode;

    if(list->elementsCount == 1UL) { // Last node being removed
        list->firstNode = list->lastNode = NULL;
    } else {
        list->firstNode = list->firstNode->next;
        list->firstNode->prev = NULL;
    }

    free(nodeToPop->data);
    free(nodeToPop);
    --(list->elementsCount);

    return LIST_RC_OK;
}

ListResultCode listPopBack(List *list) {
    if(list == NULL)
        return LIST_RC_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_RC_REMOVE_ALREADY_EMPTY;

    Node *nodeToPop = list->lastNode;

    if(list->elementsCount == 1UL) { // Last node being removed
        list->firstNode = list->lastNode = NULL;
    } else {
        list->lastNode = list->lastNode->prev;
        list->lastNode->next = NULL;
    }

    free(nodeToPop->data);
    free(nodeToPop);
    --(list->elementsCount);

    return LIST_RC_OK;
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