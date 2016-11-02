[391. Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/)
========================

原题
----

Given N axis-aligned rectangles where N > 0, determine if they all
together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right
point. For example, a unit square is represented as
[1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right
point is (2, 2)).

**Example 1:**

```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true, All 5 rectangles together form an exact cover of a rectangular region.
```

![perfect rectangle](../images/rectangle_perfect.gif)

**Example 2:**

```
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.
```

![rectangle separated](../images/rectangle_separated.gif)

**Example 3:**

```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.
```

![rectangle hole](../images/rectangle_hole.gif)

**Example 4:**

```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
```

![rectangle intersect](../images/rectangle_intersect.gif)

思路
----

1. 根据题意可知，最后形成的矩形面积应与原矩形面积的和相同。此外最后的
   矩形与原矩形的点要么出现一次，要么出现偶数次，且仅有四点出现一次。
   
代码
----

思路1示例代码

```C++
class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		size_t len = rectangles.size();
		if (len <= 1) {
			return true;
		}
		
		set<string> points;
		int min_x = INT_MAX;
		int min_y = INT_MAX;
		int max_x = INT_MIN;
		int max_y = INT_MIN;
		int eara = 0;
		
		for (size_t i = 0; i < len; ++i) {
			vector<int> tmp = rectangles[i];
			min_x = min(min_x, tmp[1]);
			min_y = min(min_y, tmp[0]);
			max_x = max(max_x, tmp[3]);
			max_y = max(max_y, tmp[2]);
			
			string p1 = to_string(tmp[1]) + "_" + to_string(tmp[0]);
			string p2 = to_string(tmp[1]) + "_" + to_string(tmp[2]);
			string p3 = to_string(tmp[3]) + "_" + to_string(tmp[0]);
			string p4 = to_string(tmp[3]) + "_" + to_string(tmp[2]);
			
			if (points.count(p1)) { points.erase(p1); } else { points.insert(p1); }
			if (points.count(p2)) { points.erase(p2); } else { points.insert(p2); }
			if (points.count(p3)) { points.erase(p3); } else { points.insert(p3); }
			if (points.count(p4)) { points.erase(p4); } else { points.insert(p4); }
			
			eara += (tmp[3] - tmp[1]) * (tmp[2] - tmp[0]);
		}
		
		string p1 = to_string(min_x) + "_" + to_string(min_y);
		string p2 = to_string(min_x) + "_" + to_string(max_y);
		string p3 = to_string(max_x) + "_" + to_string(min_y);
		string p4 = to_string(max_x) + "_" + to_string(max_y);
		
		if (points.size() != 4 || !points.count(p1) || !points.count(p2) ||
		    !points.count(p3) || !points.count(p4))
		{
			return false;
		}
		
		return eara == (max_x - min_x) * (max_y - min_y);
	}
};
```
