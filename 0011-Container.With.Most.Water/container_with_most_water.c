/*----------------------------------------------------------------------------
 *
 * container_with_most_water.c
 *   Given `n` non-negative integers `a1, a2, ..., an`, where each represents
 *   a point at coordinate `(i, ai)`. `n` vertical lines are drawn such that
 *   the two endpoints of line `i` is at `(i, ai)` and `(i, 0)`. Find two
 *   lines, which together with x-axis forms a container, such that the
 *   container contains the most water.
 *
 *----------------------------------------------------------------------------
 */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#if 0
int
maxArea(int *height, int heightSize)
{
    int max_area = 0;

    for (int i = 0; i < heightSize; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            int h = MIN(height[i], height[j]);
            max_area = MAX(max_area, h * (j - i));
        }
    }
    return max_area;
}
#endif

int
maxArea(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int h = MIN(height[left], height[right]);
        max_area = MAX(max_area, h * (right - left));

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
