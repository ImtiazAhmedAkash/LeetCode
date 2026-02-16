#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Increasing Subsequence
LeetCode Link: https://leetcode.com/problems/longest-increasing-subsequence/
Difficulty: 🟡 Medium
Tags: Array, DP, Binary Search
Techniques: Patience Sorting (LIS Optimization)

Guiding Questions:
- Do we really need O(n²) DP comparing every pair?
- What information is enough to extend an increasing subsequence?
- Can we greedily maintain useful candidates for subsequences?

Main Idea / Approach:
- We maintain an array `ends` where:
      ends[i] = the smallest possible ending value of an increasing
                subsequence of length (i + 1).
- While iterating through nums:
    For each number x:
    1) If x is greater than all elements in `ends`,
       it extends the longest subsequence → append it.
    2) Otherwise, find the first element >= x using `lower_bound`
       and replace it with x.
- Why replacement works:
    We are not storing the actual subsequence.
    We are storing the BEST possible tail value.
    A smaller tail value gives more chances to extend the subsequence later.

Example:
    [10, 9, 2, 5, 3, 7, 101, 18]
    ends evolves as:
    [10]
    [9]
    [2]
    [2,5]
    [2,3]
    [2,3,7]
    [2,3,7,101]
    [2,3,7,18]

- The size of `ends` is the length of the Longest Increasing Subsequence.

Time Complexity: O(n log n) — binary search for each element
Space Complexity: O(n) — auxiliary array
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ends;

        for (auto &x : nums) {
            auto it = lower_bound(ends.begin(), ends.end(), x);

            if (it == ends.end()) {
                ends.push_back(x);
            }
            else {
                *it = x;
            }
        }

        return ends.size();
    }
};
