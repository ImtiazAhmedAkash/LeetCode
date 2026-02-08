#include <bits/stdc++.h>
using namespace std;

/*
Problem: House Robber II
LeetCode Link: https://leetcode.com/problems/house-robber-ii/
Difficulty: 🟡 Medium
Tags: DP, Memoization
Technique: Break Cycle into Two Linear DP (Top-Down DP)

Guiding Questions:
- How does the circular arrangement change the original House Robber problem?
- Why can’t the first and last house be robbed together?
- Can I convert the circular problem into linear subproblems?

Main Idea / Approach:
- Houses are arranged in a circle, so the first and last houses are adjacent.
- Therefore, a valid solution cannot include both house 0 and house n-1.
- Split the problem into two independent linear cases:
    1) Rob houses in range [0 … n-2] (include first, exclude last)
    2) Rob houses in range [1 … n-1] (exclude first, allow last)
- Each case becomes the original House Robber I problem.
- Use top-down DP with memoization:
    - For each index, choose between:
        • Skip the current house → move to i+1
        • Rob the current house → gain nums[i] and move to i+2
- The final answer is the maximum of the two cases.

Time Complexity: O(n)
Space Complexity: O(n) (recursion stack + memoization)
*/

class Solution {
public:
    vector<int> dp;

    int findMaxProfit(int indx, int endIndx, vector<int>& nums) {
        if (indx > endIndx) return 0;
        auto& ans = dp[indx];
        if (ans != -1) return ans;

        int skip = findMaxProfit(indx + 1, endIndx, nums);
        int take = nums[indx] + findMaxProfit(indx + 2, endIndx, nums);

        return ans = max(skip, take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        dp.assign(n, -1);
        int maxProfit = findMaxProfit(0, n - 2, nums);
        
        dp.assign(n, -1);
        maxProfit = max(maxProfit, findMaxProfit(1, n - 1, nums));

        return maxProfit;
    }
};