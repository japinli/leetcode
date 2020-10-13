# 1598. Crawler Log Folder

The Leetcode file system keeps a log each time some user performs a
change folder operation.

The operations are described below:

* `"../"`: Move to the parent folder of the current folder. (If you are
  already in the main folder, __remain in the same folder__).
* `"./"`: Remain in the same folder.
* `"x/"`: Move to the child folder named `x` (This folder is
  __guaranteed to always exist__).

You are given a list of strings `logs` where `logs[i]` is the operation
performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in `logs`
are performed.

Return the minimum number of operations needed to go back to the main
folder after the change folder operations.

__Example 1:__

![](../images/crawler_log_folder_1.png)

```
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```

__Example 2:__

![](../images/crawler_log_folder_2.png)

```
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```

__Example 3:__

```
Input: logs = ["d1/","../","../","../"]
Output: 0
```

__Constraints:__

* `1 <= logs.length <= 103`
* `2 <= logs[i].length <= 10`
* `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.
* `logs[i]` follows the format described in the statement.
* Folder names consist of lowercase English letters and digits.
