#include "utils/datastructure/list.h"

#include <stdlib.h>
#include <stdbool.h>

// ===============
// PRIVATE SECTION
// ===============

#include "utils/datastructure/list_private.h"

// Create a node and return NULL if it failed to allocate memory for the new node
private Node* createNode(void *data, Node *previous, Node *next, List *parent) {
    if(parent == NULL)
        return NULL;

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL) {
        newNode->data = data;
        newNode->prev = previous;
        newNode->next = next;
        newNode->parent = parent;
    }

    return newNode;
}

// Destroy a given node properly
private void destroyNode(Node *node) {
    if(node == NULL)
        return;

    // Remember that once a node holds a reference for the data
    // the ownership of the date is tranferred to the Node
    if(node->data != NULL)
        free(node->data);

    free(node);
}

// Create an iterator and return NULL if failed allocation memory for the iterator
private ListIterator* createIterator(void *data, Node *currentNode) {
    ListIterator *iterator = (ListIterator*)malloc(sizeof(ListIterator));

    if(iterator != NULL) {
        iterator->data = data;
        iterator->currentNode = currentNode;
    }

    return iterator;
}

// Extended insert.
// Insert an element in position relative to a given node
// May insert before or after positionNode
// If positionNode is NULL and list is empty, it's the case of inserting the first node
private ListResultCode listInsertEx(List *list, Node *positionNode, ListRelativePosition relativePos, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    // positionNode may be NULL if list is empty
    // otherwise its an error
    if(positionNode == NULL && list->elementsCount > 0)
        return LIST_FAIL;

    // Given node doesn't belong to given list
    if(positionNode != NULL && positionNode->parent != list)
        return LIST_NODE_OWNERSHIP_ERROR;

    if(positionNode == NULL) {
        // Inserting the first node of the list
        list->firstNode = list->lastNode = createNode(element, NULL, NULL, list);

        if(list->firstNode == NULL) // If failed to allocate memory for the new node
            return LIST_OUT_OF_MEMORY;

        ++(list->elementsCount);
    } else if(relativePos == LIST_REPLACE) {
        // Replacing current node data
        if(positionNode->data != NULL)
            free(positionNode->data);

        positionNode->data = element;
    } else if(relativePos == LIST_BEFORE) {
        Node *newNode = createNode(element, positionNode->prev, positionNode, list);

        if(newNode == NULL)
            return LIST_OUT_OF_MEMORY;

        if(positionNode->prev != NULL) {
            positionNode->prev->next = newNode;
        } else {
            list->firstNode = newNode;
        }

        positionNode->prev = newNode;

        ++(list->elementsCount);
    } else if(relativePos == LIST_AFTER) {
        Node *newNode = createNode(element, positionNode, positionNode->next, list);

        if(newNode == NULL)
            return LIST_OUT_OF_MEMORY;

        if(positionNode->next != NULL) {
            positionNode->next->prev = newNode;
        } else {
            list->lastNode = newNode;
        }

        positionNode->next = newNode;

        ++(list->elementsCount);
    } else {
        return LIST_FAIL;
    }

    return LIST_OK;
}

// Extended remove.
// Removes the given node from the list
private ListResultCode listRemoveEx(List *list, Node *positionNode) {
    if(list == NULL)
        return LIST_FAIL;

    // Its quite important that this check comes earlier than check for
    // positionNode being not null pointer
    if(list->elementsCount == 0UL)
        return LIST_REMOVE_ALREADY_EMPTY;

    /* This guard must come after the guard that checks the amount of elements
     * in the list. If it comes before, it will not be possible to retrn
     * LIST_REMOVE_ALREADY_EMPTY for the cases a NULL node was passed to
     * positionNode parameter. Some functions that calls listRemoveEx needs
     * the behavior of failing by LIST_REMOVE_ALREADY_EMPTY even for 
     * positionNode receiving NULL (ex.: listPopFront and listPopBack) */
    if(positionNode == NULL)
        return LIST_FAIL;

    // Given node doesn't belong to given list
    if(positionNode->parent != list)
        return LIST_NODE_OWNERSHIP_ERROR;

    if(positionNode->prev != NULL) {
        positionNode->prev->next = positionNode->next;
    } else {
        list->firstNode = positionNode->next;
    }

    if(positionNode->next != NULL) {
        positionNode->next->prev = positionNode->prev;
    } else {
        list->lastNode = positionNode->prev;
    }

    destroyNode(positionNode);
    --(list->elementsCount);

    return LIST_OK;
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

    if(ret < LIST_OK)
        return LIST_FAIL;

    free(list);

    return LIST_OK;
}

unsigned long listGetElementsCount(List *list) {
    if(list == NULL)
        return 0UL;

    return list->elementsCount;
}

