#include <bits/stdc++.h>
using namespace std;

/*
Problem: Coin Change
LeetCode Link: https://leetcode.com/problems/coin-change/
Difficulty: 🟡 Medium
Tags: DP, Recursion, Knapsack
Techniques: Unbounded Knapsack (Minimization) + Memoization

Guiding Questions:
- What is the minimum number of coins needed to make a given amount?
- If I pick a coin, what smaller subproblem remains?
- How can memoization prevent repeated calculations?

Main Idea / Approach:
- Let dp[x] represent the minimum number of coins needed to make amount x.
- We try every coin as the LAST coin used to form the current amount.
- If we choose a coin `c`, the remaining amount becomes (amount - c).
- Recurrence:
      dp[amount] = 1 + min(dp[amount - coin]) for all valid coins
- Base Case:
  - amount == 0 → 0 coins required.

- For every amount, we recursively compute the minimum coins needed
  for smaller amounts and take the best option.
- Since each coin can be used unlimited times, this becomes an
  Unbounded Knapsack problem.
- A large value (inf) represents an impossible state.
- If the final result remains inf, the amount cannot be formed → return -1.

Time Complexity: O(n * amount)
Space Complexity: O(amount) + recursion stack
*/

class Solution {
public:
    vector<int> dp;
    const int inf = 1e9;
    
    int findMinCoin(int amount, vector<int>& coins) {
        if (amount == 0) return 0;

        auto& ans = dp[amount];
        if (ans != -1) return ans;

        ans = inf;
        for (auto &coin : coins) {
            if (amount >= coin) {
                ans = min(ans, 1 + findMinCoin(amount - coin, coins));
            }
        }

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, -1);
        
        int minCoin = findMinCoin(amount, coins);
        return minCoin == inf ? -1 : minCoin;
    }
};