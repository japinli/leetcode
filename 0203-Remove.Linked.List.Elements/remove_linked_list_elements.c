/*----------------------------------------------------------------------------
 *
 * remove_linked_list_elements.c
 *   Remove all elements from a linked list of integers that have value
 *   `val`.
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
removeElements(struct ListNode *head, int val)
{
    struct ListNode fake = {0, head};
    struct ListNode *prev = &fake;
    struct ListNode *next = fake.next;

    while (next) {
        if (next->val == val) {
            prev->next = next->next;
        } else {
            prev = prev->next;
        }
        next = next->next;
    }

    return fake.next;
}

struct ListNode *
removeElements2(struct ListNode *head, int val)
{
    struct ListNode fake = {0, head};
    struct ListNode *curr = &fake;

    while (curr->next) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return fake.next;
}
