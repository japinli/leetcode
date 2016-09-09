[67. Add Binary](https://leetcode.com/problems/add-binary/)

原题
----

Given two binary strings, return their sum (also a binary string).

For example,

a = `"11"`

b = `"1"`

Return `"100"`

思路
----

此题的解法与*[Plus One][]*和*[Add Two Numbers][]*类似。


代码
----

```c++
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int len1 = a.size();
		int len2 = b.size();
		int carry = 0;
		
		while (len1 > 0 || len2 > 0) {
			carry += len1 > 0 ? a[--len1] - '0' : 0;
			carry += len2 > 0 ? b[--len2] - '0' : 0;
			result = char(carry % 2 + '0') + result;
			carry /= 2;
		}
		
		if (carry) {
			result = '1' + result;
		}
		
		return result;
	}
};
```

[Plus One]: plusOne.md
[Add Two Numbers]: addTwoNumbers.md
