#include <bits/stdc++.h>
using namespace std;

/*
Problem: Contiguous Array
LeetCode Link: https://leetcode.com/problems/contiguous-array/
Difficulty: 🟡 Medium
Tags: Array, PrefixSum, HashTable
Techniques: Prefix Sum Hashing

Guiding Questions:
- How can equal number of 0s and 1s be detected efficiently?
- Can the problem be transformed into a sum-based problem?
- When does a prefix sum indicate a valid subarray?

Main Idea / Approach:
- Transform the array by treating 1 as +1 and 0 as -1.  
  Now, the problem reduces to finding the longest subarray with sum = 0.
- Maintain a prefix sum `sum` while iterating through the array.
- Use a HashTable to store the first occurrence of each prefix sum:
    - Initialize `prefix[0] = -1` to handle subarrays starting at index 0.
- For each index i:
    - Update `sum += (nums[i] == 1 ? 1 : -1)`.
    - If `sum` has been seen before at index j:
        - The subarray `(j+1 .. i)` has equal number of 0s and 1s.
        - Update `maxLen = max(maxLen, i - j)`.
    - If `sum` has not been seen before:
        - Store `sum` with the current index in the HashTable.

- By storing first occurrences, we ensure that each repeated prefix sum gives the **longest possible subarray** for that sum.
- Return the maximum length found.

Time Complexity: O(n)
- Single traversal of the array; HashTable operations are O(1) on average.

Space Complexity: O(n)
- HashTable stores prefix sums and their first occurrence indices.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> pref;
        pref[0] = -1;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) sum++;
            else sum--;

            if (pref.count(sum)) {
                maxLen = max(maxLen, i - pref[sum]);
            }
            else {
                pref[sum] = i;
            }
        }

        return maxLen;
    }
};