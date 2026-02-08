#include <bits/stdc++.h>
using namespace std;

/*
Problem: House Robber
LeetCode Link: https://leetcode.com/problems/house-robber/
Difficulty: 🟡 Medium
Tags: DP, Memoization
Technique: Top-Down Recursion (with Memoization)

Guiding Questions:
- At each house, should I rob it or skip it?
- If I rob a house, why can I not rob the next one?
- How can previously solved subproblems help reduce repeated computation?

Main Idea / Approach:
- For each index, we have two choices:
    1) Skip the current house → move to `indx + 1`
    2) Rob the current house → add its money and move to `indx + 2`
- We move to `indx + 2` after robbing because adjacent houses cannot both be robbed.
- Recursively compute the best result and store it in `dp[indx]`.
- Memoization ensures each state is solved only once.

Time Complexity: O(n)
Space Complexity: O(n) for memoization and recursion stack
*/

class Solution {
public:
    vector<int> dp;

    int findMaxProfit(int indx, vector<int>&nums) {
        if (indx >= nums.size()) return 0;
        auto& ans = dp[indx];
        if (ans != -1) return ans;

        ans = findMaxProfit(indx + 1, nums);
        ans = max(ans, nums[indx] + findMaxProfit(indx + 2, nums));

        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return findMaxProfit(0, nums);
    }
};