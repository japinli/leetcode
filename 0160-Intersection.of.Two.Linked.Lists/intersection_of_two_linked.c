/*----------------------------------------------------------------------------
 *
 * intersection_of_two_linked.c
 *   Write a program to find the node at which the intersection of two
 *   singly linked lists begins.
 *
 *----------------------------------------------------------------------------
 */

struct ListNode *
getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) {
        return NULL;
    }

    while (p1 != p2) {
        p1 = p1 ? p1->next : headA;
        p2 = p2 ? p2->next : headB;
    }

    return p1;
}
