[28. Implement strStr()](https://leetcode.com/problems/implement-strstr/)
========================

原题
----

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1
if needle is not part of haystack.

思路
----

1. 暴力算法。首先从 haystack 和 needle 的初始位置开始从左向右匹配，若
   匹配失败移动到 haystack 的下一位置重新匹配。
2. KMP算法，参考[The Knuth-Morris-Pratt Algorithm in my own words][]。

代码
----

思路1示例代码

```c++
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size();
		int len2 = needle.size();
		
		for (int i = 0; i <= len1 - len2; ++i) {
			if (isSame(&haystack[i], needle.c_str(), len2)) {
				return i;
			}
		}
		
		return -1;
	}
	
	bool isSame(const char *p1, const char *p2, size_t len) {
		while (*p1 && *p2 && len) {
			if (*p1 != *p2) {
				return false;
			}
			p1++, p2++, len--;
		}
		return true;
	}
};
```

思路2示例代码
```c++
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size();
		int len2 = needle.size();
		
		if (len2 == 0) {
			return 0;
		}
		
		int pmt[len2+1];
		int i, j;
		
		i = 0;
		pmt[0] = j = -1;
		while (i < len2) {
			while (j > -1 && needle[i] != needle[j]) {
				j = pmt[j];
			}
			i++, j++;
			if (needle[i] == needle[j]) {
				pmt[i] = pmt[j];
			} else {
				pmt[i] = j;
			}
		}
		
		i = j = 0;
		while (j < len1) {
			while (i > -1 && needle[i] != haystack[j]) {
				i = pmt[i];
			}
			
			i++, j++;
			if (i >= len2) {
				return j - i;
			}
		}
		
		return -1;
	}	
};
```


[The Knuth-Morris-Pratt Algorithm in my own words]: http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
