[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
===================================================

原题
----

Given a string, find the length of the **longest substring** without
repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note
that the answer must be a **substring**, `"pwke"` is a *subsequence*
and not a substring.

题意
----

给定一个字符串，找出没有重复字符的**最长子串**的长度。

**示例：**

给定字符串`"abcabcbb"`，答案是长度为`3`的`"abc"`子串。

给定字符串`"bbbbb"`，答案是长度为`1`的`"b"`子串。

给定字符串`"pwwkew"`，答案是长度为`3`的`"wke"`子串。注意返回的结果是必
须是**子串**的长度，`"pwke"`是*子序列*而不是子串。

思路
----

1. 最简单也是最容易想到的就是遍历字符串，然后判断所有的子串判断是否有
   重复元素，并记录最大长度。但是该算法时间复杂度为O(n^2)。LeetCode提
   交超时。
2. 从上面的思路可以看到，要解决该问题可分解为两个小问题：

   1. 查找该元素是否已出现；
   2. 重置起点，更新最大子串长度。
   
   由于当有重复的字符出现时，新的起点应设置为该字符前一次出现的后一位
   置。因此，起点的位置能够很好的设置，那么如何能快速的知道当前的字符
   是否已经出现？考虑到字符的范围区间，可以采用数组进行标记，这样可以
   在常数时间内获得结果。

代码
----

思路1示例代码（超时）
```C++
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) {
			return 0;
		}
		
		string::size_type maxLen = 0;
		string::size_type start = 0;
		string::size_type i;
		
		for (i = 1; i < s.size(); ++i) {
			string::size_type j;
			for (j = start; j < i; ++j) {
				if (s[j] == s[i]) {
					maxLen = maxLen > i - start ? maxLen : i - start;
					start++;
					i = start;
				}
			}
		}
		
		return maxLen > i - start ? maxLen : i - start;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.length();
		if (length == 0 || length == 1) {
			return length;
		}
		
		vector<int> flags(256, -1);
		int i = 0, maxLen = 0;

		for (int j = 0; j < length; ++j) {
			if (flags[s[j]] >= i) {
				i = flags[s[j]] + 1;
			}
			
			flags[s[j]] = j;
			maxLen = maxLen > j - i + 1 ? maxLen : j - i + 1;
		}
		
		return maxLen;
	}
};
```
