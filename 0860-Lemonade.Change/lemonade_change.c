/*----------------------------------------------------------------------------
 *
 * lemonade_change.c
 *   At a lemonade stand, each lemonade costs `$5`.
 *
 *   Customers are standing in a queue to buy from you, and order one at a
 *   time (in the order specified by `bills`).
 *
 *   Each customer will only buy one lemonade and pay with either a `$5`,
 *   `$10`, or `$20` bill.  You must provide the correct change to each
 *   customer, so that the net transaction is that the customer pays `$5`.
 *
 *   Note that you don't have any change in hand at first.
 *
 *   Return `true` if and only if you can provide every customer with correct
 *   change.
 *
 *----------------------------------------------------------------------------
 */

bool
lemonadeChange(int *bills, int billsSize)
{
    int five = 0;
    int ten = 0;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (--five < 0) {
                return false;
            }
            ten++;
        } else {
            if (ten && five) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}
