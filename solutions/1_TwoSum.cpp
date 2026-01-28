#include <bits/stdc++.h>
using namespace std;

/*
Problem: Two Sum
LeetCode Link: https://leetcode.com/problems/two-sum/
Difficulty: 🟢 Easy
Tags: Array, HashMap
Techniques: Complement Lookup

Guiding Questions:
- How can I check if a pair of numbers sum up to a target efficiently?
- Can I use extra space to store information for faster lookup?
- How can I return the indices of the numbers instead of the numbers themselves?

Main Idea / Approach:
- Use an unordered_map to store numbers and their indices.
- For each number, check if (target - current number) exists in the map.
- If it exists, return the pair of indices immediately.

Time Complexity: O(n) — iterate through nums once, O(1) average for map operations
Space Complexity: O(n) — store up to n elements in the unordered_map
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
