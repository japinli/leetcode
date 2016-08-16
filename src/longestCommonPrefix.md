[14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
===========================

原题
----

Write a function to find the longest common prefix string amongest an
array of strings.

题意
----

编写一个函数用于查找字符串数组中的最长公共前缀。

思路
----

若字符串数组长度等于`0`，那么最长公共前缀为`""`；若字符串数组长度等于
`1`，那么最长公共前缀为该字符串；以第一个字符串为基准，遍历该字符串的
每个字符，并与字符串数组中的其他字符串的对应索引的字符进行比较，若字索
引大于等于字符串长度，或对应索引的字符不想等则返回当前的最长公共前缀字
符串，若全相等则将该字符加入到最长公共前缀字符串中。若字符数组大小为
`m`，字符平均长度为`n`那么该算法的时间复杂度为`O(m * n)`。

代码
----

```
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		} else if (strs.size() == 1) {
			return strs[0];
		}
		
		string prefix;
		for (size_t i = 0; i < strs[0].length(); ++i) {
			char p = strs[0][i];
			for (size_t j = 1; j < strs.size(); ++j) {
				if (i >= strs[j].length() || p != strs[j][i]) {
					return prefix;
				}
			}
			
			prefix.push_back(p);
		}
		
		return prefix;
	}
};
```
