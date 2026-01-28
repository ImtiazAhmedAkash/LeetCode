#include <bits/stdc++.h>
using namespace std;

/*
Problem: Valid Anagram
LeetCode Link: https://leetcode.com/problems/valid-anagram/
Difficulty: 🟢 Easy
Tags: String, Array
Technique: Frequency Counting

Guiding Questions:
- How can I verify whether two strings contain the same characters?
- Can character counts help instead of sorting?
- Since the alphabet size is fixed, can I use constant extra space?

Main Idea / Approach:
- If the lengths of the two strings differ, they cannot be anagrams.
- Use a fixed-size array of size 26 to count character frequencies.
- Increment counts for characters in the first string.
- Decrement counts for characters in the second string.
- If all counts are zero at the end, the strings are anagrams.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (char c : t) {
            cnt[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) return false;
        }

        return true;
    }
};
