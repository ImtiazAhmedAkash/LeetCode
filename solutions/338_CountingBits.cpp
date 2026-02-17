#include <bits/stdc++.h>
using namespace std;

/*
Problem: Counting Bits
LeetCode Link: https://leetcode.com/problems/counting-bits/
Difficulty: 🟢 Easy
Tags: DP, BitManipulation
Techniques: Bit DP Recurrence

Guiding Questions:
- Can we reuse answers of smaller numbers to compute larger numbers?
- What happens to the number of set bits when we divide a number by 2?
- How does parity (odd/even) affect the number of 1 bits?

Main Idea / Approach:
- Observe the binary behavior of a number when right-shifted:
      i >> 1  → removes the last bit of i
  Example:
      13 = 1101₂
      13 >> 1 = 110₂ (6)
- So we already know the number of set bits of (i >> 1).
- Now check the last bit:
      (i & 1)
      = 1 if number is odd
      = 0 if number is even
Therefore:
      bits(i) = bits(i >> 1) + (i & 1)
Explanation:
- If i is even → last bit is 0 → same bit count as i/2
- If i is odd  → last bit is 1 → one extra set bit
So we compute answers sequentially:
      dp[i] = dp[i >> 1] + (i & 1)
This uses previously computed results, making it a classic bottom-up DP on bits.

Time Complexity: O(n) — each number processed once
Space Complexity: O(n) — dp array
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};
