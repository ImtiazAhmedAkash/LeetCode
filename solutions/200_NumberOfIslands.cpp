#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Islands
LeetCode Link: https://leetcode.com/problems/number-of-islands/
Difficulty: 🟡 Medium
Tags: Matrix, DFS
Technique: DFS Flood Fill

Guiding Questions:
- How can I traverse all connected land cells efficiently?
- How do I ensure each land cell is visited exactly once?
- How can I count connected components in a grid?

Main Idea / Approach:
- Treat the grid as a graph where each land cell ('1') is a node.
- Two land cells are connected if they are adjacent horizontally or vertically.
- Iterate through the grid:
    - When an unvisited land cell is found, perform DFS to mark
      all connected land cells as visited.
    - Each DFS call corresponds to one distinct island.
- Count how many times DFS is initiated.

Time Complexity: O(n × m)
Space Complexity: O(n × m) for the visited matrix and recursion stack
*/

class Solution {
public:
    vector<int> dx = {+0, +0, -1, +1};
    vector<int> dy = {+1, -1, +0, +0};

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector used(n, vector<bool>(m, false));
        auto dfs = [&](auto&& self, int x, int y) -> void {
            used[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '0') continue;
                if (!used[nx][ny]) {
                    self(self, nx, ny);
                }
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};