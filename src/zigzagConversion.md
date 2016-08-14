[6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)
======================

原题
----

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a
given number of rows like this: (you may want to display this pattern
in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make conversion given a number of rows:

```
string convert(string text, int nRows);
```

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

题意
----

将字符串`"PAYPALISHIRING"`按照给定的行数写成如下所示的锯齿形（你可以将
它按照如下的固定形式显示更容易阅读）：

```
P   A   H   N
A P L S I I G
Y   I   R
```

接着一行一行的读取：`"PAHNAPLSIIGYIR"`

编写如下函数，它接收一个字符串并按给定的行数将字符串转化为锯齿形：

```
string convert(string text, int nRows);
```

`convert("PAYPALISHIRING", 3)`函数将返回`"PAHNAPLSIIGYIR"`。

思路
----

1. 遍历字符串，将每个字符放入一个二维数组中，数组按列遍历，最后在按行
   遍历二维数组读取字符形成锯齿形字符串。
2. 参考[xwr1314521][]我们可以按字符串数组下标写出其生成锯齿形的对应关系，如下所示：
   字符串`"abcdefghijklmn", nRows = 3`
   ```
   a   e   i       |  0   4   8
   b d f h k n     |  1 3 5 7 9  11
   c   g   m       |  2   6   10
   ```
   若`nRows=4`
   ```
   a     g     n   | 0     6
   b   f h   m     | 1   5 7    11
   c e   i k       | 2 4   8 10
   d     j         | 3     9
   ```
   从上面可以看出对于字符串，转化为锯齿形后具有如下特征
   ```
   words[0] = 2 * i * (nRows - 1)
   words[1] = 2 * i * (nRows - 1) +/- 1
   words[2] = 2 * i * (nRows - 1) +/- 2
      .                 .
	  .                 .
	  .                 .
   words[n-1] = 2 * i * (nRows - 1) + (n - 1)
   ```
   其中`i`代码列号。
   

代码
----

思路1示例代码
```c++
class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		if (len <= 1 || numRows <= 1) {
			return s;
		}
		
		int inc = 1, row = 0, index = 0;
		vector<char> zigzag[numRows];
		
		while (index < len) {
			zigzag[row].push_back(s[index++]);
			if (row == 0) {
				inc = 1;
			}
			if (row == numRows - 1) {
				inc = -1;
			}
			
			row += inc;
		}
		
		string result;
		for (int i = 0; i < numRows; ++i) {
			string tmp(zigzag[i].begin(), zigzag[i].end());
			result += tmp; 
		}
		
		return result;
	}
};
```

思路2示例代码
```c++
class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		if (len <= 1 || numRows <= 1) {
			return s;
		}
		
		string result;
		int row = 0;
		while (row < numRows) {
			if (row == 0 || row == numRows - 1) {
				int index = 0;
				for (int i = 0; (index = 2 * i * (numRows - 1) + row) < len; i++) {
					result.push_back(s[index]);
				}
			} else {
				int base = 0;
				for (int i = 0; base + row < len || base - row < len; i++, base = 2 * i * (numRows - 1)) {
					if (base - row >= 0 && base - row < len) {
						result.push_back(s[base - row]);
					}
					if (base + row >= 0 && base + row < len) {
						result.push_back(s[base + row]);
					}
				}
			}
			row++;
		}
		
		return result;
	}
};
```

[xwr1314521]: https://discuss.leetcode.com/topic/54012/python-solution-o-n-with-picture-to-understand
