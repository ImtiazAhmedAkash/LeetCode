#include <bits/stdc++.h>
using namespace std;

/*
Problem: Palindromic Substrings
LeetCode Link: https://leetcode.com/problems/palindromic-substrings/
Difficulty: 🟡 Medium
Tags: String, DP, Memoization
Technique: Palindrome DP on Substrings (Top-Down DP)

Guiding Questions:
- How can I check if a substring is a palindrome efficiently?
- Can I reuse results from smaller substrings?
- How can I count all palindromic substrings without recomputing?

Main Idea / Approach:
- A substring s[i…j] is a palindrome if:
      s[i] == s[j] AND s[i+1…j-1] is also a palindrome.
- Use recursion with memoization to store whether each substring is a palindrome.
- Base case: if i >= j, the substring has length 0 or 1, so it is always a palindrome.
- Iterate through all substrings (i ≤ j) and add 1 to the answer if the substring is a palindrome.
- Memoization ensures each state is computed only once.

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

class Solution {
public:
    vector<vector<int>> dp;

    int isPalindrome(int i, int j, string& s) {
        if (i >= j) return 1;
        auto& ans = dp[i][j];
        if (ans != -1) return ans;

        ans = (s[i] == s[j] && isPalindrome(i + 1, j - 1, s));

        return ans;
    }

    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += isPalindrome(i, j, s);
            }
        }

        return ans;
    }
};