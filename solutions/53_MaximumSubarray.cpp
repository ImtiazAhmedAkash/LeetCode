#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Subarray
LeetCode Link: https://leetcode.com/problems/maximum-subarray/
Difficulty: 🟡 Medium
Tags: Array, DP
Technique: Kadane’s Algorithm

Guiding Questions:
- How can I find the maximum sum of a contiguous subarray efficiently?
- When should I discard a running subarray and start fresh?
- How do I ensure negative values are handled correctly?

Main Idea / Approach:
- Maintain a running sum (curSum) while iterating through the array.
- Add the current element to curSum.
- Update the global maximum (maxSum) at each step.
- If curSum becomes negative, reset it to 0:
    - A negative prefix will only reduce future subarray sums.
- This guarantees that only beneficial subarrays are extended.

Why This Works:
- Any subarray with a negative sum is worse than starting fresh.
- Kadane’s Algorithm dynamically finds the best subarray ending at each index.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for (auto &x : nums) {
            curSum += x;
            maxSum = max(maxSum, curSum);
            curSum = max(0, curSum);
        }
        return maxSum;
    }
};