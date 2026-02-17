#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of 1 Bits
LeetCode Link: https://leetcode.com/problems/number-of-1-bits/
Difficulty: 🟢 Easy
Tags: BitManipulation
Techniques: Built-in Popcount

Guiding Questions:
- How can we efficiently count the number of set bits (1s) in an integer?
- Are there built-in functions or bit tricks to simplify the implementation?

Main Idea / Approach:
- Use the built-in function __builtin_popcount(n) to count the number of 1s in the binary representation of n.
- __builtin_popcount is optimized at the compiler level for speed.

Time Complexity: O(1) — constant time for a 32-bit integer
Space Complexity: O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};