ListResultCode listGetBegin(List *list, ListIterator **iterator) {
    if(list == NULL || iterator == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_FIND_NOT_FOUND;

    *iterator = createIterator(list->firstNode->data, list->firstNode);

    if(*iterator == NULL)
        return LIST_OUT_OF_MEMORY;

    return LIST_OK;
}

ListResultCode listGetEnd(List *list, ListIterator **iterator) {
    if(list == NULL || iterator == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_FIND_NOT_FOUND;

    *iterator = createIterator(list->lastNode->data, list->lastNode);

    if(*iterator == NULL)
        return LIST_OUT_OF_MEMORY;

    return LIST_OK;
}

ListResultCode listFindElement(List *list, unsigned long position, ListIterator **iterator) {
    if(list == NULL || iterator == NULL)
        return LIST_FAIL;

    if(position >= list->elementsCount)
        return LIST_OUT_OF_BOUNDS;

    // Whether the search must happen forward or backward for performance reasons.
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

    *iterator = createIterator(currentNode->data, currentNode);

    if(*iterator == NULL)
        return LIST_OUT_OF_MEMORY;

    return LIST_OK;
}

ListResultCode listMoveNext(ListIterator *iterator) {
    if(iterator == NULL)
        return LIST_FAIL;

    if(iterator->currentNode == NULL)
        return LIST_FAIL;

    if(iterator->currentNode->next == NULL)
        return LIST_ITERATOR_END_REACHED;

    iterator->currentNode = iterator->currentNode->next;
    iterator->data = iterator->currentNode->data;

    return LIST_OK;
}

ListResultCode listMoveBack(ListIterator *iterator) {
    if(iterator == NULL)
        return LIST_FAIL;

    if(iterator->currentNode == NULL)
        return LIST_FAIL;

    if(iterator->currentNode->prev == NULL)
        return LIST_ITERATOR_BEGIN_REACHED;

    iterator->currentNode = iterator->currentNode->prev;
    iterator->data = iterator->currentNode->data;

    return LIST_OK;
}

ListResultCode listInsert(ListIterator *iterator, ListRelativePosition relativePos, void *element) {
    if(iterator == NULL || iterator->currentNode == NULL)
        return LIST_FAIL;

    return listInsertEx(iterator->currentNode->parent, iterator->currentNode, relativePos, element);
}

ListResultCode listInsertAtIndex(List *list, unsigned long position, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    if(position > list->elementsCount)
        return LIST_OUT_OF_BOUNDS;

    if(position == 0UL && list->elementsCount == 0UL) { // Empty list case
        return listInsertEx(list, NULL, LIST_BEFORE, element);
    } else if(position == list->elementsCount) { // Push back case
        return listInsertEx(list, list->lastNode, LIST_AFTER, element);
    } else { // Default case
        ListIterator *iterator;
        ListResultCode ret = LIST_FAIL;

        ret = listFindElement(list, position, &iterator);
        if(ret == LIST_OK)
            ret = listInsertEx(list, iterator->currentNode, LIST_BEFORE, element);

        if(iterator != NULL)
            free(iterator);

        return ret;
    }
}

ListResultCode listPushFront(List *list, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    return listInsertEx(list, list->firstNode, LIST_BEFORE, element);
}

ListResultCode listPushBack(List *list, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    return listInsertEx(list, list->lastNode, LIST_AFTER, element);
}

ListResultCode listRemove(ListIterator *iterator) {
    if(iterator == NULL || iterator->currentNode == NULL)
        return LIST_FAIL;

    return listRemoveEx(iterator->currentNode->parent, iterator->currentNode);
}

ListResultCode listRemoveFromIndex(List *list, unsigned long position) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_REMOVE_ALREADY_EMPTY;

    ListIterator *iterator;
    ListResultCode ret = LIST_FAIL;

    ret = listFindElement(list, position, &iterator);
    if(ret == LIST_OK)
        ret = listRemoveEx(list, iterator->currentNode);

    if(iterator != NULL)
        free(iterator);

    return ret;
}

ListResultCode listPopFront(List *list) {
    if(list == NULL)
        return LIST_FAIL;

    return listRemoveEx(list, list->firstNode);
}

ListResultCode listPopBack(List *list) {
    if(list == NULL)
        return LIST_FAIL;

    return listRemoveEx(list, list->lastNode);
}

// For performance reasons this function doesn't use listRemoveEx
ListResultCode listRemoveAll(List *list) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->firstNode == NULL)
        return LIST_REMOVE_ALREADY_EMPTY;

    Node *currentNode = list->firstNode;
    while(currentNode != NULL) {
        Node *nextNode = currentNode->next;

        destroyNode(currentNode);

        currentNode = nextNode;
    }

    list->firstNode = NULL;
    list->lastNode = NULL;
    list->elementsCount = 0UL;

    return LIST_OK;
}