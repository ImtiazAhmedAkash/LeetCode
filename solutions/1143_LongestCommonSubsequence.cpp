#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Common Subsequence
LeetCode Link: https://leetcode.com/problems/longest-common-subsequence/
Difficulty: 🟡 Medium

Tags: DP, String
Techniques: Iterative DP

Guiding Questions:
- How can we find the length of the longest common subsequence between two strings?
- Can we break the problem into smaller subproblems based on prefixes of the strings?
- How do we efficiently avoid recomputation of overlapping subproblems?

Main Idea / Approach:
- Use a 2D DP table where dp[i][j] represents the length of LCS between text1[i..] and text2[j..].
- Fill the table iteratively from bottom-right to top-left.
- If text1[i] == text2[j], dp[i][j] = 1 + dp[i+1][j+1].
- Otherwise, dp[i][j] = max(dp[i+1][j], dp[i][j+1]).
- Finally, dp[0][0] contains the length of the LCS.
- This approach avoids recursion and memoization, computing all subproblems iteratively.

Time Complexity: O(n * m) — filling a table of size n x m
Space Complexity: O(n * m) — storing the DP table
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
