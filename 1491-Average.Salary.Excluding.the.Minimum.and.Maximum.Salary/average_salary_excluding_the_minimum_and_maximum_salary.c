/*----------------------------------------------------------------------------
 *
 * average_salary_excluding_the_minimum_and_maximum_salary.c
 *   Given an array of __unique__ integers `salary` where `salary[i]` is the
 *   salary of the employee `i`.
 *
 *   Return the average salary of employees excluding the minimum and maximum
 *   salary.
 *
 *----------------------------------------------------------------------------
 */

double
average(int *salary, int salarySize)
{
    int    min = salary[0];
    int    max = salary[0];
    double sum = (double) min;

    for (int i = 1; i < salarySize; i++) {
        sum += salary[i];
        if (salary[i] < min) {
            min = salary[i];
        } else if (salary[i] > max) {
            max = salary[i];
        }
    }

    sum -= (min + max);
    return sum / (salarySize - 2);
}
