#include <bits/stdc++.h>
using namespace std;

/*
Problem: Reverse Bits
LeetCode Link: https://leetcode.com/problems/reverse-bits/
Difficulty: 🟢 Easy
Tags: BitManipulation
Techniques: Bit Mirroring, Bitwise Operations

Guiding Questions:
- How can we access individual bits of a number?
- Where should each bit go after reversing?
- Can we construct the reversed number bit by bit?

Main Idea / Approach:
- A 32-bit integer has bits indexed from 0 to 31.
- Reversing bits means:
    bit at position i → moves to position (31 - i).
- We iterate through all 32 bit positions.
- For each bit:
    - Check whether the i-th bit of n is set using:
        (n & (1u << i))
    - If it is set, then we set the corresponding mirrored bit
      in the result at position (31 - i).
- We build the final number gradually by turning on bits in `result`.

- `1u` is important:
  Using unsigned shifting avoids undefined behavior when shifting
  into the sign bit (especially at bit 31).

Time Complexity: O(32) ≈ O(1)
- Always processes exactly 32 bits.

Space Complexity: O(1)
- Only a few variables are used.
*/

class Solution {
public:
    int reverseBits(int n) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            if (n & (1u << bit)) {
                result |= (1u << (31 - bit));
            }
        }

        return result;
    }
};
