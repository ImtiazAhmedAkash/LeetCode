#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Removals to Balance Array
LeetCode Link: https://leetcode.com/problems/minimum-removals-to-balance-array/
Difficulty: 🟡 Medium
Tags: TwoPointers, SlidingWindow, Sorting
Technique: Sliding Window on Sorted Array

Guiding Questions:
- Can rearranging (sorting) the array make the balancing condition easier to check?
- After sorting, how can I identify the largest subarray that already satisfies the condition?
- Can I maintain a valid range using two pointers?
- How does maximizing a valid subarray minimize removals?

Main Idea / Approach:
- Sort the array so that the balancing condition becomes monotonic.
- A subarray [l, r] is valid if `nums[r] <= nums[l] * k`.
- Use two pointers to maintain the longest valid window:
    - Expand `r` to include new elements.
    - Shrink `l` when the condition is violated.
- Track the maximum length of any valid window.
- The minimum removals required is:
      total elements − maximum valid window length.

Time Complexity: O(n log n)
- Sorting takes O(n log n)
- Sliding window runs in O(n)

Space Complexity: O(1) (excluding sort space)
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxBalancedLen = 0;
        for (int l = 0, r = 0; r < n; r++) {
            while (1LL * nums[l] * k < nums[r]) {
                l++;
            }
            maxBalancedLen = max(maxBalancedLen, r - l + 1);
        }

        return n - maxBalancedLen;
    }
};