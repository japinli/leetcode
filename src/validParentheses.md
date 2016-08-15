[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
=======================

原题
----

Given a string containing just the characters `'('`, `')'`, `'{'`,
`'}'`, `'['` and `']'`, determine if the input string is valid.

The brackets must close in the correct order, `"()"` and `"()[]{}"`
are all valid but `"(]"` and `"([)]` are not.

题意
----

给定一个只包含 `'('`, `')'`, `'{'`, `'}'`, `'['` 和 `']'`字符的字符串，
判断输入的字符串是否有效。

括号必须以正确的顺序闭合，例如`"()"`和`"()[]{}"`是有效的，但是`"(]"`和
`"([)]`是无效的。

思路
----

典型的栈应用。

代码
----

```c++
class Solution {
public:
	bool isValid(string s) {
		stack<char> brackets;
		
		for (size_t i = 0; i < s.length(); ++i) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{':
				brackets.push(s[i]);
				break;
				
			case ')':
				if (brackets.empty() || brackets.top() != '(') {
					return false;
				}
				brackets.pop();
				break;
			
			case ']':
				if (brackets.empty() || brackets.top() != '[') {
					return false;
				}
				brackets.pop();
				break;
				
			case '}':
				if (brackets.empty() || brackets.top() != '{') {
					return false;
				}
				brackets.pop();
				break;
				
			default:
				return false;
			}
		}
		
		return brackets.empty();
	}
};
```
