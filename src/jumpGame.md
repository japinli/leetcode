[55. Jump Game](https://leetcode.com/problems/jump-game/)

原题
----

Given an array of non-negative integers, you are initially positioned
at the first index of the array.

Each element in the array represents your maximum jump length at that
position.

Determine if you are able to reach the last index.

For example:

A = `[2, 3, 1, 1, 4]`, return `true`.

A = `[3, 2, 1, 0, 4]`, return `false`.

思路
----

1. 从左到右依次跳，每次最多跳`A[i]`步，当然也能跳`0`或`1`步，若能到达
   最右端或超过最右端，返回`true`。
   
代码
----

思路1示例代码

```C++
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int max_step = 1;
		
		for (int i = 0; i < max_step && max_step < nums.size(); i++) {
			max_step = max(max_step, i + 1 + nums[i]);
		}
		
		return max_step >= nums.size();
	}
};
```
