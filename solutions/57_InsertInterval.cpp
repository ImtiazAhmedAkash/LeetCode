#include <bits/stdc++.h>
using namespace std;

/*
Problem: Insert Interval
LeetCode Link: https://leetcode.com/problems/insert-interval/
Difficulty: 🟡 Medium
Tags: Array, Intervals, Simulation
Techniques: Three-Phase Interval Merge

Guiding Questions:
- Since intervals are already sorted and non-overlapping, where can the new interval go?
- When exactly do two intervals overlap?
- Can we process the array in one pass instead of inserting and sorting?

Main Idea / Approach:

The key observation:
The given intervals are:
1) Sorted by start time
2) Already non-overlapping

Therefore, every interval relative to the newInterval must fall into
exactly ONE of three cases:

----------------------------------------------------
CASE 1 — Completely Before (Left Side)
Condition:
    interval.end < newInterval.start

Meaning:
The current interval finishes before the new interval even begins.

Example:
    [1,3]   new = [6,8]

These intervals can NEVER overlap in the future,
so we directly copy them into the result.

----------------------------------------------------
CASE 2 — Overlapping (Merge Zone)
Condition:
    interval.start <= newInterval.end

Meaning:
The interval intersects the new interval.

Example:
    [4,7]   new = [6,9]

We DO NOT push it to result yet.
Instead, we EXPAND the new interval to absorb it.

Why?
If two intervals overlap:
    [a,b] and [c,d]
The merged interval must cover both:
    [min(a,c), max(b,d)]

So we update:
    newInterval.start = min(newInterval.start, interval.start)
    newInterval.end   = max(newInterval.end, interval.end)

We keep merging until overlap stops.

----------------------------------------------------
CASE 3 — Completely After (Right Side)
Condition:
    interval.start > newInterval.end

Now merging is finished.
The newInterval is final and safe to insert.

We first push the merged newInterval,
then copy all remaining intervals as-is.

----------------------------------------------------

Important Insight:
Because the original intervals are sorted and non-overlapping,
once we leave the overlapping zone, we will NEVER encounter
another overlapping interval again. That guarantees a single pass solution.

Time Complexity: O(n) — single traversal of intervals
Space Complexity: O(n) — output array
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
