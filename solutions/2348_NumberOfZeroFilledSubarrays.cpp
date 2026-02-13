#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Zero-Filled Subarrays
LeetCode Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/
Difficulty: 🟡 Medium
Tags: Array, Math, Counting
Techniques: Contribution Counting

Guiding Questions:
- How many subarrays end at the current index?
- What happens when we extend a streak of zeros?
- Can we count subarrays without explicitly generating them?

Main Idea / Approach:
- We scan the array from left to right and track consecutive zeros.
- Let cnt = length of the current continuous zero segment.
- If nums[i] == 0:
      increment cnt
      every new zero creates new subarrays ending at index i.
- Why?
  If a zero streak has length k, then the number of zero-only subarrays
  ending at the current position equals k:
        [0]
        [0,0]
        [0,0,0]
        ...
  So we add cnt to the answer.
- If nums[i] != 0:
      the streak breaks → reset cnt = 0.
- This implicitly computes:
        1 + 2 + 3 + ... + k
  for every zero segment without explicitly calculating the formula.

Time Complexity: O(n)
- Single pass through the array.

Space Complexity: O(1)
- Only constant variables used.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
                total += cnt;
            }
            else {
                cnt = 0;
            }
        }

        return total;
    }
};