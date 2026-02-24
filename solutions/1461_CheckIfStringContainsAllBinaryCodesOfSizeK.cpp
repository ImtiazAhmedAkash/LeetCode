#include <bits/stdc++.h>
using namespace std;

/*
Problem: Check If a String Contains All Binary Codes of Size K
LeetCode Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
Difficulty: 🟡 Medium

Tags: String, BitManipulation, SlidingWindow
Techniques: Rolling Bitmask

Guiding Questions:
- How many binary strings of length k are possible?
- Can we represent a binary substring as an integer?
- How do we efficiently slide a window while maintaining its numeric value?

Main Idea / Approach:
- There are exactly 2^k possible binary strings of length k.
- If total substrings of length k (n - k + 1) is less than 2^k,
  it is impossible to contain all codes → early return false.

- We use a rolling bitmask technique:
    - Maintain an integer `cur` representing the current window.
    - For each character:
        1) Multiply `cur` by 2
        2) Add current bit (if '1')

- When window size reaches k:
    - `cur` now represents a k-length binary substring.
    - Mark it as seen.
    - If this pattern is new, increase counter.
    - Remove the leftmost bit contribution before sliding window.

- Instead of using a hash set,
  we use vector<bool> of size 2^k for O(1) marking.

- Finally, if number of distinct patterns found == 2^k,
  return true.

Time Complexity: O(n)
Space Complexity: O(2^k)
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n - k + 1 < (1 << k)) return false;
        
        vector<bool> seen(1 << k, false);

        int cur = 0;
        int found = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cur *= 2;
            if (s[r] == '1') cur++;

            if (r - l + 1 == k) {
                if (!seen[cur]) {
                    seen[cur] = true;
                    found++;
                }
                if (s[l] == '1') cur -= (1 << (k - 1));
                l++;
            }
        }

        return found == (1 << k);
    }
};