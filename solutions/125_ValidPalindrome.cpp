#include <bits/stdc++.h>
using namespace std;

/*
Problem: Valid Palindrome
LeetCode Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: 🟢 Easy
Tags: String, TwoPointers
Technique: Filter & Two-Pointer Check

Guiding Questions:
- Which characters should be considered valid?
- Should uppercase and lowercase letters be treated the same?
- What is the simplest way to compare characters from both ends?

Main Idea / Approach:
- Ignore all non-alphanumeric characters.
- Convert all letters to lowercase to ensure case-insensitive comparison.
- Store the filtered characters in a new string.
- Use two pointers (start & end) to check if the string is a palindrome.

Time Complexity: O(n)
- One pass to filter characters
- One pass to check palindrome

Space Complexity: O(n)
- Extra string used to store filtered characters
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (auto &c : s) {
            if (isalpha(c)) {
                t += tolower(c);
            } else if (isdigit(c)) {
                t += c;
            }
        }

        int n = t.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (t[i] != t[j]) return false;
        }

        return true;
    }
};
