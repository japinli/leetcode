[295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
===================================

原题
----

Median is the middle value in an ordered integer list. If the size of
the list is even, there is no middle value. So the median is the mean
of the two middle value.

Examples:

`[2,3,4]`, the median is `3`.

`[2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Design a data structure that supports the following two operations:

* void addNum(int num) - Add a integer number from the data stream to
 the data structure.
* double findMedian() - Return the median of all elements so far.

For example:
```
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
```

题意
----

中位数是处于有序整数链表中间位置的数。如果链表的大小为偶数，则它没有中
间的值，中位数就是处于中间位置的两个数的平均值。

示例：

`[2,3,4]`, 中位数是 `3`.

`[2,3]`, 中位数是 `(2 + 3) / 2 = 2.5`.

设计一个数据结构支持下面两种操作：

* void addNum(int num) - 从数据流中添加一个整数到该数据结构中。
* double findMedian() - 返回现阶段所有元素的中位数.

示例:
```
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
```

思路
----

1. 在插入数据时保证链表是有序的，同时注意到每次添加元素时，只需要保证
新加入的元素是有序的即可，因此时间复杂度为`O(n)`。
2. 参考LeetCode上[mightyvoice][]的思想，利用两个优先级队列进行。一个优
先级队列用于保存小于等于中位数的值，该队列中的元素个数大于等于所有元素
的一半，并且该优先级队列使用大根堆存放数据。另一个优先级队列则使用小根
堆存放数据，并且所有元素的值大于中位数的值。保证两个优先级的元素个数相
等或大根堆的个数比小根堆的个数多一个，这样做有利于中位数的获取。

代码
----

思路1示例代码
```c++
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        array_.push_back(num);
	size_t len = array_.size();
	if (len == 1) {
	    return;
	}

        len--;     /* Point the last element. */
	while (--len && num < array_[len]) {
	    array_[len + 1] = array_[len];
	}
	
	array_[len] = num;	
    }
    // Returns the median of current data stream
    double findMedian() {
        size_t len = array_.size();
	if (len & 0x01) {   /* Odd element(s) */
	    return array_[len >> 1];
	}
	
	/* Even elemets */
	size_t mid = len >> 1;
	return (array_[mid] + array_[mid - 1]) / 2.0;
    }
private:
    vector<int> array_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
```

思路2示例代码
```c++
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (left_.empty()) {
	    left_.push(num);
	    return;
	}
        int leftSize = left_.size();
	int rightSize = right_.size();
	if (leftSize == rightSize) {
	    int tmp = right_.top();
	    if (tmp >= num) {
	        left_.push(num);
	    } else {
                left_.push(tmp);
		right_.pop();
		right_.push(num);
	    }
	} else {
            int tmp = left_.top();
	    if (tmp > num) {
	        right_.push(tmp);
		left_.pop();
		left_.push(num);
	    } else {
                right_.push(num);
	    }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (left_.size() == right_.size()) {
	    return (left_.top() + right_.top()) / 2.0;
	}

        return left_.top();
    }
private:
    priority_queue<int> left_;
    priority_queue<int, vector<int>, greater<int> > right_;
	
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
```

[mightyvoice]: https://discuss.leetcode.com/topic/53398/easy-to-understand-c-solution-beats-97