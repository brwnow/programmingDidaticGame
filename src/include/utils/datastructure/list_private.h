#ifndef _DIDATIC_GAME_LIST_PRIV_H_
#define _DIDATIC_GAME_LIST_PRIV_H_

struct _Node {
    void *data;
    struct _Node *prev;
    struct _Node *next;
};

struct _List {
    Node *firstNode;
    Node *lastNode;
    unsigned long elementsCount;
};

#endif // _DIDATIC_GAME_LIST_PRIV_H_