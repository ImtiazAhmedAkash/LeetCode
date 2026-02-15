#include <bits/stdc++.h>
using namespace std;

/*
Problem: Add Binary
LeetCode Link: https://leetcode.com/problems/add-binary/
Difficulty: 🟢 Easy
Tags: String, Math, Simulation
Techniques: Bit-by-Bit Addition (Carry Handling)

Guiding Questions:
- How do we manually add binary numbers?
- How should we handle different string lengths?
- How do we propagate the carry?

Main Idea / Approach:
- This problem is identical to manual addition we do on paper,
  but performed in base 2 instead of base 10.
- We process the strings from right to left (least significant bit first).
- Maintain a variable `carry`.
At each step:
    sum = carry
    + current bit from string a (if exists)
    + current bit from string b (if exists)
- The resulting bit becomes:
      sum % 2
- The carry becomes:
      sum / 2
- Continue until both strings are processed AND carry becomes 0.
- We append digits while moving from right → left, so the result is reversed.
- Reverse the string at the end to obtain the final binary number.

Time Complexity: O(max(n, m)) — traverse both strings once
Space Complexity: O(max(n, m)) — result string
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            carry = sum / 2;
            result += ('0' + (sum % 2));
        }

        reverse(result.begin(), result.end());

        return result;
    }
};