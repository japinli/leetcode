[8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)
=============================

原题
----

Implement *atoi* to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a
  challenge, please do not see below and ask yourself what are the
  possible input cases.
  
**Notes:** It is intended for this problem to be specified vaguely
  (ie, no given input specs). You are responsible to gather all the
  input requirements up front.
  
题意
----

实现*atoi*函数将字符串转换为整数。

**提示：**

仔细考虑所有可能的输入。如果你想要挑战，那么请不要看下面的内容并想想什
么是可能的输入。

**注意：**

这个问题的是模糊的（即，没有给定输入说明）。你需要处理所有的输入要求。

思路
-----

直接遍历字符串，判断是否数字字符并将其转换为整数。注意整型越界问题。

代码
-----

```c++
class Solution {
public:
	int myAtoi(string str) {
		char *p = (char *)str.c_str();
		
		while (isspace(*p)) { /* ingore the blank space */
			p++;
		}
		
		int negative = 0;
		if (p[0] == '-') {
			negative = 1;
			p++;
		} else if (p[0] == '+') {			
			p++;
		}
		
		long long result = 0;
		
		while (isdigit(*p)) {
			result = result * 10 + (*p - '0');
			if (result > INT_MAX) {   /* overflow */
				return negative ? INT_MIN : INT_MAX;
			}
			p++;
		}
		
		return negative ? -result : result;
	}
};
```
