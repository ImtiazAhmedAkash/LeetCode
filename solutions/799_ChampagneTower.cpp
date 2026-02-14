#include <bits/stdc++.h>
using namespace std;

/*
Problem: Champagne Tower
LeetCode Link: https://leetcode.com/problems/champagne-tower/
Difficulty: 🟡 Medium
Tags: DP, Simulation
Techniques: Row-by-Row Flow Simulation

Guiding Questions:
- How does champagne flow when a glass overfills?
- Do we need to track every glass in the triangle?
- Can we simulate the process row by row instead of building the full pyramid?

Main Idea / Approach:
- Each glass can hold at most 1 cup of champagne.
- If a glass contains more than 1 cup, the excess (overflow) is split equally
  between the two glasses directly below it.
- We simulate the tower row by row using a 1D DP array:
    dp[j] = amount of champagne currently in glass j of the current row.
- Initialize:
    dp filled with `poured` at the top row.
- For each row:
    - Create a new array `tmp` initialized to 0.
    - For every glass j:
        - If dp[j] > 1:
            overflow = dp[j] - 1
            tmp[j]     += overflow / 2
            tmp[j + 1] += overflow / 2
    - Move to next row: dp = tmp
- After reaching `query_row`, the required glass contains dp[query_glass].
- Since a glass cannot exceed capacity, return min(dp[query_glass], 1.0).

Time Complexity: O(query_row²)
- Each row processes up to its index.

Space Complexity: O(query_row)
- Only one row is stored at a time (rolling array).
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 1, poured);

        for (int i = 0; i < query_row; i++) {
            vector<double> tmp(query_row + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (dp[j] > 1) {
                    tmp[j] += (dp[j] - 1) / 2;
                    tmp[j + 1] += (dp[j] - 1) / 2;
                }
            }
            dp = tmp;
        }

        return min(dp[query_glass], 1.00);
    }
};