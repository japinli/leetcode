# 1022. Sum of Root To Leaf Binary Numbers

You are given the `root` of a binary tree where each node has a value
`0` or `1`.  Each root-to-leaf path represents a binary number starting
with the most significant bit.  For example, if the path is
`0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary,
which is `13`.

For all leaves in the tree, consider the numbers represented by the path
from the root to that leaf.

Return the sum of these numbers. The answer is __guaranteed__ to fit in
a __32-bits__ integer.

__Example 1:__

```
                1
			   / \
		     0     1
		    / \   / \
		   0   1 0   1

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

__Example 2:__

```
Input: root = [0]
Output: 0
```

__Example 3:__

```
Input: root = [1]
Output: 1
```

__Example 4:__

```
Input: root = [1,1]
Output: 3
```

__Constraints:__

* The number of nodes in the tree is in the range `[1, 1000]`.
* `Node.val` is `0` or `1`.

