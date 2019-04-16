/*----------------------------------------------------------------------------
 *
 * unique_email_addresses.c
 *   Every email consists of a local name and a domain name, separated
 *   by the @ sign.
 *
 *   For example, in `alice@leetcode.com`, `alice` is the local name,
 *   and `leetcode.com` is the domain name.
 *
 *   Besides lowercase letters, these emails may contain `'.'`s or
 *   `'+'`s.
 *
 *   If you add periods ('.') between some characters in the
 *   __local name__ part of an email address, mail sent there will be
 *   forwarded to the same address without dots in the local name.
 *   For example, `"alice.z@leetcode.com"` and `"alicez@leetcode.com"`
 *   forward to the same email address.  (Note that this rule does not
 *   apply for domain names.)
 *
 *   If you add a plus (`'+'`) in the __local name__, everything after
 *   the first plus sign will be __ignored__. This allows certain emails
 *   to be filtered, for example `m.y+name@email.com` will be forwarded
 *   to my@email.com.  (Again, this rule does not apply for domain
 *   names.)
 *
 *   It is possible to use both of these rules at the same time.
 *
 *   Given a list of emails, we send one email to each address in the
 *   list.  How many different addresses actually receive mails?
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void
fliter(char *email)
{
    char *t = email;

    while (*t != '+' && *t != '@') {
        if (*t == '.') {
            t++;
        } else {
            *email++ = *t++;
        }
    }

    while (*t != '@') {
        t++;
    }
    while (*t) {
        *email = *t;
        email++, t++;
    }
    *email = '\0';
}

static int
cmpstring(const void *a, const void *b)
{
    return strcmp(*(char * const *) a, *(char * const *) b);
}

int
numUniqueEmails(char **emails, int emailsSize)
{
    int i, j, c;
    if (emailsSize < 2) {
        return emailsSize;
    }

    for (i = 0; i < emailsSize; i++) {
        fliter(emails[i]);
    }

    qsort(emails, emailsSize, sizeof(char *), cmpstring);

    for (i = 0, c = j = 1; j < emailsSize; j++) {
        if (cmpstring(&emails[i], &emails[j]) != 0) {
            c++;
            i = j;
        }
    }

    return c;
}
