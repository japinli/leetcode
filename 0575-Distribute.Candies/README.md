# 575. Distribute Candies

You have `n` candies, the i-th candy is of type `candies[i]`.

You want to distribute the candies equally between a sister and a
brother so that each of them gets `n / 2` candies (`n` is even). The
sister loves to collect different types of candies, so you want to give
her the maximum number of different types of candies.

Return the maximum number of different types of candies you can give to
the sister.

__Example 1:__

```
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies
for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has
candies [1,2,3], too. 
The sister has three different kinds of candies. 
```

__Example 2:__

```
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother
has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one
kind of candies.
```

__Example 3:__

```
Input: candies = [1,1]
Output: 1
```

__Example 4:__

```
Input: candies = [1,11]
Output: 1
```

__Example 5:__

```
Input: candies = [2,2]
Output: 1
```

__Constraints:__

* `n == candies.length`
* `2 <= n <= 10^4`
* `n` is even.
* `-10^5 <= candies[i] <= 10^5`
