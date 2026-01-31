#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Substring Without Repeating Characters
LeetCode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Difficulty: 🟡 Medium
Tags: SlidingWindow, Hashing
Technique: Sliding Window (Frequency Tracking)

Guiding Questions:
- How can I efficiently track repeating characters in the current window?
- How do I shrink the window when a duplicate character appears?
- How do I update the maximum window length during traversal?

Main Idea / Approach:
- Use a sliding window with two pointers: l and r.
- Maintain a count array, cnt to track characters in the current window (size 256 for ASCII).
- Expand the window by moving the right pointer:
    - Increment cnt[s[r]].
- While cnt[s[r]] > 1 (duplicate exists):
    - Shrink the window from the left until all characters are unique.
    - Decrement cnt[s[l]] and move l forward.
- Update maxLength with the current window size (r - l + 1) after each expansion.
- Return maxLength at the end.

Time Complexity: O(n), each character is visited at most twice
Space Complexity: O(1), fixed-size array of 256 elements
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        vector<int> cnt(256);
        int n = s.size();
        
        for (int l = 0, r = 0; r < n; r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 1) {
                cnt[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};