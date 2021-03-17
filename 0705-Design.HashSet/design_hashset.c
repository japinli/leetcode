/*----------------------------------------------------------------------------
 *
 * design_hashset.c
 *   Design a HashSet without using any built-in hash table libraries.
 *
 *   Implement `MyHashSet` class:
 *
 *     - `void add(key)` Inserts the value `key` into the HashSet.
 *     - `bool contains(key)` Returns whether the value `key` exists in the
 *       HashSet or not.
 *     - `void remove(key)` Removes the value `key` in the HashSet. If `key`
 *       does not exist in the HashSet, do nothing.
 *
 *----------------------------------------------------------------------------
 */
#define MAX_BYTE_LEN (1000000 / 8 + 1)

typedef struct {
    char set[MAX_BYTE_LEN];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *s = NULL;
    
    if ((s = (MyHashSet *) malloc(sizeof(MyHashSet))) != NULL) {
        memset(s->set, 0, sizeof(char) * MAX_BYTE_LEN);
    }

    return s;
}

void myHashSetAdd(MyHashSet* s, int key) {
    int byte_offset = key / 8;
    int bit_offset = key % 8;

    s->set[byte_offset] |= 1 << bit_offset;
}

void myHashSetRemove(MyHashSet* s, int key) {
    int byte_offset = key / 8;
    int bit_offset = key % 8;

    s->set[byte_offset] &= ~(1 << bit_offset);
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* s, int key) {
    int byte_offset = key / 8;
    int bit_offset = key % 8;

    return s->set[byte_offset] & (1 << bit_offset);
}

void myHashSetFree(MyHashSet* obj) {
    if (obj) {
        free(obj);
    }
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/