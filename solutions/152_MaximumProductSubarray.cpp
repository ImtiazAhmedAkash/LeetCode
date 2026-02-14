#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Product Subarray
LeetCode Link: https://leetcode.com/problems/maximum-product-subarray/
Difficulty: 🟡 Medium
Tags: Array, DP
Techniques: Kadane Variant (Max-Min Tracking)

Guiding Questions:
- Why doesn't normal Kadane’s algorithm work for products?
- What happens when we multiply by a negative number?
- Why do we need to track both maximum and minimum values?

Main Idea / Approach:
- Unlike sum problems, multiplication behaves differently with negative numbers.
- A negative number can turn a large positive product into a negative one,
  but it can also turn a very small (negative) product into a large positive one.
- Therefore, at every index we must keep:
    maxSoFar → maximum product ending at current index
    minSoFar → minimum product ending at current index
- The minimum is important because multiplying it by a negative number
  may produce the next maximum product.

For each element nums[i]:
    The product ending here can be:
        1) nums[i] alone (start a new subarray)
        2) nums[i] * previous maximum
        3) nums[i] * previous minimum

So:
    maxSoFar = max(nums[i], prevMax * nums[i], prevMin * nums[i])
    minSoFar = min(nums[i], prevMax * nums[i], prevMin * nums[i])

- Update the global answer with maxSoFar after each step.
- This is essentially Kadane’s algorithm adapted for multiplication.

Time Complexity: O(n) — single traversal
Space Complexity: O(1) — constant variables only
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int maxProduct = nums[0];

        for (int i = 1; i < n; i++) {
            int prevMax = maxSoFar;
            int prevMin = minSoFar;

            maxSoFar = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            minSoFar = min({nums[i], prevMax * nums[i], prevMin * nums[i]});
            
            maxProduct = max(maxProduct, maxSoFar);
        }

        return maxProduct;
    }
};