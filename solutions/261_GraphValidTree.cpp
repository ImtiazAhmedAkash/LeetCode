#include <bits/stdc++.h>
using namespace std;

/*
Problem: Graph Valid Tree
LeetCode Link: https://leetcode.com/problems/graph-valid-tree/
NeetCode Link: https://neetcode.io/problems/graph-valid-tree
Difficulty: 🟡 Medium
Tags: Graph, DFS
Technique: DFS + Cycle Detection

Guiding Questions:
- What are the conditions for a graph to be a valid tree?
- How can I detect cycles in an undirected graph efficiently?
- How can I ensure all nodes are connected?

Main Idea / Approach:
- A graph is a tree if:
    1. It has exactly n - 1 edges.
    2. It is fully connected (all nodes reachable from any node).
- Build an adjacency list from the edges.
- Use DFS (implemented as a recursive lambda) to detect cycles:
    - Keep track of visited nodes.
    - For each neighbor, if it is visited and not the parent, a cycle exists.
- Count visited nodes during DFS to ensure connectivity.
- Return false if a cycle is found or some nodes are unvisited.

Time Complexity: O(n) — each node and edge visited once
Space Complexity: O(n) — adjacency list + visited array + recursion stack
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector G(n, vector<int>());
        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<bool> used(n, false);
        int visitedCount = 0;
        auto cycleExists = [&](auto&& self, int u, int par = -1) -> bool {
            used[u] = true;
            visitedCount++;
            for (auto v : G[u]) {
                if (used[v] && v != par) return true;
                if (!used[v] && self(self, v, u)) {
                    return true;
                }
            }
            return false;
        };

        return (!cycleExists(cycleExists, 0) && visitedCount == n);
    }
};