/*----------------------------------------------------------------------------
 *
 * implement_queue_using_stacks.c
 *   Implement the following operations of a queue using stacks.
 *
 *   - push(x) -- Push element x to the back of queue.
 *   - pop() -- Removes the element from in front of queue.
 *   - peek() -- Get the front element.
 *   - empty() -- Return whether the queue is empty.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int top;
    int capacity;
    int *stack;
} MyStack;

static MyStack *
myStackCreate(int maxSize)
{
    MyStack *stack;

    stack = (MyStack *) malloc(sizeof(MyStack) + sizeof(int) * maxSize);
    stack->top = -1;
    stack->capacity = maxSize;
    stack->stack = (int *)((char *) stack + sizeof(MyStack));

    return stack;
}

static int
getMyStackSize(MyStack *stack)
{
    return stack->top + 1;
}

static bool
myStackEmpty(MyStack *stack)
{
    return stack->top == -1;
}

static void
myStackPush(MyStack *stack, int x)
{
    if (stack->top == stack->capacity - 1) {

        int size = sizeof(MyStack) + sizeof(int) * 2 * stack->capacity;
        stack = (MyStack *) realloc(stack, size);
        stack->capacity *= 2;
    }

    stack->stack[++stack->top] = x;
}

static int
myStackPop(MyStack *stack)
{
    if (stack->top > -1) {
        return stack->stack[stack->top--];
    }

    return -1;
}

static int
myStackPeek(MyStack *stack)
{
    if (stack->top > -1) {
        return stack->stack[stack->top];
    }

    return -1;
}

static void
myStackFree(MyStack *stack)
{
    free(stack);
}

typedef struct {
    MyStack *in;
    MyStack *out;
} MyQueue;

/*
 * Initialize your data structure here.
 */
MyQueue *
myQueueCreate(int maxSize)
{
    MyQueue *q;

    q = (MyQueue *) malloc(sizeof(MyQueue));

    q->in = myStackCreate(maxSize);
    q->out = myStackCreate(maxSize);

    return q;
}

/*
 * Push element x to the back of queue.
 */
void
myQueuePush(MyQueue *obj, int x)
{
    myStackPush(obj->in, x);
}

/*
 * Removes the element from in front of queue and returns that element.
 */
int
myQueuePop(MyQueue *obj)
{
    if (!myStackEmpty(obj->out)) {
        return myStackPop(obj->out);
    }

    while (!myStackEmpty(obj->in)) {
        myStackPush(obj->out, myStackPop(obj->in));
    }

    return myStackPop(obj->out);
}

/*
 * Get the front element.
 */
int
myQueuePeek(MyQueue *obj)
{
    if (!myStackEmpty(obj->out)) {
        return myStackPeek(obj->out);
    }

    while (!myStackEmpty(obj->in)) {
        myStackPush(obj->out, myStackPop(obj->in));
    }

    return myStackPeek(obj->out);
}

/*
 * Returns whether the queue is empty.
 */
bool
myQueueEmpty(MyQueue *obj)
{
    return myStackEmpty(obj->in) && myStackEmpty(obj->out);
}

void
myQueueFree(MyQueue *obj)
{
    myStackFree(obj->in);
    myStackFree(obj->out);
    free(obj);
}
