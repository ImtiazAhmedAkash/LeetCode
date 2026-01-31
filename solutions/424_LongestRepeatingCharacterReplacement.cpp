#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Repeating Character Replacement
LeetCode Link: https://leetcode.com/problems/longest-repeating-character-replacement/
Difficulty: 🟡 Medium
Tags: SlidingWindow, Hashing
Technique: Sliding Window (Frequency Tracking)

Guiding Questions:
- How can I maintain a valid window with at most k replacements?
- Why do we track the most frequent character inside the window?
- When should the left pointer move to shrink the window?

Main Idea / Approach:
- Use a sliding window with two pointers (l, r).
- Maintain a frequency array to count characters inside the window.
- Track maxCnt, the frequency of the most common character in the window.
- The number of replacements needed is:
    window_size - maxCnt
- If replacements exceed k, shrink the window from the left.
- Keep updating the maximum window size that satisfies the condition.

Time Complexity: O(n)
Space Complexity: O(1) since the frequency array size is fixed (26 letters).
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int maxCnt = 0;
        int ans = 0;

        int n = s.size();
        for (int l = 0, r = 0; r < n; r++) {
            cnt[s[r] - 'A']++;
            maxCnt = max(maxCnt, cnt[s[r] - 'A']);

            while ((r - l + 1 - maxCnt) > k) {
                cnt[s[l] - 'A']--;
                maxCnt = *max_element(cnt.begin(), cnt.end());
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};