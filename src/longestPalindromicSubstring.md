[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
==================================

原题
----

Given a string *S*, find the longest palindromic substring in *S*. You
may assume that the maximum length of *S* is 1000, and there exists
one unique longest palindromic substring.

题意
----

给定字符串*S*，找出*S*中最长的回文子串。你可以假定*S*的最大长度为
`1000`，并且存在唯一的最长回文子串。

思路
----

1. 暴力破解，遍历*S*的所有子串并判断其是否为回文，若是则判断其长度并保
   存最长的字符串。该算法时间复杂度为`O(n^3)`。
2. 中心扩展，遍历*S*的每个字符，以该字符为中点，分别向两端扩展获取回文
   的长度。该算法时间复杂度为`O(n^2)`。需要注意的是回文的长度可能是奇
   数也可能是偶数，因此不要忽略了偶数的情况，即回文串可能是`aba`或
   `abba`这两种情况。

代码
----

思路1示例代码（超时）
```
class Solution {
public:
	string longestPalindrome(string s) {
		size_t len = s.length();
		if (len <= 1) {
			return s;
		}
		
		size_t maxLen = 0;
		char *maxStr = NULL;
		for (size_t i = 0; i < len; i++) {
			for (size_t j = i; j < len; j++) {
				if (isPalindrome(&s[i], j - i + 1)) {
					maxLen = maxLen > j - i + 1 ? maxLen : (maxStr = &s[i], j - i + 1);
				}
			}
		}
		
		return string(maxStr, maxLen);
	}
	
private:
	bool isPalindrome(char *s, size_t n) {
		char *p = s, *q = s + n - 1;
		
		while (p < q) {
			if (*p != *q) {
				return false;
			}
			p++, q--;
		}
		
		return true;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len <= 1) {
			return s;
		}
		string odd, even, longest;
		for (int i = 0; i < len; ++i) {
			odd = expand(s, i, i);
			even = expand(s, i, i + 1);
			if (longest.length() < odd.length()) {
				longest = odd;
			}
			if (longest.length() < even.length()) {
				longest = even;
			}
		}
		
		return longest;
	}
	
private:
	string expand(string s, int l, int r) {
		int len = s.length();
		while (l >= 0 && r < len && s[l] == s[r]) {
			l--, r++;
		}
		
		/* r - l - 1 = (r - 1) - (l + 1) + 1 */
		return s.substr(l + 1, r - l - 1);
	}
};
```
