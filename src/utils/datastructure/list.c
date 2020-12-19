#include "utils/datastructure/list.h"

#include <stdlib.h>
#include <stdbool.h>

// ===============
// PRIVATE SECTION
// ===============

#include "utils/datastructure/list_private.h"

// Create a node and return NULL if it failed to allocate memory for the new node
private Node* createNode(void *data, Node *previous, Node *next) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL) {
        newNode->data = data;
        newNode->prev = previous;
        newNode->next = next;
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

// This function insert the first node ever of the list (it's not pushfront)
private ListResultCode insertFirstNode(List *list, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount > 0UL)
        return LIST_FAIL; // List not empty. First node was already inserted

    Node *firstNode = createNode(element, NULL, NULL);

    if(firstNode == NULL)
        return LIST_OUT_OF_MEMORY; // Failed to allocated memory for the first node

    list->firstNode = list->lastNode = firstNode;
    list->elementsCount = 1UL;

    return LIST_OK;
}

// Insert a node in place of a given positionNode.
private ListResultCode insertAtNode(List *list, Node *positionNode, void *element) {
    ListResultCode ret = LIST_OK;

    if(list == NULL || positionNode == NULL)
        ret = LIST_FAIL;

    if(ret == LIST_OK) {
        if(positionNode->prev == NULL) { // If inserting in first position of the list
            ret = listPushFront(list, element);
        } else {
            Node *newNode = createNode(element, NULL, NULL);
            if(newNode == NULL)
                ret = LIST_OUT_OF_MEMORY;

            if(ret == LIST_OK) {
                // Attaching new node to the d-linked list
                newNode->prev = positionNode->prev;
                newNode->next = positionNode;
                positionNode->prev->next = newNode;
                positionNode->prev = newNode;

                ++(list->elementsCount);
            }
        }
    }

    return ret;
}

// Removes a given node from the list
private ListResultCode removeNode(List *list, Node *positionNode) {
    ListResultCode ret = LIST_OK;

    if(list == NULL || positionNode == NULL)
        ret = LIST_FAIL;

    if(ret == LIST_OK) {
        if(positionNode->prev == NULL) { // If removing from first position
            ret = listPopFront(list);
        } else if(positionNode->next == NULL) { // If removing from last position
            ret = listPopBack(list);
        } else {
            positionNode->prev->next = positionNode->next;
            positionNode->next->prev = positionNode->prev;

            destroyNode(positionNode);

            --(list->elementsCount);
        }
    }

    return ret;
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
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_FIND_NOT_FOUND;

    *iterator = createIterator(list->firstNode->data, list->firstNode);

    if(*iterator == NULL)
        return LIST_OUT_OF_MEMORY;

    return LIST_OK;
}

ListResultCode listGetEnd(List *list, ListIterator **iterator) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_FIND_NOT_FOUND;

    *iterator = createIterator(list->lastNode->data, list->lastNode);

    if(*iterator == NULL)
        return LIST_OUT_OF_MEMORY;

    return LIST_OK;
}

ListResultCode listFindElement(List *list, unsigned long position, ListIterator **iterator) {
    if(list == NULL)
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

    Node *currentNode = iterator->currentNode;

    if(currentNode == NULL)
        return LIST_FAIL;

    if(currentNode->next == NULL)
        return LIST_ITERATOR_END_REACHED;

    currentNode = currentNode->next;
    iterator->data = currentNode->data;
    iterator->currentNode = currentNode;

    return LIST_OK;
}

ListResultCode listMoveBack(ListIterator *iterator) {
    if(iterator == NULL)
        return LIST_FAIL;

    Node *currentNode = iterator->currentNode;

    if(currentNode == NULL)
        return LIST_FAIL;

    if(currentNode->prev == NULL)
        return LIST_ITERATOR_BEGIN_REACHED;

    currentNode = currentNode->prev;
    iterator->data = currentNode->data;
    iterator->currentNode = currentNode;

    return LIST_OK;
}

