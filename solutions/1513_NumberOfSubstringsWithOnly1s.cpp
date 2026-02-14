#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Substrings With Only 1s
LeetCode Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/
Difficulty: 🟡 Medium
Tags: String, Math, Prefix Sum
Techniques: Consecutive Ones Contribution

Guiding Questions:
- How many valid substrings end at the current index?
- How does extending a streak of '1's affect the total count?
- Can we count substrings without enumerating them?

Main Idea / Approach:
- We observe that substrings consisting only of '1's come from consecutive blocks of '1's.
- For a block of k consecutive '1's:
    Number of valid substrings = 1 + 2 + ... + k
- While iterating through the string:
    - Maintain a counter `cnt` for the current consecutive '1's.
    - If the current character is '1':
        - Increment cnt.
        - Add cnt to the result, because cnt new substrings end here.
    - If the current character is '0':
        - Reset cnt to 0, since the streak breaks.
- This way, each character contributes directly to the final answer.
- Modulo is applied to keep the result within bounds.

Time Complexity: O(n) — single traversal of the string
Space Complexity: O(1) — only constant extra variables used
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        long long result = 0;
        int cnt = 0;

        for (auto &c : s) {
            if (c == '1') {
                cnt++;
                result += cnt;
                result %= mod;
            }
            else {
                cnt = 0;
            }
        }

        return result;
    }
};