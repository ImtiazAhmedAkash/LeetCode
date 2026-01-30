#include <bits/stdc++.h>
using namespace std;

/*
Problem: Container With Most Water
LeetCode Link: https://leetcode.com/problems/container-with-most-water/
Difficulty: 🟡 Medium
Tags: Array, TwoPointers
Technique: Two Pointers (Greedy Shrinking)

Guiding Questions:
- How can I compute the area between two vertical lines?
- Why is the brute-force O(n^2) solution too slow?
- Which pointer should I move to potentially increase the area?

Main Idea / Approach:
- Use two pointers: one at the start (l) and one at the end (r).
- The area is determined by:
    width = r - l
    height = min(height[l], height[r])
- To possibly find a larger area:
    - Move the pointer with the smaller height inward.
    - Moving the taller pointer cannot increase the area because width decreases
      and height is limited by the shorter line.
- Keep track of the maximum area found.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int l = 0, r = n - 1; l < r; ) {
            int h = min(height[l], height[r]);
            int b = r - l;
            ans = max(ans, b * h);

            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return ans;
    }
};