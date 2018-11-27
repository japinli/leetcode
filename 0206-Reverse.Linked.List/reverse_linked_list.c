/*----------------------------------------------------------------------------
 *
 * reverse_linked_list.c
 *   Reverse a singly linked list.
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
reverseList1(struct ListNode *head)
{
    struct ListNode fake = {0, NULL};
    struct ListNode *node;

    while (head) {
        node = head;
        head = node->next;

        node->next = fake.next;
        fake.next = node;
    }

    return fake.next;
}

struct ListNode *
reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *p = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return p;
}
