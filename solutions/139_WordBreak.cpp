#include <bits/stdc++.h>
using namespace std;

/*
Problem: Word Break
LeetCode Link: https://leetcode.com/problems/word-break/
Difficulty: 🟡 Medium
Tags: String, DP, Recursion
Techniques: Memoized Recursion (String Partitioning)

Guiding Questions:
- Can the string be split into valid dictionary words?
- Where should we try to partition the string?
- How can we avoid recomputing the same index multiple times?

Main Idea / Approach:
- We want to check whether the string can be segmented into words from the dictionary.
- Define dp[i] as:
      whether the substring starting from index i can be segmented.
- Use recursion starting from index 0.
- At position `indx`, try every word in the dictionary:
    - If the word matches the substring starting at indx,
      we recursively check the remaining part of the string.
- If any recursive call succeeds, the current index is also valid.
- Memoization is used so each index is solved only once.
  dp[indx] stores:
      1 → segmentation possible
      0 → not possible
- Base case:
      If indx reaches the end of the string, segmentation succeeded.
- This converts an exponential recursion into linear DP over indices.

Time Complexity: O(n * m * L)
- n = string length
- m = number of words
- L = average word length (substring comparison)

Space Complexity: O(n) — dp array + recursion stack
*/

class Solution {
public:
    int isPossible(int indx, string& s, vector<string>& wordDict, vector<int>& dp) {
        if (indx == s.size()) return 1;
        auto& ans = dp[indx];
        if (ans != -1) return ans;

        ans = 0;
        for (auto &word : wordDict) {
            int len = word.size();
            if (indx + len <= s.size() && s.substr(indx, len) == word) {
                ans = max(ans, isPossible(indx + len, s, wordDict, dp));
            }
        }

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return isPossible(0, s, wordDict, dp);
    }
};