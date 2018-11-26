/*----------------------------------------------------------------------------
 *
 * design_linked_list.c
 *   Design your implementation of the linked list. You can choose to
 *   use the singly linked list or the doubly linked list. A node in a
 *   singly linked list should have two attributes: val and next. val is
 *   the value of the current node, and next is a pointer/reference to
 *   the next node. If you want to use the doubly linked list, you will
 *   need one more attribute prev to indicate the previous node in the
 *   linked list. Assume all nodes in the linked list are 0-indexed.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct Node MyNode;

typedef struct
{
    int size;
    struct Node *head;
} MyLinkedList;

/*
 * Initialize your data structure here.
 */
MyLinkedList *
myLinkedListCreate()
{
    MyLinkedList *list;

    list = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    if (list) {
        list->size = 0;
        list->head = NULL;
    }

    return list;
}

/*
 * Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1.
 */
int
myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size) {
        return -1;
    }

    MyNode *curr = obj->head;

    while (index--) {
        curr = curr->next;
    }

    return curr->val;
}

/*
 * Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list.
 */
void
myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyNode *node;

    node = (MyNode *) malloc(sizeof(MyNode));
    if (node == NULL) {
        return;
    }

    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

/*
 * Append a node of value val to the last element of the linked list.
 */
void
myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyNode *node;

    if (obj->size == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    node = (MyNode *) malloc(sizeof(MyNode));
    if (node == NULL) {
        return;
    }
    node->val = val;

    MyNode *prev = obj->head;

    while (prev->next) {
        prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;
    obj->size++;
}

/*
 * Add a node of value val before the index-th node in the linked list. If index
 * equals to the length of linked list, the node will be appended to the end of
 * linked list. If index is greater than the length, the node will not be
 * inserted.
 */
void
myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index < 0 || index > obj->size) {
        return;
    }

    if (obj->size == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    MyNode *node;
    node = (MyNode *) malloc(sizeof(MyNode));
    if (node == NULL) {
        return;
    }
    node->val = val;

    MyNode *prev = obj->head;
    index--;
    while (index-- > 0) {
        prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;
    obj->size++;
}

/*
 * Delete the index-th node in the linked list, if the index is valid.
 */
void
myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (index < 0 || index >= obj->size) {
        return;
    }

    MyNode *prev = obj->head;

    index--;
    while (index-- > 0) {
        prev = prev->next;
    }

    MyNode *node = prev->next;

    prev->next = node->next;
    obj->size--;
    free(node);
}

void
myLinkedListFree(MyLinkedList *obj)
{
    MyNode *node = obj->head;

    while (node) {
        obj->head = node->next;
        free(node);
        node = obj->head;
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
