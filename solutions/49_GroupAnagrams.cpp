#include <bits/stdc++.h>
using namespace std;

/*
Problem: Group Anagrams
LeetCode Link: https://leetcode.com/problems/group-anagrams/
Difficulty: 🟡 Medium
Tags: Array, HashTable, String, Sorting
Technique: Canonical Representation

Guiding Questions:
- How can I identify if two strings are anagrams?
- Can I convert each string into a standard form for comparison?
- How can I group strings efficiently based on that form?

Main Idea / Approach:
- Anagrams share the same sorted character sequence.
- For each string, sort its characters to form a canonical key.
- Use a hash table to group original strings by this key.
- Finally, collect all grouped values as the answer.

Time Complexity:
- O(n * k log k)
  where n = number of strings, k = average length of a string

Space Complexity:
- O(n * k)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &[_, v] : mp) {
            ans.push_back(v);
        }

        return ans;
    }
};
