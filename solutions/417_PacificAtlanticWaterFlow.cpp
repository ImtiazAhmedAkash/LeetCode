#include <bits/stdc++.h>
using namespace std;

/*
Problem: Pacific Atlantic Water Flow
LeetCode Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
Difficulty: 🟡 Medium
Tags: Matrix, DFS
Technique: Reverse DFS from Borders

Guiding Questions:
- From which cells can water reach the Pacific ocean?
- From which cells can water reach the Atlantic ocean?
- How can I avoid running DFS from every cell?

Main Idea / Approach:
- Instead of flowing water from each cell outward, reverse the logic:
    - Start DFS from the Pacific border cells and mark all reachable cells.
    - Start DFS from the Atlantic border cells and mark all reachable cells.
- A cell can flow into an ocean if there exists a non-decreasing height path to it.
- During DFS, move only to neighboring cells with height >= current cell.
- Finally, collect cells that are reachable from both Pacific and Atlantic DFS runs.

Time Complexity: O(n × m)
Space Complexity: O(n × m) for visited matrices and recursion stack
*/

class Solution {
public:
    vector<int> dx = {+1, -1, +0, +0};
    vector<int> dy = {+0, +0, +1, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector pacific(n, vector<bool>(m, false));
        vector atlantic(n, vector<bool>(m, false));
        auto dfs = [&](auto&& self, int x, int y, vector<vector<bool>>& used) -> void {
            used[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || heights[x][y] > heights[nx][ny]) continue;
                if (!used[nx][ny]) {
                    self(self, nx, ny, used);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            dfs(dfs, i, 0, pacific);
            dfs(dfs, i, m - 1, atlantic);
        }
        for (int j = 0; j < m; j++) {
            dfs(dfs, 0, j, pacific);
            dfs(dfs, n - 1, j, atlantic);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};