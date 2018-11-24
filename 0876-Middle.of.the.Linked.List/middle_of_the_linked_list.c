/*----------------------------------------------------------------------------
 *
 * middle_of_the_linked_list.c
 *   Given a non-empty, singly linked list with head node head, return a
 *   middle node of linked list.
 *
 *   If there are two middle nodes, return the second middle node.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *
middleNode(struct ListNode *head)
{
    int count = 0;
    struct ListNode *p = head;

    while (p) {
        count++;
        p = p->next;
    }

    p = head;
    count >>= 1;
    while (count--) {
        p = p->next;
    }

    return p;
}

struct ListNode *
middleNode2(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
