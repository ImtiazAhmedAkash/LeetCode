#include <bits/stdc++.h>
using namespace std;

/*
Problem: Binary Number with Alternating Bits
LeetCode Link: https://leetcode.com/problems/binary-number-with-alternating-bits/
Difficulty: 🟢 Easy
Tags: BitManipulation
Techniques: XOR Pattern + All Ones Check

Guiding Questions:
- What pattern appears if we compare a number with itself shifted right by one bit?
- How can we detect that all bits of a number are 1?
- Can we verify alternating bits without checking each bit individually?

Main Idea / Approach:
- For an alternating bit number:
      n      = 101010...
      n >> 1 = 010101...

- XORing them:
      x = n ^ (n >> 1)
  produces a number consisting entirely of 1s.

- Example:
      10 (1010₂)
      5  (0101₂)
      XOR → 1111₂

- A number made of only 1s has a special property:
      x & (x + 1) == 0
  because adding 1 carries through all bits and clears them.

- Therefore:
      1) Create x = n ^ (n >> 1)
      2) Check if x is all 1s using (x & (x + 1)) == 0

- If true → n has alternating bits.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
