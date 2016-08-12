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
3. *Manacher*算法，该算法利用`O(n)`的辅助空间，将时间复杂度将到了
   `O(n)`。该算法首先通过预处理将上述方法二中的需要针对奇偶长度进行计
   算统一起来，其次它充分利用了回文的特性通过动态规划的思想避免了不必
   要的计算。
   
1. 预处理：在该阶段，它为每个字符两端插入一个特殊的字符，通常使用
   `'#'`字符。如下所示：

	primitive: "adcabacdef"
	processed: "#a#d#c#a#b#a#c#d#e#f#"
	primitive: "abbad"
	processed: "#a#b#b#a#d#"
	
	因此，无论原始字符串长度是为奇数还是偶数，经预处理之后其长度均为奇
    数。这样就避免了考虑偶数的情况。由于在类C语言中字符串末尾包含
    `'\0'`字符，因此通常还会在字符串的开始加入一个特殊字符`'$'`避免越
    界。
	
2. 分析： 首先我们先定义回文半径，回文半径即从回文中心点到回文最左边或
   最右边的距离。例如上面的示例中，我们可以计算每个字符的回文半径，如
   下所示：

	primitive:  "adcabacdef"
	processed:  # a # d # c # a # b # a # c # d # e # f #
	radiuses[-]:   1 2 1 2 1 2 1 2 1 8 1 2 1 2 1 2 1 3 1 2 1
	
	上述中的空格是为了显示而加上的，*rediuses*数组中的`'-'`字符同样是
    为了显示效果而加上的。可以看出`radiuses[i] - 1`既是原字符串中回文
    串的长度。这其实是可以证明的。
	
	证明：
	1. 首先有$L=2 * radiuses[i] - 1$为新串中以`processed[i]`为中心的回
       文串的长度。
	2. 以`processed[i]`为中心的回文串一定是以`'#'`字符开始和结尾的，因
       此，当`L`减去回文串最前（或最后）的`'#'`字符后，其长度正好是原
       字符串的两倍，即$(L-1)/2$，将$L$代入化解即得$radiuses[i] - 1$。
	
3. 因此只要计算出预处理后字符串的回文半径数组就可以求出回文字符串了。
*Manacher*算法在计算回文半径是利用到了动态规划的思路。它利用两个辅助变
量`max_right`和`max_index`来计算`radiuses`数组。其中`max_right`代表预
处理串中最大的回文字符串的最右边位置，`max_index`则代表回文字符串的中
心索引位置（该算法也可以只使用一个`max_index`辅助变量）。步骤如下：

	1. `i < max_right`意味着当前字符处于最大回文半径范围内，因此可以利
       用回文的特性找到其以`max_index`为中心的对称点（`max\_index -
       (i - max_index) = 2 * max_index - i`）的回文半径，避免重复计算。
	   
       1. 若对称点的回文半径小于`max_right - i`，说明以字符
          `processed[i]`为中的回文半径等于其对称点的回文半径。
	   2. 若对称点的回文半径大于等于$max\_right - i$，说明该点的回文
           半径至少为`max_right - i`。此时还需要利用中心扩展法进行探测。
		   
	2. `i >= max_right`意味着需要重新以中心扩展的方式计算回文半径。

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
		string str = preprocess(s);
		int len = str.length();		
		vector<int> radiuses(len);
		int max_right = 0, max_index = 0;
		
		for (int i = 0; i < len; ++i) {
			/* core code */
			if (max_right > i) {
				radiuses[i] = max_right - i < radiuses[2 * max_index - i] ? max_right - i : radiuses[2 * max_index - i];
   			} else {
				radiuses[i] = 1;
			}
			
			while (str[i - radiuses[i]] == str[i + radiuses[i]]) {
				radiuses[i]++;
			}
			
			if (max_right - max_index < radiuses[i]) {
				max_index = i;
				max_right = i + radiuses[i];
			}
		}
		
		len = radiuses[max_index] - 1;
		int start = max_index - len;
		string result;
		while (len--) {
			result.push_back(str[start + 1]); /* skip '#' */
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
