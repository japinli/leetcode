# 463. Island Perimeter

You are given `row x col grid` representing a map where `grid[i][j] = 1`
represents land and `grid[i][j] = 0` represents water.

Grid cells are connected __horizontally/vertically__ (not diagonally).
The `grid` is completely surrounded by water, and there is exactly one
island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected
to the water around the island. One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100. Determine the
perimeter of the island.

__Example 1:__

```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

__Example 2:__

```
Input: grid = [[1]]
Output: 4
```

__Example 3:__

```
Input: grid = [[1,0]]
Output: 4
```

__Constraints:__

* `row == grid.length`
* `col == grid[i].length`
* `1 <= row, col <= 100`
* `grid[i][j]` is `0` or `1`.
