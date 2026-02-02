#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Consecutive Sequence
LeetCode Link: https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty: 🟡 Medium
Tags: Array, HashTable
Technique: Hash Set + Sequence Start Detection

Guiding Questions:
- How can I identify the start of a consecutive sequence?
- How do I avoid counting the same sequence multiple times?
- How can I ensure linear time complexity?

Main Idea / Approach:
- Insert all elements into an unordered_set for O(1) average lookup.
- A number is considered the start of a sequence if (num - 1) does not exist.
- From each valid start, expand forward to count the length of the sequence.
- Each number is part of exactly one sequence expansion.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }

        int maxConsecutive = 0;
        for (auto num : st) {
            if (st.find(num - 1) == st.end()) {
                int cnt = 0;
                int cur = num;
                while (st.find(cur) != st.end()) {
                    cur++;
                    cnt++;
                }
                maxConsecutive = max(maxConsecutive, cnt);
            }
        }

        return maxConsecutive;
    }
};