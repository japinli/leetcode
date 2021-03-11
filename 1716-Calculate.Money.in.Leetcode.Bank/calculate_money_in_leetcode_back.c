/*----------------------------------------------------------------------------
 *
 * calculate_money_in_leetcode_back.c
 *   Hercy wants to save money for his first car. He puts money in the
 *   Leetcode bank every day.
 *
 *   He starts by putting in `$1` on Monday, the first day. Every day
 *   from Tuesday to Sunday, he will put in `$1` more than the day
 *   before. On every subsequent Monday, he will put in `$1` more than
 *   the previous Monday.
 *
 *   Given `n`, return the total amount of money he will have in the
 *   Leetcode bank at the end of the `n-th` day.
 *
 *----------------------------------------------------------------------------
 */

int
totalMoney(int n)
{
    int money = 0;
    int count = 1;
    int weeks = 0;

    for (int i = 0; i < n; i++) {
        money += count + weeks;
        count++;

        if (count > 7) {
            weeks++;
            count = 1;
        }
    }

    return money;
}

#if 0

int totalMoney(int n){
	int money = 0;
    int days = n % 7;
    int weeks = n / 7;

    money = 28 * weeks + (weeks - 1) * weeks / 2 * 7;

    for (int i = 1; i <= days; i++) {
	    money += i + weeks;
    }
    
    return money;
}

#endif
