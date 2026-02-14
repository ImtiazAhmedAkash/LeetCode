#include <bits/stdc++.h>
using namespace std;

/*
Problem: Subarray Sum Equals K
LeetCode Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: 🟡 Medium
Tags: Array, PrefixSum, HashTable
Techniques: Prefix Sum Frequency Counting

Guiding Questions:
- How can we check subarray sums efficiently without checking all O(n²) subarrays?
- When does a prefix sum indicate a valid subarray?
- How can previous computations help current positions?

Main Idea / Approach:
- Let prefix sum `sum` represent the sum of elements from index 0 to current index i.
- A subarray (l → i) has sum k if:
      prefix[i] - prefix[l-1] = k
  which means:
      prefix[l-1] = prefix[i] - k
- So, for every position i, we need to know how many times
  the value (sum - k) appeared before.
- Use a HashTable (unordered_map) to store frequency of prefix sums.
    mp[x] = number of times prefix sum x has occurred so far.
- Initialize mp[0] = 1:
    This handles subarrays starting from index 0 whose sum equals k.
- While iterating:
    - Update cumulative sum.
    - If (sum - k) exists in the map, it means a valid subarray ends here.
      Add its frequency to the answer.
    - Then record the current sum in the map.
- This counts all valid subarrays in one pass.

Time Complexity: O(n) — each element processed once, O(1) average map operations
Space Complexity: O(n) — storing prefix sum frequencies
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;

        for (auto &x : nums) {
            sum += x;
            if (mp.count(sum - k)) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }

        return ans;
    }
};