ListResultCode listInsert(List *list, ListIterator *iterator, void *element) {
    if(iterator == NULL)
        return LIST_FAIL;

    return insertAtNode(list, iterator->currentNode, element);
}

ListResultCode listInsertAtIndex(List *list, unsigned long position, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    if(position > list->elementsCount)
        return LIST_OUT_OF_BOUNDS;

    if(list->elementsCount == 0UL) { // List is empty, inserting first element
        return insertFirstNode(list, element);
    } else if(position == 0UL) { // Pushing the element in front
        return listPushFront(list, element);
    } else if(position == list->elementsCount) { // Pushing the element in back
        return listPushBack(list, element);
    } else { // Defult insertion case
        ListIterator *iterator;
        ListResultCode ret = LIST_FAIL;

        ret = listFindElement(list, position, &iterator);
        if(ret == LIST_OK)
            ret = listInsert(list, iterator, element);

        if(iterator != NULL)
            free(iterator);

        return ret;
    }
}

ListResultCode listPushFront(List *list, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL) {
        return insertFirstNode(list, element);
    } else {
        Node *newNode = createNode(element, NULL, list->firstNode);

        if(newNode == NULL)
            return LIST_FAIL;

        list->firstNode->prev = newNode;
        list->firstNode = newNode;
        ++(list->elementsCount);

        return LIST_OK;
    }
}

ListResultCode listPushBack(List *list, void *element) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL) {
        return insertFirstNode(list, element);
    } else {
        Node *newNode = createNode(element, list->lastNode, NULL);

        if(newNode == NULL)
            return LIST_FAIL;

        list->lastNode->next = newNode;
        list->lastNode = newNode;
        ++(list->elementsCount);

        return LIST_OK;
    }
}

ListResultCode listRemove(List *list, ListIterator *iterator) {
    if(iterator == NULL || iterator->currentNode == NULL)
        return LIST_FAIL;

    Node *currentNode = iterator->currentNode;
    Node *nextNode = currentNode->next;
    ListResultCode ret = removeNode(list, currentNode);

    // On success, sets the iterator to the next node
    if(ret == LIST_OK) {
        iterator->currentNode = nextNode;

        if(nextNode != NULL)
            iterator->data = nextNode->data;
    }

    return ret;
}

ListResultCode listRemoveFromIndex(List *list, unsigned long position) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_REMOVE_ALREADY_EMPTY;

    if(position >= list->elementsCount)
        return LIST_OUT_OF_BOUNDS;

    if(position == 0UL) { // Popping the element from front
        return listPopFront(list);
    } else if(position == list->elementsCount - 1) { // Popping the element from back
        return listPopBack(list);
    } else { // Defult insertion case
        ListIterator *iterator;
        ListResultCode ret = LIST_FAIL;

        ret = listFindElement(list, position, &iterator);
        if(ret == LIST_OK)
            ret = listRemove(list, iterator);

        if(iterator != NULL)
            free(iterator);

        return ret;
    }
}

ListResultCode listPopFront(List *list) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_REMOVE_ALREADY_EMPTY;

    Node *nodeToPop = list->firstNode;

    if(list->elementsCount == 1UL) { // Last node being removed
        list->firstNode = list->lastNode = NULL;
    } else {
        list->firstNode = list->firstNode->next;
        list->firstNode->prev = NULL;
    }

    destroyNode(nodeToPop);
    --(list->elementsCount);

    return LIST_OK;
}

ListResultCode listPopBack(List *list) {
    if(list == NULL)
        return LIST_FAIL;

    if(list->elementsCount == 0UL)
        return LIST_REMOVE_ALREADY_EMPTY;

    Node *nodeToPop = list->lastNode;

    if(list->elementsCount == 1UL) { // Last node being removed
        list->firstNode = list->lastNode = NULL;
    } else {
        list->lastNode = list->lastNode->prev;
        list->lastNode->next = NULL;
    }

    destroyNode(nodeToPop);
    --(list->elementsCount);

    return LIST_OK;
}

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