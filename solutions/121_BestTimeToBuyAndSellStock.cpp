#include <bits/stdc++.h>
using namespace std;

/*
Problem: Best Time to Buy and Sell Stock
LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: 🟢 Easy
Tags: Array, Greedy
Technique: Single Pass (Track Min & Max)

Guiding Questions:
- How can I find the maximum profit without checking every pair of days?
- How do I track the minimum price seen so far efficiently?
- How do I update the maximum profit at each step?

Main Idea / Approach:
- Initialize minPrice to INT_MAX and maxProfit to 0.
- Traverse the prices array once:
    - Update maxProfit as the difference between current price and minPrice.
    - Update minPrice if the current price is lower.
- Return maxProfit at the end.

Time Complexity: O(n), single pass through the array
Space Complexity: O(1), only constant extra variables
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (auto x : prices) {
            maxProfit = max(maxProfit, x - minPrice);
            minPrice = min(minPrice, x);
        }

        return maxProfit;
    }
};