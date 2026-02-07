#include <bits/stdc++.h>
using namespace std;

/*
Problem: Climbing Stairs
LeetCode Link: https://leetcode.com/problems/climbing-stairs/
Difficulty: 🟢 Easy
Tags: DP, Memoization
Technique: Count Ways Recurrence

Guiding Questions:
- What does dp[n] represent?
- From which previous steps can I reach step n?
- What should happen when I overshoot the stairs?

Main Idea / Approach:
Let dp[n] represent the number of distinct ways to reach exactly step n.
To reach step n, the last move must be:
- a 1-step jump from step (n-1), or
- a 2-step jump from step (n-2)
Therefore,
        dp[n] = dp[n-1] + dp[n-2]
Base Cases:
- n == 0 → 1 way (already at the starting position)
- n < 0  → 0 ways (invalid path, exceeded the stairs)

We recursively compute dp[n] and store results in a memoization array
so each state is calculated only once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> dp;
    int countWays(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        auto& ans = dp[n];
        if (ans != -1) return ans;

        ans = countWays(n - 1) + countWays(n - 2);

        return ans;
    }

    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return countWays(n);
    }
};