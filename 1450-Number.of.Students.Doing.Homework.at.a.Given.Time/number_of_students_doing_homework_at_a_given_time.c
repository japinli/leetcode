/*----------------------------------------------------------------------------
 *
 * number_of_students_doing_homework_at_a_given_time.c
 *   Given two integer arrays `startTime` and `endTime` and given an
 *   integer `queryTime`.
 *
 *   The `ith` student started doing their homework at the time
 *   `startTime[i]` and finished it at time `endTime[i]`.
 *
 *   Return _the number of students_ doing their homework at time
 *   `queryTime``. More formally, return the number of students where
 *   `queryTime` lays in the interval `[startTime[i], endTime[i]]`
 *   inclusive.
 *
 *----------------------------------------------------------------------------
 */

int
busyStudent(int *startTime, int startTimeSize, int *endTime, int endTimeSize,
            int queryTime)
{
    int count = 0;

    (void) endTimeSize;

    for (int i = 0; i < startTimeSize; i++) {
        if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
            count++;
        }
    }

    return count;
}
