#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Palindromic Substring
LeetCode Link: https://leetcode.com/problems/longest-palindromic-substring/
Difficulty: 🟡 Medium
Tags: String, DP, Memoization
Technique: Palindrome DP on Substrings (Top-Down DP)

Guiding Questions:
- When is a substring a palindrome?
- Can I reuse results of smaller substrings?
- How can I check palindromes without recomputing repeatedly?

Main Idea / Approach:
- A substring s[i…j] is a palindrome if:
      s[i] == s[j] AND s[i+1…j-1] is also a palindrome.
- Use recursion with memoization to store whether each substring is a palindrome.
- Base case: if i >= j, the substring has length 0 or 1, so it is always a palindrome.
- Check all substrings and keep track of the longest valid palindrome.
- Memoization prevents recomputation and ensures each state is evaluated once.

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

        ans = 0;
        if (s[i] == s[j]) {
            ans = max(ans, isPalindrome(i + 1, j - 1, s));
        }

        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        int start = 0, len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n ;j++) {
                if (isPalindrome(i, j, s) && len < j - i + 1) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, len);
    }
};