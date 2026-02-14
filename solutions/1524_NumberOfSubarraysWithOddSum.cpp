#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Sub-arrays With Odd Sum
LeetCode Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
Difficulty: 🟡 Medium
Tags: Prefix Sum, Parity, HashTable
Techniques: Prefix Parity Counting

Guiding Questions:
- What condition makes a subarray sum odd?
- Do we really need the exact prefix sum or just some property of it?

Main Idea / Approach:
- Instead of tracking the actual prefix sum, we only track whether it is EVEN or ODD.
- A subarray sum from L to R is:
      prefix[R] - prefix[L-1]
- This subarray will be ODD only when the two prefix sums have different parity:
      odd - even = odd
      even - odd = odd
- Therefore, at each position:
  - If current prefix sum is odd, it can form an odd subarray with every previous even prefix.
  - If current prefix sum is even, it can form an odd subarray with every previous odd prefix.
- So we just count how many even and odd prefixes we have seen so far.
- We start with one even prefix (empty array sum = 0).
- As we scan the array, we update the parity and add how many opposite-parity prefixes exist.
- This directly counts how many odd-sum subarrays end at the current index.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        vector<int> cnt(2, 0);
        cnt[0] = 1;
        int sum = 0;
        long long result = 0;

        for (auto &x : arr) {
            sum += x;
            sum %= 2;
            result += cnt[sum ^ 1];
            result %= mod;
            cnt[sum]++;
        }

        return result;
    }
};