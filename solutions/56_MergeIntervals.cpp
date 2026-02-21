#include <bits/stdc++.h>
using namespace std;

/*
Problem: Merge Intervals
LeetCode Link: https://leetcode.com/problems/merge-intervals/
Difficulty: 🟡 Medium
Tags: Array, Sorting, Intervals
Techniques: Sorting + Greedy

Guiding Questions:
- Why must we sort intervals first?
- How do we detect overlapping intervals?
- Why is checking only current.start <= lastMerged.end enough?

Main Idea / Approach:
1) Sort all intervals by their start time.
   Sorting ensures that any overlapping intervals will appear next to each other.
   Without sorting, we could miss overlaps.

2) Maintain a result vector.
   It will always contain non-overlapping merged intervals.

3) For each interval, there are two possible cases:

   Case 1: No Overlap
       current.start > lastMerged.end

       Example:
           [1,3]   [5,7]

       The current interval starts after the previous one ends.
       So we simply push it into result.

   Case 2: Overlap
       current.start <= lastMerged.end

       Example:
           [1,4] and [2,6]

       Since they overlap, we merge them.

       Merging logic:
           newStart = min(previous.start, current.start)
           newEnd   = max(previous.end, current.end)

       Because intervals are sorted, previous.start is already
       the smaller one, so practically we only need to update the end:

           result.back()[1] = max(result.back()[1], current[1]);

4) Continue this process for all intervals.

Time Complexity: O(n log n)
    - Sorting takes O(n log n)
    - Single pass merging takes O(n)

Space Complexity: O(n)
    - In worst case, no intervals overlap
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto &vec : intervals) {
            if (!result.empty() && vec[0] <= result.back()[1]) {
                result.back()[0] = min(result.back()[0], vec[0]);
                result.back()[1] = max(result.back()[1], vec[1]);
            }
            else {
                result.push_back(vec);
            }
        }

        return result;
    }
};