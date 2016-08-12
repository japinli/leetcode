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
3. Manacher算法，思路2中的算法针对回文串长度的奇偶性需要分别计算，
   Manacher算法则在进行回文查找前先对其进行预处理，统一了回文长度奇偶
   两种情况。例如，字符串`"aba", "abba"`经预处理后分别变为`"#a#b#a#",
   "#a#b#b#a#"`。该算法中还涉及一个回文半径的概念，即回文中心到回文最
   左端/右端的距离。针对字符串`"abaaba"`运用该算法如下：
   
   ```
   PREPROCESS RESULT: # a # b # a # a # b # a # 
   PALINDROME RADIUS: 1 2 1 3 1 2 7 2 1 3 1 2 1
   ```
   
   从上面可以看出`PALINDROME RADIUS[i] - 1`即是原字符串的回文长度。因
   此该问题转化为求解`PALINDROME RADIUS`数组。该算法使用了连个辅助变量
   用于计算`PALINDROME RADIUS`数组。一个记录当前最大的回文半径变量
   `maxR`以及其对应的中心点的位置`maxO`。当计算`i`处的回文半径时，分两
   种情况：
   
   1. `i < maxR`：此时由于区间`[0, i-1]`的回文半径以经确定，且当前字符
      位于最长回文半径内，因此由对称性可知，当`maxO + maxR - i >
      PALINDROME RADIUS[2 * maxR - i]`时，此时回文半径为`PALINDROME
      RADIUS[2 * maxR - i]`；若`maxO + maxR - i < PALINDROME
      RADIUS[2 * maxR - i]`说明此时`i`右侧的字符不足以构成`2 * maxR -
      i`处的回文序列，因此回文半径为`maxo + maxR - i`。
   2. `i > maxR`：此时，由于没有可用信息，因此只能向两边扩展来找出可能
      的回文半径。
	  
  处理完上述两种情况后，还需要对其进行扩展，以判断是否存在更长的回文串。
  详细说明请看[这里](http://blog.csdn.net/japinli/article/details/52195212)。


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

思路3示例代码（Manacher's Algorithm）
```C++
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len <= 1) {
			return s;
		}
		
		string str = preprocess(s);
		vector<int> radiuses(str.length());
		int maxRadius = 0, maxPoint = 0;
		
		len = str.length();
		for (int i = 1; i < len; ++i) {
			if (maxRadius > i) {
				radiuses[i] = maxRadius + maxPoint - i > radiuses[2 * maxPoint - i] ? maxRadius + maxPoint - i : radiuses[2 * maxPoint - i];
			} else {
				radiuses[i] = 1;
			}
			
			while (str[i - radiuses[i]] == str[i + radiuses[i]]) {
				radiuses[i]++;
			}
			
			if (radiuses[i] > maxRadius) {
				maxRadius = radiuses[i];
				maxPoint = i;
			}
		}
		
		len = radiuses[maxPoint] - 1;
		int start = maxPoint - len;
		string result;
		while (len--) {
			result.push_back(str[start + 1]);
			start += 2;
		}
		
		return result;
	}
	
private:
	string preprocess(const string& s) {
		string result("$#");
		
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			result.push_back(s[i]);
			result.push_back('#');
		}
		
		return result;
	}
};
```
