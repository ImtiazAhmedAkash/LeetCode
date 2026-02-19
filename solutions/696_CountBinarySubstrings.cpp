#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Binary Substrings
LeetCode Link: https://leetcode.com/problems/count-binary-substrings/
Difficulty: 🟢 Easy
Tags: String, TwoPointers
Techniques: Consecutive Group Counting

Guiding Questions:
- What makes a substring valid?
- Do we need to check every substring explicitly?
- Can we represent the string in a more compressed way?

Main Idea / Approach:
- A valid substring must have:
    equal number of 0s and 1s
    AND they must be grouped consecutively.
  Examples:
      "01", "10", "0011", "1100"

- Notice an important observation:
  We do NOT actually care about the full substring.
  We only care about the sizes of consecutive groups.

  Example:
      s = "001110011"
      Groups: 2, 3, 2, 2

- Any valid substring is formed ONLY between two adjacent groups.
  The number of valid substrings between them is:
      min(previous_group_length, current_group_length)

  Why?
  Because the smaller group limits how many equal pairs we can form.

  Example:
      "00111"
      groups = 2 and 3
      Valid substrings:
          "01"
          "0011"
      → total = 2 = min(2,3)

- So instead of checking substrings:
    1. Count the size of each consecutive block.
    2. Add min(lastBlock, currentBlock) to the answer.

- We only store:
      prevCnt  → previous group size
      curCnt   → current group size

- This turns an O(n²) brute force problem into O(n).

Time Complexity: O(n) — single pass through string
Space Complexity: O(1) — only counters used
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int total = 0;
        int prevCnt = 0;
        
        for (int i = 0; i < n; i++) {
            int curCnt = 0;
            int j = i;
            while (j < n && s[i] == s[j]) {
                j++;
                curCnt++;
            }
            total += min(prevCnt, curCnt);
            prevCnt = curCnt;
            i = j - 1;
        }
        
        return total;
    }
};
