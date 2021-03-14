# 1694. Reformat Phone Number

You are given a phone number as a string `number`. `number` consists of
digits, spaces `' '`, and/or dashes `'-'`.

You would like to reformat the phone number in a certain manner.
Firstly, __remove__ all spaces and dashes. Then, __group__ the digits
from left to right into blocks of length 3 __until__ there are 4 or
fewer digits. The final digits are then grouped as follows:

* 2 digits: A single block of length 2.
* 3 digits: A single block of length 3.
* 4 digits: Two blocks of length 2 each.

The blocks are then joined by dashes. Notice that the reformatting
process should __never__ produce any blocks of length 1 and produce
__at most__ two blocks of length 2.

Return _the phone number after formatting_.


__Example 1:__

```
Input: number = "1-23-45 6"
Output: "123-456"
Explanation: The digits are "123456".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 3 digits remaining, so put them in a single block of length 3. The 2nd block is "456".
Joining the blocks gives "123-456".
```

__Example 2:__

```
Input: number = "123 4-567"
Output: "123-45-67"
Explanation: The digits are "1234567".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 4 digits left, so split them into two blocks of length 2. The blocks are "45" and "67".
Joining the blocks gives "123-45-67".
```

__Example 3:__

```
Input: number = "123 4-5678"
Output: "123-456-78"
Explanation: The digits are "12345678".
Step 1: The 1st block is "123".
Step 2: The 2nd block is "456".
Step 3: There are 2 digits left, so put them in a single block of length 2. The 3rd block is "78".
Joining the blocks gives "123-456-78".
```

__Example 4:__

```
Input: number = "12"
Output: "12"
```

__Example 5:__

```
Input: number = "--17-5 229 35-39475 "
Output: "175-229-353-94-75"
```

__Constraints:__

* `2 <= number.length <= 100`
* `number` consists of digits and the characters `'-'` and `' '`.
* There are at least __two__ digits in `number`.

__Hints__

* Discard all the spaces and dashes.
* Use a while loop. While the string still has digits, check its length
  and see which rule to apply.
