[58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
=========================

原题
----

Given a string *s* consists of upper/lower-case alphabets and empty
space characters `' '`, return the length of last word in the string.

If the last word does not exist, return 0.

**Note:** A word is defined as a character sequence consists of
non-space characters only.

For example,

Given *s* = `"Hello World"`,

return `5`.

思路
----

1. 分两步进行：a.跳过末尾的空白字符；b.从后向前统计非空白字符的个数。
2. 思路1采用从后往前的计算。我们也可以采用由前往后计算，分三步进行：
   a.跳过所有空白字符；b.统计非空白字符的长度；c.若出现空白字符，将长
   度置为0，跳转到(a)。

代码
----

思路1示例代码
```c++
class Solution {
public:
	int lengthOfLastWord(string s) {
		int lastWordLength = 0;
		int index = s.length() - 1;
		
		while (s[index] == ' ') {
			index--;
		}
		
		while (index >= 0 && s[index] != ' ') {
			index--;
			lastWordLength++;
		}
		
		return lastWordLength;
	}
};
```

思路2示例代码
```
class Solution {
public:
	int lengthOfLastWord(string s) {
		int lastWordLength = 0;
		int index = 0;
		
		while (index < s.length()) {
			if (s[index++] != ' ') {
				lastWordLength++;
			} else if (index < s.length() && s[index] != ' ') {
				lastWordLength = 0;
			}
		}
		
		return lastWordLength;
	}
};
```
