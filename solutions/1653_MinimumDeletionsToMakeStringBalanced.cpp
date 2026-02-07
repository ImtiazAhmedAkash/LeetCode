#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Deletions to Make String Balanced
LeetCode Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
Difficulty: 🟡 Medium
Tags: String, PrefixSum
Technique: Prefix-Suffix Cut Minimization

Guiding Questions:
- What does a "balanced" string actually look like?
- Can I choose a partition point that separates 'a' and 'b'?
- For each position, how many characters must be removed?

Main Idea / Approach:
- A balanced string has all 'a' before all 'b' (aaaa...bbbb).
- Think of placing a cut at every position of the string.
    Left side  → should contain only 'a'
    Right side → should contain only 'b'
- Therefore:
    - On the left, delete every 'b'
    - On the right, delete every 'a'
- Maintain:
    prefB → number of 'b' seen so far (left side)
    suffA → number of 'a' remaining (right side)
- Initially, the cut is before the string:
    deleting all 'a' (suffA) is one valid answer.
- As we scan:
    - If we see 'a', it leaves the suffix → suffA--
    - If we see 'b', it enters the prefix → prefB++
- At each step compute:
    deletions = prefB + suffA
- The minimum deletions across all cut points is the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int suffA = count(s.begin(), s.end(), 'a');
        int prefB = 0;
        int minDelete = suffA;

        for (auto &c : s) {
            if (c == 'a') suffA--;
            else prefB++;
            minDelete = min(minDelete, prefB + suffA);
        }

        return minDelete;
    }
};