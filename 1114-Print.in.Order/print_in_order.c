/*----------------------------------------------------------------------------
 *
 * print_in_order.c
 *   Suppose we have a class:
 *
 *   ```
 *   public class Foo {
 *     public void first() { print("first"); }
 *     public void second() { print("second"); }
 *     public void third() { print("third"); }
 *   }
 *   ```
 *
 *   The same instance of `Foo` will be passed to three different threads.
 *   Thread A will call `first()`, thread B will call `second()`, and thread
 *   C will call `third()`. Design a mechanism and modify the program to
 *   ensure that `second()` is executed after `first()`, and `third()` is
 *   executed after `second()`.
 *
 *----------------------------------------------------------------------------
 */

typedef struct
{
    /* User defined data may be declared here. */
    char  flags;
} Foo;

Foo *
fooCreate()
{
    Foo* obj = (Foo*) malloc(sizeof(Foo));

    /* Initialize user defined data here. */

    return obj;
}

void
first(Foo *obj)
{
    /* printFirst() outputs "first". Do not change or remove this line. */
    printFirst();
    obj->flags = 0;
}

void
second(Foo *obj)
{
    /* waste some cpu */
    while (obj->flags != 0) {
        /* we must be use usleep, sleep will cause Time Limit Exceeded. */
        usleep(500);
    }

    /* printSecond() outputs "second". Do not change or remove this line. */
    printSecond();
    obj->flags = 1;
}

void
third(Foo *obj)
{
    while (obj->flags != 1) {
        usleep(500);
    }

    /* printThird() outputs "third". Do not change or remove this line. */
    printThird();
}

void fooFree(Foo* obj) {
    /* User defined data may be cleaned up here. */
    free(obj);
}


#if SEM_SOLUTION
typedef struct
{
    /* User defined data may be declared here. */
    sem_t first_sem;
    sem_t second_sem;
} Foo;

Foo *
fooCreate()
{
    Foo* obj = (Foo*) malloc(sizeof(Foo));

    /* Initialize user defined data here. */
    sem_init(&obj->first_sem, 0, 0);
    sem_init(&obj->second_sem, 0, 0);

    return obj;
}

void
first(Foo *obj)
{
    /* printFirst() outputs "first". Do not change or remove this line. */
    printFirst();
    sem_post(&obj->first_sem);
}

void
second(Foo *obj)
{
    sem_wait(&obj->first_sem);
    /* printSecond() outputs "second". Do not change or remove this line. */
    printSecond();
    sem_post(&obj->second_sem);
}

void
third(Foo *obj)
{
    sem_wait(&obj->second_sem);
    /* printThird() outputs "third". Do not change or remove this line. */
    printThird();
}

void fooFree(Foo* obj) {
    /* User defined data may be cleaned up here. */
    free(obj);
}

#endif
