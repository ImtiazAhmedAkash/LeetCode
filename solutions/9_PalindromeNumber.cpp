#include <bits/stdc++.h>
using namespace std;

/*
Problem: Palindrome Number
LeetCode Link: https://leetcode.com/problems/palindrome-number/
Difficulty: 🟢 Easy
Tags: Math
Techniques: Reverse Integer

Guiding Questions:
- How can we reverse a number without converting it to a string?
- What happens if the number is negative?
- How do we extract digits one by one?

Main Idea / Approach:
- A number is a palindrome if it reads the same forward and backward.
- Negative numbers are immediately not palindrome.

- We reverse the integer using digit extraction:
      lastDigit = tmp % 10
      rev = rev * 10 + lastDigit
      tmp /= 10

- After constructing the reversed number,
  we compare it with the original number.
- If both are equal → it is a palindrome.

- We use long long for `rev` to avoid overflow during reversal.

Time Complexity: O(log10(n)) — number of digits
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int tmp = x;
        long long rev = 0;
        while (tmp > 0) {
            rev *= 10;
            rev += tmp % 10;
            tmp /= 10;
        }

        return (x == rev);
    }
};