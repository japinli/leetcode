/*----------------------------------------------------------------------------
 *
 * simplify_path.c
 *     Given an absolute path for a file (Unix-style), simplify it. Or
 *     in other words, convert it to the canonical path.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *
simplifyPath(char *path)
{
    int   dots = 0;
    char *dst;
    char *src;

    for (dst = path, src = path; *src; src++) {
        if (*src == '/') {
            if (dots == 1) {
                dst--;
            } else if (dots == 2) {
                dst -= 3;
                while (dst > path && *(dst - 1) != '/') {
                    dst--;
                }
                if (dst <= path) {
                    dst = path + 1;
                }
            } else if (dst == path || *(dst - 1) != '/') {
                *dst++ = *src;
            }
            dots = 0;
        } else if (*src == '.') {
            *dst++ = *src;
            dots++;
        } else {
            *dst++ = *src;
            dots = 0;
        }
    }

    if (dots == 1) {
        dst--;
    } else if (dots == 2) {
        dst -= 3;
        while (dst > path && *(dst - 1) != '/') {
            dst--;
        }
        if (dst <= path) {
            dst = path + 1;
        }
    }

    while (dst > path && *(dst - 1) == '/') {
        dst--;
    }
    if (dst == path) {
        dst++;
    }
    *dst = '\0';

    return path;
}
