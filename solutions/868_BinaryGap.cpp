#include <bits/stdc++.h>
using namespace std;

/*
Problem: Binary Gap
LeetCode Link: https://leetcode.com/problems/binary-gap/
Difficulty: 🟢 Easy
Tags: BitManipulation
Techniques: Track Consecutive Set Bits

Guiding Questions:
- How can we find the distance between consecutive 1s in a binary number?
- Do we actually need the full binary string representation?
- Can we scan the integer bit by bit instead?

Main Idea / Approach:
- We iterate through all 32 bit positions of the integer.
- Whenever we encounter a set bit (1), we compare its position with the
  previous set bit we saw.
- The distance between these two positions is a candidate binary gap.
- We keep track of the maximum distance among all such pairs.

- `prevOne` stores the position of the previous set bit.
- For every bit:
    - If current bit is 1 and `prevOne` exists:
        update answer with (current_position - prevOne)
    - Update `prevOne` to the current bit position.

Time Complexity: O(32) ≈ O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prevOne = -1;
        
        for (int bit = 0; bit < 32; bit++) {
            if ((n >> bit) & 1) {
                if (prevOne != -1) {
                    ans = max(ans, bit - prevOne);
                }
                prevOne = bit;
            }
        }
        
        return ans;
    }
};