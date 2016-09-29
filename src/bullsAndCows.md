[299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)
=====================

原题
----

You are playing the following Bulls and Cows game with your friend:
You write down a number and ask your friend to guess what the number
is. Each time your friend makes a guess, you provide a hint that
indicates how many digits in said guess match your secret number
exactly in both digit and position (called "bulls") and how many
digits match the secret number but locate in the wrong position
(called "cows"). Your friend will use successive guesses and hints to
eventually derive the secret number.

For example:

```
Secret number:  "1807"
Friend's guess: "7810"
```

Hint: `1` bull and `3` cows. (The bull is `8`, the cows are `0`, `1`
and `7`.)

Write a function to return a hint according to the secret number and
friend's guess, use A to indicate the bulls and B to indicate the
cows. In the above example, your function should return `"1A3B"`.

Please note that both secret number and friend's guess may contain
duplicate digits, for example:

```
Secret number:  "1123"
Friend's guess: "0111"
```

In this case, the 1st `1` in friend's guess is a bull, the 2nd or 3rd `1`
is a cow, and your function should return `"1A1B"`.

You may assume that the secret number and your friend's guess only
contain digits, and their lengths are always equal.


思路
----

1. 遍历两个字符串，若相等且序号相同则将`bull`加`1`。关键在于计算`cows`，
   为了计算`cows`，我们可以利用两个数组分别保存`secret`和`guess`字符串
   中数字出现的次数，并在遍历过程中判断数字是否同时出现在`secret`和
   `guess`两个字符串中。
   
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	string getHint(string secret, string guess) {
		vector<int> secretFlags(10, 0);
		vector<int> guessFlags(10, 0);
		
		int bull = 0, cows = 0;
		for (size_t i = 0; i < secret.length(); ++i) {
			int s = secret[i] - '0';
			int g = guess[i] - '0';
			
			if (s == g) {
				bull++;
			} else {
				if (secretFlags[g]) {
					secretFlags[g]--;
					cows++;
				} else {
					guessFlags[g]++;
				}
				
				if (guessFlags[s]) {
					guessFlags[s]--;
					cows++;
				} else {
					secretFlags[s]++;
				}
			}
		}
		
		stringstream format;
		format <<bull <<"A" <<cows <<"B";
		return format.str();
	}
};
```
