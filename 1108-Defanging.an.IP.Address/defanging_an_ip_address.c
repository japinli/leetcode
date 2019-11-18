/*----------------------------------------------------------------------------
 *
 * defanging_an_ip_address.c
 *   Given a valid (IPv4) IP `address`, return a defanged version of
 *   that IP address.
 *   A defanged IP address replaces every period `"."` with `"[.]"`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
defangIPaddr(char *address)
{
    char    *s;
    char    *result;
    size_t   len;

    len = strlen(address);
    result = (char *) malloc(sizeof(char) * (len + 3 * 2 + 1));
    s = result;

    while (*address) {
        if (*address == '.') {
            *s++ = '[';
            *s++ = *address++;
            *s++ = ']';
        } else {
            *s++ = *address++;
        }
    }
    *s = '\0';

    return result;
}
