#include <bits/stdc++.h>
using namespace std;

/*
Problem: 3Sum
LeetCode Link: https://leetcode.com/problems/3sum/
Difficulty: 🟡 Medium
Tags: Array, TwoPointers, Sorting
Technique: Fixed Element + Two Pointers

Guiding Questions:
- Can I reduce 3Sum to a 2Sum problem?
- How does sorting help with pruning and duplicates?
- How can I ensure all triplets are unique?

Main Idea / Approach:
- Sort the array to enable two-pointer traversal.
- Fix one element nums[i] and find pairs (l, r) such that:
    nums[i] + nums[l] + nums[r] == 0
- Move pointers based on the sum:
    - sum < 0 → move left pointer
    - sum > 0 → move right pointer
- Skip duplicate values for:
    - the fixed index i
    - both left and right pointers after finding a valid triplet
- This guarantees all triplets are unique.

Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding output)
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            for (int l = i + 1, r = n - 1; l < r; ) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int leftVal = nums[l];
                    int rightVal = nums[r];
                    while (l < r && nums[l] == leftVal) l++;
                    while (l < r && nums[r] == rightVal) r--;
                }
            }
        }

        return ans;
    }
};