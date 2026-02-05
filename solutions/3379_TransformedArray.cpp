#include <bits/stdc++.h>
using namespace std;

/*
Problem: Transformed Array
LeetCode Link: https://leetcode.com/problems/transformed-array/
Difficulty: 🟢 Easy
Tags: Array, Simulation
Technique: Index Mapping with Modulo

Guiding Questions:
- How do I map each index to its transformed position?
- How do I safely handle negative modulo in C++?
- How can I build the result array without modifying the original one?

Main Idea / Approach:
- For each index i, compute the new index as:
      (i + nums[i]) % n
- Since C++ modulo can be negative, adjust it by adding n if needed.
- Set result[i] = nums[newIndex].
- This directly simulates the transformation as described.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int indx = (i + nums[i]) % n;
            if (indx < 0) indx += n;
            result[i] = nums[indx];
        }
        return result;
    }
};