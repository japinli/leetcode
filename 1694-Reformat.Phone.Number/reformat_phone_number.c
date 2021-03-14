/*----------------------------------------------------------------------------
 *
 * reformat_phone_number.c
 *   You are given a phone number as a string `number`. `number` consists of
 *   digits, spaces `' '`, and/or dashes `'-'`.
 *
 *   You would like to reformat the phone number in a certain manner.
 *   Firstly, remove all spaces and dashes. Then, group the digits
 *   from left to right into blocks of length 3 until there are 4 or
 *   fewer digits. The final digits are then grouped as follows:
 *
 *   - 2 digits: A single block of length 2.
 *   - 3 digits: A single block of length 3.
 *   - 4 digits: Two blocks of length 2 each.
 *
 *   The blocks are then joined by dashes. Notice that the reformatting
 *   process should never produce any blocks of length 1 and produce
 *   at most two blocks of length 2.
 *
 *   Return the phone number after formatting.
 *
 *----------------------------------------------------------------------------
 */
char * 
reformatNumber(char *number)
{
    int len = strlen(number);
    int num_digits = 0;
    int i, j;
    char *res;

    /* remove the spaces and dashes */
    for (int i = 0; i < len; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            number[num_digits++] = number[i];
        }
    }
    number[num_digits] = '\0';
    len = num_digits + num_digits / 3 + 3;
    res = (char *) malloc(sizeof(char) * len);

    i = j = 0;
    while (number[i] != '\0') {
        int reminder = num_digits - i;
        if (reminder > 4) {
            res[j++] = number[i++];
            res[j++] = number[i++];
            res[j++] = number[i++];
            res[j++] = '-';
        } else if (reminder == 4) {
            res[j++] = number[i++];
            res[j++] = number[i++];
            res[j++] = '-';
            res[j++] = number[i++];
            res[j++] = number[i++];
        } else if (reminder == 3) {
            res[j++] = number[i++];
            res[j++] = number[i++];
            res[j++] = number[i++];
        } else if (reminder == 2) {
            res[j++] = number[i++];
            res[j++] = number[i++];
        }
    }
    res[j] = '\0';

    return res;
}

#if 0
char * 
reformatNumber(char *number)
{
    int len = strlen(number);
    int idx = 0;
    int newlen = 0;
    int digits = 0;
    char *res;

    /* collect the number of digits */
    for (int i = 0; i < len; i++) {
        if (isdigit(number[i])) {
            digits++;
        }
    }

    newlen = digits + (digits / 3 + 2);
    res = (char *) malloc(sizeof(char) * newlen);
    for (int i = 0, j = 0; i < len; i++) {
        if (isdigit(number[i])) {
            j++;
            res[idx++] = number[i];
            if (digits > j && j % 3 == 0) {
                res[idx++] = '-';
            }
        }
    }

    /* adjust if the last only has one digit */
    if (digits % 3 == 1) {
        char t = res[idx - 2];
        res[idx - 2] = res[idx - 3];
        res[idx - 3] = t;
    }
    res[idx] = '\0';

    return res;
}
#endif