/*----------------------------------------------------------------------------
 *
 * Two sum
 *
 * gcc -o add_two_numbers add_two_numbers.c
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define unused(expr) ((void) (expr))

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

    while (l1 && l2) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        int tmp = l1->val + l2->val + carry;
        tail->val = tmp % 10;
        tail->next = NULL;
        carry = tmp / 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        int tmp = l1->val + carry;
        tail->val = tmp % 10;
        tail->next = NULL;
        carry = tmp / 10;

        l1 = l1->next;
    }

    while (l2) {
        tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail = tail->next;

        int tmp = l2->val + carry;
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

static void
freeList(struct ListNode *list)
{
    struct ListNode *next;
    while (list) {
        next = list->next;
        free(list);
        list = next;
    }
}

static void
printList(struct ListNode *list)
{
    printf("[");
    while (list) {
        printf("%d, ", list->val);
        list = list->next;
    }
    printf("\b\b]");
}

static void
printResult(struct ListNode *l1, struct ListNode *l2, struct ListNode *r)
{
    printList(l1);
    printf(" ");
    printList(l2);
    printf(" -> ");
    printList(r);
    printf("\n");
}

int
main(int argc, char *argv[])
{
    int l1, l2;
    struct ListNode list1, list2;

    unused(argc), unused(argv);


    while (scanf("%d%d", &l1, &l2) != EOF) {
        struct ListNode *tail = &list1;
        while (l1) {
            tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->next = NULL;
            scanf("%d", &(tail->val));
            l1--;
        }

        tail = &list2;
        while (l2) {
            tail->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->next = NULL;
            scanf("%d", &(tail->val));
            l2--;
        }

        struct ListNode *result;
        result = addTwoNumbers(list1.next, list2.next);

        printResult(list1.next, list2.next, result);

        freeList(result);
        freeList(list1.next);
        freeList(list2.next);
    }
    return 0;
}
