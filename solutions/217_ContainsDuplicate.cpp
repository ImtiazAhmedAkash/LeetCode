#include <bits/stdc++.h>
using namespace std;

/*
Problem: Contains Duplicate
LeetCode Link: https://leetcode.com/problems/contains-duplicate/
Difficulty: 🟢 Easy
Tags: Array, HashSet
Technique: Seen Before Check

Guiding Questions:
- How can I detect whether an element has appeared before?
- Do I need frequency counts, or just existence?
- Can I stop early once a duplicate is found?

Main Idea / Approach:
- Iterate through the array while keeping a hash set of seen elements.
- For each element, check if it already exists in the set.
- If it does, a duplicate is found → return true.
- If the loop completes without finding duplicates, return false.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &x : nums) {
            if (seen.find(x) != seen.end()) {
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};
