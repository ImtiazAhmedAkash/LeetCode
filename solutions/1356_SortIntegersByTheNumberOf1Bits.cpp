#include <bits/stdc++.h>
using namespace std;

/*
Problem: Sort Integers by The Number of 1 Bits
LeetCode Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
Difficulty: 🟢 Easy
Tags: Array, BitManipulation, Sorting
Techniques: Custom Comparator

Guiding Questions:
- How do we count the number of 1 bits in an integer?
- How do we sort using multiple criteria?
- What should we do if two numbers have the same bit count?

Main Idea / Approach:
- We sort the array using a custom comparator.
- Primary sorting criteria:
      Number of set bits (ascending).
- Secondary sorting criteria:
      Numerical value (ascending).

- We use __builtin_popcount(x) to count set bits efficiently.
- If two numbers have equal bit count,
  we return x < y to ensure smaller number comes first.

Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring sort recursion stack)
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (__builtin_popcount(x) == __builtin_popcount(y)) 
                return x < y;
            return __builtin_popcount(x) < __builtin_popcount(y);
        });

        return arr;
    }
};