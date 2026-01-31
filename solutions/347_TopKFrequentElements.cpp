#include <bits/stdc++.h>
using namespace std;

/*
Problem: Top K Frequent Elements
LeetCode Link: https://leetcode.com/problems/top-k-frequent-elements/
Difficulty: 🟡 Medium
Tags: Hashing, Heap
Technique: Hash Map + Max Heap

Guiding Questions:
- How can I count the frequency of each element efficiently, including negative numbers?
- How can I retrieve the k elements with the highest frequency efficiently?
- How do I maintain the correct order of the top k elements?

Main Idea / Approach:
- Use an unordered_map (freq) to count the frequency of each number in nums.
    - Note: unordered_map is used instead of a vector because nums may contain negative numbers.
- Use a max heap (priority_queue) to store pairs of (frequency, number).
- Push all pairs from the map into the heap.
- Pop the top k elements from the heap and store their numbers in result.
- Return result as the final answer.

Time Complexity: O(n + m log m), where n = nums.size(), m = number of unique elements
Space Complexity: O(n + m), for the map and the heap
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto [num, cnt] : freq) {
            pq.push({cnt, num});
        }

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            auto [cnt, num] = pq.top();
            pq.pop();
            result[i] = num;
        }

        return result;
    }
};