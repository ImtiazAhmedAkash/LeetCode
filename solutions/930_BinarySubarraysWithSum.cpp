#include <bits/stdc++.h>
using namespace std;

/*
Problem: Binary Subarrays With Sum
LeetCode Link: https://leetcode.com/problems/binary-subarrays-with-sum/
Difficulty: 🟡 Medium
Tags: Array, PrefixSum, HashTable
Techniques: Contribution Counting via Prefix Sum

Guiding Questions:
- How can we count subarrays whose sum equals a target efficiently?
- Can prefix sums help avoid checking all possible subarrays?
- How do we accumulate the number of valid subarrays ending at each index?

Main Idea / Approach:
- Maintain a running prefix sum `sum` while iterating through `nums`.
- Use a HashTable `pref` to store the **count of times each prefix sum has occurred**.
- Initialization:
    - `pref[0] = 1` to handle subarrays starting at index 0.
- For each element `x` in `nums`:
    - Update `sum += x`.
    - If `(sum - goal)` exists in `pref`:
        - There are `pref[sum - goal]` subarrays ending at the current index with total sum = goal.
        - Add that count to `total`.
    - Increment `pref[sum]` by 1.
- This is a **contribution counting** approach:  
  Each prefix sum tracks how many subarrays ending at the current index achieve the target sum.
- Finally, return `total`, the number of valid subarrays.

Time Complexity: O(n)
- Single pass; HashTable operations are O(1) on average.

Space Complexity: O(n)
- HashTable stores counts of prefix sums encountered.
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        int total = 0;
        int sum = 0;
        
        for (auto &x : nums) {
            sum += x;
            if (pref.count(sum - goal)) {
                total += pref[sum - goal];
            }
            pref[sum]++;
        }

        return total;
    }
};