#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Balanced Substring I
LeetCode Link: https://leetcode.com/problems/longest-balanced-substring-i/
Difficulty: 🟡 Medium
Tags: String, Array, Frequency, BruteForce
Techniques: Equal Frequency Invariant (distinct × freq = length)

Guiding Questions:
- What does a "balanced" substring mean?
- Do we need to compare all character frequencies every step?
- Can the equal-frequency requirement be checked mathematically instead?

Main Idea / Approach:
- A substring is balanced if every character present appears the SAME number of times.
- Fix a starting index i and extend the substring to the right (j).
- Maintain:
    -  freq[26] → frequency of each character
    -  distinct → number of unique characters currently present
    -  maxCnt   → highest frequency of any character
- Before processing each new starting index:
    -  reset the frequency array using fill().
- When adding a character:
    -  if its frequency becomes 1 → increase distinct
    -  update maxCnt

- Suppose there are d distinct characters and each appears k times.
- Then substring length must be: length = d × k
- Therefore instead of checking all 26 frequencies explicitly, 
  verify: distinct * maxCnt == current substring length
- If the condition holds, all characters must share the same frequency,
  so the substring is balanced and we update the maximum length.

Time Complexity: O(n²)
- Two nested loops over the string.

Space Complexity: O(26) → constant extra space
*/

class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        int n = s.size();
        vector<int> freq(26);

        for (int i = 0; i < n; i++) {
            fill(freq.begin(), freq.end(), 0);
            int distinct = 0;
            int maxCnt = 0;
            
            for (int j = i; j < n; j++) {
                int c = s[j] - 'a';
                freq[c]++;
                if (freq[c] == 1) distinct++;
                maxCnt = max(maxCnt, freq[c]);

                if (distinct * maxCnt == j - i + 1) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};