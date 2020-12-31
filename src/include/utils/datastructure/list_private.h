#ifndef _DIDATIC_GAME_LIST_PRIV_H_
#define _DIDATIC_GAME_LIST_PRIV_H_

struct _Node {
    void *data;
    struct _Node *prev;
    struct _Node *next;

    // The list that owns this node
    struct _List *parent;
};

struct _List {
    Node *firstNode;
    Node *lastNode;
    unsigned long elementsCount;
};

#ifdef _TESTS_ENABLED_

    Node* createNode(void *data, Node *previous, Node *next, List *parent);
    void destroyNode(Node *node);

    ListIterator* createIterator(void *data, Node *currentNode);

    ListResultCode listInsertEx(List *list, Node *positionNode, ListRelativePosition relativePos, void *element);
    ListResultCode listRemoveEx(List *list, Node *positionNode);

#endif // _TESTS_ENABLED_

#endif // _DIDATIC_GAME_LIST_PRIV_H_