#include <bits/stdc++.h>
using namespace std;

/*
Problem: Alien Dictionary
LeetCode Link: https://leetcode.com/problems/alien-dictionary/
NeetCode Link: https://neetcode.io/problems/foreign-dictionary
Difficulty: 🔴 Hard
Tags: Graph, BFS, TopologicalSort
Technique: Kahn’s Algorithm (BFS Topological Sort)

Guiding Questions:
- How can I convert character ordering rules into a directed graph?
- Why is only the first differing character between adjacent words important?
- How do I handle invalid cases caused by prefix conflicts?
- How can I detect cycles in the character dependency graph?

Main Idea / Approach:
- Treat each unique character as a node in a directed graph.
- Compare adjacent words and identify the first differing character.
- Add a directed edge representing character precedence.
- If a longer word comes before its prefix, return an invalid result.
- Track in-degrees of characters.
- Apply Kahn’s Algorithm to obtain a topological ordering.
- If all characters are processed, return the ordering; otherwise, return an empty string.

Time Complexity: O(C + E)
Space Complexity: O(C + E)
Where:
- C = number of unique characters
- E = number of precedence relations
*/

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> G;
        unordered_map<char, int> inDegree;
        
        int n = words.size();
        for (auto &word : words) {
            for (auto &c : word) {
                inDegree[c] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            int prevLen = words[i - 1].size();
            int curLen = words[i].size();
            if (prevLen > curLen && words[i - 1].substr(0, curLen) == words[i]) return "";
            
            int len = min(prevLen, curLen);
            int j = 0;
            while (j < len && words[i - 1][j] == words[i][j]) j++;
            if (j < len) {
                char u = words[i - 1][j];
                char v = words[i][j];
                if (G[u].find(v) == G[u].end()) {
                    G[u].insert(v);
                    inDegree[v]++;
                }
            }
        }

        queue<char> q;
        for (auto [c, degree] : inDegree) {
            if (degree == 0) {
                q.push(c);
            }
        }

        string alphabetOrder;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            alphabetOrder += u;

            for (auto &v : G[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return alphabetOrder.size() == inDegree.size() ? alphabetOrder : "";
    }
};