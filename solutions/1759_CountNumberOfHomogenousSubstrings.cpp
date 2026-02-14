#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Number of Homogenous Substrings
Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/
Difficulty: 🟡 Medium
Tags: String, Math, PrefixSum
Techniques: Consecutive Character Contribution

Guiding Questions:
- How can we count substrings formed by consecutive identical characters?
- Do we need to generate all substrings explicitly?
- How can we accumulate contributions efficiently?

Main Idea / Approach:
- A homogenous substring consists of identical consecutive characters.
- For a consecutive block of k identical characters:
    Number of homogenous substrings = 1 + 2 + ... + k
- Initialize `result = 1` because the first character forms a substring of length 1.
- Iterate through the string starting from index 1:
    - Maintain a counter `cnt` for the length of the current block of identical characters.
    - If the current character equals the previous one:
        - Increment cnt.
      Else:
        - Reset cnt = 1.
    - Each character contributes `cnt` new substrings ending at that position.
    - Add cnt to the result and take modulo 1e9+7.
- This efficiently counts all homogenous substrings in one pass.

Time Complexity: O(n) — single pass through the string
Space Complexity: O(1) — only counters used
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.size();
        long long result = 1;
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }

            result += cnt;
            result %= mod;
        }

        return result;
    }
};