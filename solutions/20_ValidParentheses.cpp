#include <bits/stdc++.h>
using namespace std;

/*
Problem: Valid Parentheses
LeetCode Link: https://leetcode.com/problems/valid-parentheses/
Difficulty: 🟢 Easy
Tags: Stack, String
Technique: Stack (Bracket Matching)

Guiding Questions:
- How can I ensure every closing bracket matches the most recent opening one?
- What should I do if a closing bracket appears with no opening bracket?
- How do I verify that all brackets are properly closed at the end?

Main Idea / Approach:
- Use a stack to track opening brackets.
- Traverse the string character by character.
- Push opening brackets '(' '{' '[' onto the stack.
- For a closing bracket:
    - If the stack is empty → invalid string.
    - If the top of the stack does not match the closing bracket → invalid.
    - Otherwise, pop the matching opening bracket.
- After processing all characters, the stack must be empty for the string to be valid.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
                continue;
            }

            if (stk.empty()) return false;
            if (stk.top() != '(' && c == ')') return false;
            if (stk.top() != '{' && c == '}') return false;
            if (stk.top() != '[' && c == ']') return false;
            stk.pop();
        }
        
        return stk.empty();
    }
};