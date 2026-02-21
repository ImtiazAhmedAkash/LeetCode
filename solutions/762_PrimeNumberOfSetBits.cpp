#include <bits/stdc++.h>
using namespace std;

/*
Problem: Prime Number of Set Bits in Binary Representation
LeetCode Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
Difficulty: 🟢 Easy
Tags: BitManipulation, Math
Techniques: Popcount + Prime Check

Guiding Questions:
- How can we efficiently count the number of 1 bits in a number?
- Instead of checking the number itself, what if we check a property of its binary form?
- What range of values can the number of set bits take?

Main Idea / Approach:
- For every number in the range [left, right], we count how many 1s appear in its binary representation.
- We use `__builtin_popcount(n)` which directly returns the number of set bits in O(1) time.
- Now the problem becomes:
      Count numbers whose number of set bits is a prime number.
- Since the maximum value of right is 10^6, a number can have at most 20 bits.
  Therefore, the set-bit count will only lie between 0 and 20.
- We simply check if this count is prime using a basic primality test.
- If it is prime → increment the answer.

Time Complexity: O((right − left + 1) * √20)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(__builtin_popcount(i))) result++;
        }

        return result;
    }
};