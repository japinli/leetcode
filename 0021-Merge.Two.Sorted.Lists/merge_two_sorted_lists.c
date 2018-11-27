/*----------------------------------------------------------------------------
 *
 * merge_two_sorted_lists.c
 *   Merge two sorted linked lists and return it as a new list. The new
 *   list should be made by splicing together the nodes of the first two
 *   lists.
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
mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode fake = {0, NULL};
    struct ListNode *curr = &fake;
    struct ListNode *node;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            node = l1;
            l1 = l1->next;
        } else {
            node = l2;
            l2 = l2->next;
        }

        node->next = NULL;
        curr->next = node;
        curr = node;
    }

    if (l1) {
        curr->next = l1;
    }

    if (l2) {
        curr->next = l2;
    }

    return fake.next;
}
