# 872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the
values of those leaves form a __leaf value sequence__.

![](./images/leaf_similar_trees_1.png)

For example, in the given tree above, the leaf value sequence is
`(6, 7, 4, 9, 8)`.

Two binary trees are considered _leaf-similar_ if their leaf value
sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1`
and `root2` are leaf-similar.

__Example 1:__


![](./images/leaf_similar_trees_2.jpeg)

```
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
```

__Example 2:__

```
Input: root1 = [1], root2 = [1]
Output: true
```

__Example 3:__

```
Input: root1 = [1], root2 = [2]
Output: false
```

__Example 4:__

```
Input: root1 = [1,2], root2 = [2,2]
Output: true
```

__Example 5:__

![](./images/leaf_similar_trees_3.jpeg)

```
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

__Constraints:__

* The number of nodes in each tree will be in the range `[1, 200]`.
* Both of the given trees will have values in the range `[0, 200]`.