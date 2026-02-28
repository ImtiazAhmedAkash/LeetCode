#include <bits/stdc++.h>
using namespace std;

/*
Problem: Concatenation of Consecutive Binary Numbers
LeetCode Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
Difficulty: 🟡 Medium
Tags: Math, BitManipulation
Techniques: Bit Length Growth

Guiding Questions:
- How many bits does a number contribute when appended in binary?
- When does the bit-length of numbers increase?
- How can we append a number in binary form efficiently?

Main Idea / Approach:
- We need to concatenate binary representations of numbers from 1 to n.
- Appending a binary number is equivalent to:
      Shift left by its bit length
      Then OR with the number.

- Instead of computing bit-length every time,
  we observe that bit-length increases only when
  the number is a power of two.

- A number is a power of two if:
      (i & (i - 1)) == 0

- Each time we encounter a power of two,
  we increment `bits`.

- Then:
      result = (result << bits) | i

- Since values grow quickly,
  we take modulo (1e9 + 7) at each step.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    const int mod = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long result = 0;
        int bits = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) 
                bits++;

            result = ((result << bits) | i) % mod;
        }

        return result;
    }
};
