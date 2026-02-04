#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Connected Components in an Undirected Graph
LeetCode Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
NeetCode Link: https://neetcode.io/problems/count-connected-components
Difficulty: 🟡 Medium
Tags: Graph, DSU
Technique: Disjoint Set Union (Union-Find)

Guiding Questions:
- How can I efficiently track connected components as I add edges?
- How does union by size or rank help in keeping operations fast?
- How can I count the number of connected components without traversing the graph repeatedly?

Main Idea / Approach:
- Initialize DSU with n components (each node is its own parent initially).
- For each edge (u, v), merge their components using DSU:
    - If they were already connected, do nothing.
    - Otherwise, union them and decrement component count.
- After processing all edges, the DSU's `components` value gives the number of connected components.

Time Complexity: O(n + m * α(n)) — α(n) is inverse Ackermann function (almost constant)
Space Complexity: O(n) — for parent and size arrays
*/

class Solution {
public:
    struct DSU {
        vector<int> parent, Size;
        int components;
        DSU() {}
        DSU(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            Size.assign(n + 1, 1);
            components = n;
        }
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;

            if (Size[x] < Size[y]) swap(x, y);
            Size[x] += Size[y];
            parent[y] = x;
            components--;
            return true;
        }
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            dsu.merge(u, v);
        }

        return dsu.components;
    }
};
