# 766. Toeplitz Matrix

A matrix is _Toeplitz_ if every diagonal from top-left to bottom-right has the same element.

Now given an `M x N` matrix, return `True` if and only if the matrix is _Toeplitz_.

__Example 1:__

```
Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```

__Example 2:__

```


Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
```

__Note:__

1. `matrix` will be a 2D array of integers.
2. `matrix` will have a number of rows and columns in range `[1, 20]`.
3. `matrix[i][j]` will be integers in range `[0, 99]`.

__Follow up:__

1. What if the matrix is stored on disk, and the memory is limited such that
   you can only load at most one row of the matrix into the memory at once?
2. What if the matrix is so large that you can only load up a partial row into
   the memory at once?

__Hint 1__

Check whether each value is equal to the value of it's top-left neighbor.
