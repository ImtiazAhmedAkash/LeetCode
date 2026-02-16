#include <bits/stdc++.h>
using namespace std;

/*
Problem: Unique Paths
LeetCode Link: https://leetcode.com/problems/unique-paths/
Difficulty: 🟡 Medium
Tags: DP, Combinatorics
Techniques: Grid DP (Rolling Array)

Guiding Questions:
- From any cell, how many ways can we reach it?
- What are the only possible moves in the grid?
- Can we avoid storing the full 2D DP table?

Main Idea / Approach:
- The robot can only move:
    1) Right
    2) Down
- Therefore, the number of ways to reach a cell (i, j)
  equals the sum of:
    ways from top cell (i-1, j)
    +
    ways from left cell (i, j-1)
- So, dp[i][j] = dp[i-1][j] + dp[i][j-1]
- First row and first column always have exactly 1 path
  because the robot can only move in one direction.

Space Optimization:
- Instead of a 2D grid, we store only one row:
    dp[j] = ways to reach column j in the previous row
- For the current row we build `newDp`:
    newDp[j] = dp[j] (from top)
             + newDp[j-1] (from left)
- After processing a row, replace dp with newDp.
- The last cell dp[n-1] contains the total number of paths.

Time Complexity: O(m * n)
- Every cell is computed once.

Space Complexity: O(n)
- Only one row is stored at any time.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            vector<int> newDp(n, 0);
            for (int j = 0; j < n; j++) {
                newDp[j] += dp[j];
                if (j - 1 >= 0) newDp[j] += newDp[j - 1];
            }
            dp = newDp;
        }

        return dp[n - 1];
    }
};