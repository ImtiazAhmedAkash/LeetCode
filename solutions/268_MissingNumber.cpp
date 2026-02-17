#include <bits/stdc++.h>
using namespace std;

/*
Problem: Missing Number
LeetCode Link: https://leetcode.com/problems/missing-number/
Difficulty: 🟢 Easy
Tags: BitManipulation, Math
Techniques: XOR Cancellation Trick

Guiding Questions:
- How can we find the missing value without sorting or extra memory?
- Is there an operation where identical values eliminate each other?
- Can we combine indices and values into a single computation?

Main Idea / Approach:
- The array contains numbers from 0 to n with exactly one number missing.
- XOR has two very useful properties:
      a ^ a = 0        (same numbers cancel)
      a ^ 0 = a
      XOR is commutative and associative (order doesn't matter)

- If we XOR all numbers from 1 to n and also XOR all elements in the array:
      every number that appears in both places cancels out.

- Only the missing number remains because it appears in the range [0…n]
  but not inside the array.

- So:
      missing = (1 ^ 2 ^ 3 ^ ... ^ n) ^ (nums[0] ^ nums[1] ^ ...)

- After all cancellations, the remaining value is exactly the missing number.

Time Complexity: O(n) — single pass over numbers
Space Complexity: O(1) — no extra memory used
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int Xor = 0;
        for (int i = 1; i <= n; i++) {
            Xor ^= i;
        }

        for (auto &x : nums) {
            Xor ^= x;
        }

        return Xor;
    }
};