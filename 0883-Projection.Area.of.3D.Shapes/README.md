# 883. Projection Area of 3D Shapes

On a `N * N` grid, we place some `1 * 1 * 1` cubes that are axis-aligned with
the `x`, `y`, and `z` axes.

Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of
grid cell `(i, j)`.

Now we view the _projection_ of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2
dimensional plane.

Here, we are viewing the "shadow" when looking at the cubes from the top, the
front, and the side.

Return the total area of all three projections.

__Example 1:__

```
Input: [[2]]
Output: 5
```

__Example 2:__

```
Input: [[1,2],[3,4]]
Output: 17
```

__Example 3:__

```
Input: [[1,0],[0,2]]
Output: 8
```

__Example 4:__

```
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 14
```

__Example 5:__

```
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 21
```

__Note:__

1. `1 <= grid.length = grid[0].length <= 50`
2. `0 <= grid[i][j] <= 50`
