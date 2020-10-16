# 1518. Water Bottles

Given `numBottles` full water bottles, you can exchange `numExchange`
empty water bottles for one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Return the __maximum__ number of water bottles you can drink.

__Example 1:__

![](../images/water_bottles.png)

```
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
```

__Example 2:__

```
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
```

__Example 3:__

```
Input: numBottles = 5, numExchange = 5
Output: 6
```

__Example 4:__

```
Input: numBottles = 2, numExchange = 3
Output: 2
```

__Constraints:__

* `1 <= numBottles <= 100`
* `2 <= numExchange <= 100`
