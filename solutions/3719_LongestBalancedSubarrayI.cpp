#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Balanced Subarray I
LeetCode Link: https://leetcode.com/problems/longest-balanced-subarray-i/
Difficulty: 🟡 Medium
Tags: Array, HashTable, BruteForce
Techniques: Distinct Even-Odd Frequency Matching

Guiding Questions:
- What does "balanced" really mean in this problem?
- Are we comparing counts of elements or counts of DISTINCT values?
- How can I efficiently track unique odd and even numbers inside a subarray?

Main Idea / Approach:
- A subarray is balanced if:
      number of DISTINCT even integers == number of DISTINCT odd integers
- We fix a starting index `i` and expand the subarray to the right.
- While expanding, we maintain two sets:
      even → stores unique even numbers
      odd  → stores unique odd numbers
- For every new element:
      if number is odd → insert into odd set
      else → insert into even set
- After each insertion, check:
      if even.size() == odd.size()
      → current subarray is balanced
      → update maximum length
- We check all possible starting points to guarantee the longest subarray.

Time Complexity: O(n²)
- For each starting index, we scan the rest of the array.

Space Complexity: O(n)
- In worst case, the sets can store all elements.
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> even, odd;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) odd.insert(nums[j]);
                else even.insert(nums[j]);

                if (even.size() == odd.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};