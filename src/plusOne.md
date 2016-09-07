[66. Plus One](https://leetcode.com/problems/plus-one/)
==============

原题
-----

Given a non-negative number represented as an array of digits, plus
one to the number.

The digits are stored such that the most significant digit is at the
head of the list.


思路
-----

从最后一位相加，依次将进位值追加到高位。

代码
----

```C++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int carry = 1; /* plus one */
	for (int i = digits.size() - 1; i >= 0; --i) {
	    int tmp = digits[i] + carry;
	    digits[i] = tmp % 10;
	    carry = tmp / 10;
	}
	
	if (carry) {
	    digits.insert(digits.begin(), carry);
	}
	
	return digits;
    }
};
```