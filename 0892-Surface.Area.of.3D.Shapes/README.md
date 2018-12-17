# 892. Surface Area of 3D Shapes

On a `N * N` grid, we place some `1 * 1 * 1` cubes.

Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of
grid cell `(i, j)`.

Return the total surface area of the resulting shapes.

__Example 1:__

```
Input: [[2]]
Output: 10
```

__Example 2:__

```
Input: [[1,2],[3,4]]
Output: 34
```

__Example 3:__

```
Input: [[1,0],[0,2]]
Output: 16
```

__Example 4:__

```
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
```

__Example 5:__

```
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
```

__Note:__

* `1 <= N <= 50`
* `0 <= grid[i][j] <= 50`
