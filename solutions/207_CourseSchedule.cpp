#include <bits/stdc++.h>
using namespace std;

/*
Problem: Course Schedule
LeetCode Link: https://leetcode.com/problems/course-schedule/
Difficulty: 🟡 Medium
Tags: Graph, BFS, TopologicalSort
Technique: Kahn’s Algorithm (BFS Topological Sort)

Guiding Questions:
- How can I model course prerequisites as a directed graph?
- How can I detect cycles in a directed graph efficiently?
- How do I determine if all nodes can be processed?

Main Idea / Approach:
- Represent courses as nodes in a directed graph.
- For each prerequisite (u → v), increase the in-degree of v.
- Push all nodes with in-degree 0 into a queue.
- Repeatedly remove nodes from the queue and reduce in-degrees of neighbors.
- Count how many nodes are processed.
- If all courses are processed, the schedule is valid; otherwise, a cycle exists.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector G(numCourses, vector<int>());
        for (auto &vec : prerequisites) {
            int u = vec[1];
            int v = vec[0];
            inDegree[v]++;
            G[u].push_back(v);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int coursesTaken = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            coursesTaken++;

            for (auto v : G[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return numCourses == coursesTaken;
    }
};