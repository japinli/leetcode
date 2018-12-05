/*----------------------------------------------------------------------------
 *
 * long_pressed_name.c
 *   Your friend is typing his `name` into a keyboard.  Sometimes, when
 *   typing a character `c`, the key might get long pressed, and the
 *   character will be typed 1 or more times.
 *
 *   You examine the `typed` characters of the keyboard.  Return `True`
 *   if it is possible that it was your friends name, with some
 *   characters (possibly none) being long pressed.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool
isLongPressedName(char *name, char *typed)
{
    while (*name) {
        if (*name != *typed) {
            return false;
        }

        /*
         * If there has repeated character, calculate the lengh of
         * repeated character.
         */
        int len = 1;
        while (*name == *(name + len)) {
            len++;
        }

        if (len && strncmp(name, typed, len) != 0) {
            return false;
        } else {
            name += len - 1;
            typed += len - 1;
        }

        while (*name == *typed) {
            typed++;
        }
        name++;
    }

    return true;
}
