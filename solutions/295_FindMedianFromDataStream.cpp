#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Median from Data Stream
LeetCode Link: https://leetcode.com/problems/find-median-from-data-stream/
Difficulty: 🔴 Hard
Tags: Heap, DataStream
Technique: Two Heaps (Balanced Partition)

Guiding Questions:
- How can I maintain the median while numbers arrive one by one?
- Can I split the numbers into two balanced halves?
- How do I ensure quick access to the largest of the left half
  and the smallest of the right half?

Main Idea / Approach:
- Maintain two heaps:
    - `small`: a max-heap storing the smaller half of the numbers
    - `big`: a min-heap storing the larger half of the numbers
- Invariant:
    - Either both heaps have the same size, or
    - `small` has exactly one more element than `big`
- When inserting a number:
    - First push it into `small`
    - Move the largest element of `small` to `big`
    - Rebalance if `big` becomes larger than `small`
- Median retrieval:
    - If sizes are equal, median is the average of both heap tops
    - Otherwise, median is the top of `small`

Time Complexity:
- addNum: O(log n)
- findMedian: O(1)

Space Complexity: O(n)
*/

class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<>> big;

    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        big.push(small.top());
        small.pop();

        if (small.size() < big.size()) {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == big.size()) {
            return (small.top() + big.top()) / 2.0;
        }
        return small.top();
    }
};