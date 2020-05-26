/*----------------------------------------------------------------------------
 *
 * day_of_the_week.c
 *   Given a date, return the corresponding day of the week for that date.
 *
 *   The input is given as three integers representing the `day`, `month`
 *   and `year` respectively.
 *
 *   Return the answer as one of the following values `{"Sunday", "Monday",
 *   "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}`.
 *
 *----------------------------------------------------------------------------
 */

static const char *Weekdays[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};


char *
dayOfTheWeek(int day, int month, int year)
{
    int i;

    year -= month < 3;
    i = (year + year / 4 - year / 100 + year / 400 + "-bed=pen+mad."[month] + day) % 7;

    return (char *) Weekdays[i];
}
