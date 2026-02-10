#include <bits/stdc++.h>
using namespace std;

/*
Problem: Decode Ways
LeetCode Link: https://leetcode.com/problems/decode-ways/
Difficulty: 🟡 Medium
Tags: DP, String, Recursion
Techniques: Memoization with 1-step and 2-step transitions

Guiding Questions:
- At a given index, how many decoding choices are possible?
- Can the string be interpreted by moving 1 step or 2 steps forward?
- How can I avoid recomputing the same substring multiple times?

Main Idea / Approach:
- Let dp[i] represent the number of ways to decode the substring starting from index i.
- Use recursion with memoization (top-down DP).
- Base Cases:
  - If we reach the end of the string, a valid decoding path is formed → return 1.
  - If the current character is '0', it cannot be decoded → return 0.
- From each index we have two transitions:
  1) Take one digit:
     - Decode s[i] alone (valid for '1' to '9')
     - Move to index i + 1
  2) Take two digits:
     - Decode s[i..i+1] only if it forms a number from 10 to 26
     - Move to index i + 2
- Total ways from index i = ways(i+1) + ways(i+2) when valid.

Time Complexity: O(n) — each index is solved once
Space Complexity: O(n) — dp array + recursion stack
*/

class Solution {
public:
    vector<int> dp;

    int countWays(int indx, string& s) {
        if (indx == s.size()) return 1;
        if (s[indx] == '0') return 0;

        auto& ways = dp[indx];
        if (ways != -1) return ways;

        int takeOne = countWays(indx + 1, s);

        int takeTwo = 0;
        if (indx + 1 < s.size()) {
            int val = (s[indx] - '0') * 10 + (s[indx + 1] - '0');
            if (10 <= val && val <= 26) {
                takeTwo = countWays(indx + 2, s);
            }
        }

        return ways = takeOne + takeTwo;
    }

    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n, -1);
        return countWays(0, s);
    }
};