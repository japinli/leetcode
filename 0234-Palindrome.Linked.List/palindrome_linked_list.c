/*----------------------------------------------------------------------------
 *
 * palindrome_linked_list.c
 *   Given a singly linked list, determine if it is a palindrome.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static struct ListNode *
reverseList(struct ListNode *head)
{
    struct ListNode fake = {0, NULL};
    struct ListNode *curr = head;
    struct ListNode *next;

    while (curr) {
        next = curr->next;
        curr->next = fake.next;
        fake.next = curr;
        curr = next;
    }

    return fake.next;
}

bool
isPalindrome(struct ListNode* head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = head;
    slow = reverseList(slow);

    while (slow && fast) {
        if (slow->val != fast->val) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return true;
}
