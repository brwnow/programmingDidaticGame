#include <testsdefs.h>

#include "utils/datastructure/list.h"
#include "utils/datastructure/list_private.h"
#include "utils/datastructure/list_tests.h"
#include "utils/datastructure/list_test_setups.h"

DEFINE_STANDALONE_TEST_FUNC(createNode) {
    Node *node = createNode((void*)1UL,
                            (Node*)2UL,
                            (Node*)3UL,
                            (List*)4UL);

    munit_assert_not_null(node);
    munit_assert_ptr_equal(node->data, (void*)1UL);
    munit_assert_ptr_equal(node->prev, (void*)2UL);
    munit_assert_ptr_equal(node->next, (void*)3UL);
    munit_assert_ptr_equal(node->parent, (void*)4UL);

    destroyNode(node);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(createNodeNullParent) {
    Node *node = createNode((void*)1UL,
                            (Node*)2UL,
                            (Node*)3UL,
                            NULL);

    munit_assert_null(node);

    // For the case it failed and didn't returned null
    destroyNode(node);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(createIterator) {
    ListIterator *iterator = createIterator((void*)1UL, (Node*)2UL);

    munit_assert_not_null(iterator);
    munit_assert_ptr_equal(iterator->data, (void*)1UL);
    munit_assert_ptr_equal(iterator->currentNode, (void*)2UL);

    // For the case it failed and didn't returned null
    free(iterator);

    return MUNIT_OK;
}

// ============

DEFINE_STANDALONE_TEST_FUNC(listCreate) {
    List *list = listCreate();

    munit_assert_not_null(list);
    munit_assert_ulong(list->elementsCount, ==, 0UL);
    munit_assert_null(list->firstNode);
    munit_assert_null(list->lastNode);

    listDestroy(list);

    return MUNIT_OK;
}

// =================
// == TEST ARRAYS ==
// =================

static MunitTest listTests[] = {
    GET_TEST_FUNC_ARRAY_ENTRY("/createNode", createNode),
    GET_TEST_FUNC_ARRAY_ENTRY("/createNode-nullParent", createNodeNullParent),
    GET_TEST_FUNC_ARRAY_ENTRY("/createIterator", createIterator),
    GET_TEST_FUNC_ARRAY_ENTRY("/listCreate", listCreate),

    TEST_FUNC_ARRAY_END
};

static MunitSuite listTestsSuite = {
    "/creating",
    listTests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

MunitSuite listCreateTestsGetSuite(void) {
    return listTestsSuite;
}