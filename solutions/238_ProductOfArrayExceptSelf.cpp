#include <bits/stdc++.h>
using namespace std;

/*
Problem: Product of Array Except Self
LeetCode Link: https://leetcode.com/problems/product-of-array-except-self/
Difficulty: 🟡 Medium
Tags: Array, PrefixSum
Technique: Prefix & Suffix Product (No Division)

Guiding Questions:
- How can I compute the product of all elements except the current one without using division?
- Can I store partial results directly in the output array?
- How do I ensure correctness when the array contains zero(s)?

Main Idea / Approach:
- For each index i:
    productExceptSelf[i] =
        (product of all elements to the left of i) ×
        (product of all elements to the right of i)
- Compute this efficiently using two passes:
    1. Prefix pass (left to right):
        - ans[i] stores the product of all elements before index i.
    2. Suffix pass (right to left):
        - Multiply ans[i] by the product of all elements after index i.
- The output array itself is reused to store prefix products,
  achieving constant extra space.

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output array)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};