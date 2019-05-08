/*----------------------------------------------------------------------------
 *
 * sum_of_even_numbers_after_queries.cc
 *   We have an array `A` of integers, and an array `queries` of
 *   queries.
 *
 *   For the `i`-th query `val = queries[i][0]`,
 *   `index = queries[i][1]`, we add `val` to `A[index]`. Then, the
 *   answer to the `i`-th query is the sum of the even values of `A`.
 *
 *   _(Here, the given `index = queries[i][1]` is a 0-based index, and
 *   each query permanently modifies the array A.)_
 *
 *   Return the answer to all queries.  Your `answer` array should have
 *   `answer[i]` as the answer to the `i`-th query.
 *
 *----------------------------------------------------------------------------
 */

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> result;
        int sum = 0;
        for (const auto &i : A) {
            if ((i & 0x01) == 0) {
                sum += i;
            }
        }

        for (const auto &item : queries) {
            int val = item[0];
            int idx = item[1];

            if (val & 0x01) {
                if (A[idx] & 0x01) {
                    sum += val + A[idx];
                } else {
                    sum -= A[idx];
                }
            } else {
                if ((A[idx] & 0x01) == 0) {
                    sum += val;
                }
            }

            result.push_back(sum);
            A[idx] += val;
        }

        /* faster than above method
        for (const auto &item : queries) {
            int val = item[0];
            int idx = item[1];

            if ((A[idx] & 0x01) && (val & 0x01)) {
                sum += A[idx] + val;
            } else if (!(A[idx] & 0x01) && !(val & 0x01)) {
                sum += val;
            } else if (!(A[idx] & 0x01) && (val & 0x01)) {
                sum -= A[idx];
            }
            A[idx] += val;
            result.push_back(sum);
        }
         */

        return result;
    }
};
