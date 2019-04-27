/*----------------------------------------------------------------------------
 *
 * number_of_recent_calls.c
 *   Write a class `RecentCounter` to count recent requests.
 *
 *   It has only one method: `ping(int t)`, where `t` represents some
 *   time in milliseconds.
 *
 *   Return the number of `pings` that have been made from `3000`
 *   milliseconds ago until now.
 *
 *   Any ping with time in `[t - 3000, t]` will count, including the
 *   current `ping`.
 *
 *   It is guaranteed that every call to `ping` uses a strictly larger
 *   value of `t` than before.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------------------
 *
 * The first solution I got.

struct ping
{
    int val;
    struct ping *next;
};

typedef struct {
    struct ping *pings;
} RecentCounter;

RecentCounter *
recentCounterCreate()
{
    RecentCounter *obj = (RecentCounter *) malloc(sizeof(RecentCounter));
    obj->pings = NULL;
    return obj;
}

int
recentCounterPing(RecentCounter *obj, int t)
{
    int count = 1;
    struct ping *q = obj->pings;
    struct ping *p = (struct ping *) malloc(sizeof(struct ping));
    p->val = t;
    p->next = obj->pings;
    obj->pings = p;

    while (q) {

        if (t > 3000 && q->val < t - 3000) {
            break;
        } else {
            count++;
            q = q->next;
            p = p->next;
        }
    }
    while (q) {
        struct ping *x = q->next;
        free(q);
        q = x;
    }
    p->next = NULL;

    return count;
}

void recentCounterFree(RecentCounter* obj) {
    struct ping *q = obj->pings;
    while (q) {
        struct pings *x = q->next;
        free(q);
        q = x;
    }

    free(obj);
}

*----------------------------------------------------------------------------
*/

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * struct RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */

typedef struct
{
    int now;
    int prev;
    int pings[10000];
} RecentCounter;

RecentCounter *
recentCounterCreate()
{
    RecentCounter *obj = (RecentCounter *) malloc(sizeof(RecentCounter));
    memset(obj, 0, sizeof(RecentCounter));
    return obj;
}

int
recentCounterPing(RecentCounter *obj, int t)
{
    obj->pings[obj->now++] = t;

    while (obj->pings[obj->prev] < t - 3000) {
        obj->prev++;
    }

    return obj->now - obj->prev;
}

void
recentCounterFree(RecentCounter *obj)
{
    free(obj);
}
