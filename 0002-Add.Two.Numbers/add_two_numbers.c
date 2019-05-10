/*----------------------------------------------------------------------------
 *
 * add_two_numbers.c
 *   You are given __non-empty__ linked lists reprsenting two
 *   non-negative integers. The digits are stored in __reverse order__
 *   and each of their nodes contain a single digit. Add the two numbers
 *   do not contain any leading zero, except the number 0 itself.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *
addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode head = {0, NULL};
    struct ListNode *tail = &head;
    int carry = 0;
    int tmp;

    while (l1 && l2) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        tmp = l1->val + l2->val + carry;
        tail->val = tmp % 10;
        tail->next = NULL;
        carry = tmp / 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        tmp = l1->val + carry;
        tail->val = tmp % 10;
        tail->next = NULL;
        carry = tmp / 10;

        l1 = l1->next;
    }

    while (l2) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        tmp = l2->val + carry;
        tail->val = tmp % 10;
        tail->next = NULL;
        carry = tmp / 10;

        l2 = l2->next;
    }

    if (carry) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = carry;
        tail->next = NULL;
    }

    return head.next;
}
