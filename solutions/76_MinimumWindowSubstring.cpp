#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Window Substring
LeetCode Link: https://leetcode.com/problems/minimum-window-substring/
Difficulty: 🔴 Hard
Tags: SlidingWindow, Hashing
Technique: Sliding Window (Frequency Tracking)

Guiding Questions:
- How can I track the counts of required characters efficiently?
- How do I know when a current window satisfies all required characters?
- When should the left pointer move to shrink the window while keeping it valid?

Main Idea / Approach:
- Maintain two arrays of size 128:
    - needCnt: counts of each character required by t
    - curCnt: counts of characters in the current window
- Keep track of:
    - required = number of unique characters needed
    - found = number of unique characters currently satisfied in the window
- Expand the window by moving the right pointer, updating curCnt and found.
- Shrink the window from the left while found == required to find minimum length.
- Update the start and minLength whenever a smaller valid window is found.
- Return the substring starting at 'start' with length 'minLength' (or "" if no window found).

Time Complexity: O(n), each character is visited at most twice
Space Complexity: O(1), fixed-size arrays of 128 elements
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m) return "";
        
        vector<int> needCnt(128, 0);
        for (auto &c : t) {
            needCnt[c]++;
        }

        int required = 0;
        for (auto x : needCnt) {
            if (x > 0) required++;
        }

        int start = 0;
        int minLength = INT_MAX;
        int found = 0;
        vector<int> curCnt(128, 0);
        for (int l = 0, r = 0; r < n; r++) {
            curCnt[s[r]]++;
            if (needCnt[s[r]] > 0 && curCnt[s[r]] == needCnt[s[r]]) found++;

            while (required == found) {
                if (r - l + 1 < minLength) {
                    start = l;
                    minLength = r - l + 1;
                }
                curCnt[s[l]]--;
                if (needCnt[s[l]] > 0 && curCnt[s[l]] == needCnt[s[l]] - 1) found--;
                l++;
            }
        }

        if (minLength == INT_MAX) return "";
        return s.substr(start, minLength);
    }
};