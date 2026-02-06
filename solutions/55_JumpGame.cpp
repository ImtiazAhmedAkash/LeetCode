#include <bits/stdc++.h>
using namespace std;

/*
Problem: Jump Game
LeetCode Link: https://leetcode.com/problems/jump-game/
Difficulty: 🟡 Medium
Tags: Array, Greedy
Technique: Farthest Reach (Greedy)

Guiding Questions:
- From the current position, how far can I reach?
- Is there any index that becomes unreachable?
- Can I detect failure as early as possible?

Main Idea / Approach:
- Maintain `maxIndx`, the farthest index reachable so far.
- While iterating the array, every index `i` must be reachable
  (i.e., `i <= maxIndx`) in order to continue.
- From each reachable position, update `maxIndx` using `i + nums[i]`.
- If at any point we are stuck (`i == maxIndx` and `nums[i] == 0`)
  before reaching the end, no further progress is possible.
- If the loop finishes without getting stuck, the last index is reachable.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndx = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i == maxIndx && nums[i] == 0) return false;
            maxIndx = max(maxIndx, i + nums[i]);
        }
        return true;
    }
};