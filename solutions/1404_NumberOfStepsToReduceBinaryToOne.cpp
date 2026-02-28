#include <bits/stdc++.h>
using namespace std;

/*
Problem: Number of Steps to Reduce a Number in Binary Representation to One
LeetCode Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
Difficulty: 🟡 Medium
Tags: String, Simulation, BitManipulation
Techniques: Carry Simulation

Guiding Questions:
- How do we simulate binary addition without converting to an integer?
- What happens when the current bit is 0 or 1?
- How does carry propagate during addition?

Main Idea / Approach:
- We simulate the process from right to left.
- Two operations exist:
      If number is even → divide by 2
      If number is odd  → add 1

- Instead of modifying the string,
  we simulate using a carry variable.

- For each bit (from right to left, excluding MSB):
      sum = current bit + carry

  Case 1: sum == 0
      → even → 1 step (divide by 2)

  Case 2: sum == 1
      → odd → 2 steps (add 1, then divide)
      → this creates a carry

  Case 3: sum == 2
      → effectively 0 with carry already handled
      → 1 step (divide)

- After processing all bits,
  if carry remains → add one more step.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int carry = 0;
        int ans = 0;
        
        for (int i = n - 1; i > 0; i--) {
            int sum = carry + (s[i] - '0');
            carry = (sum / 2);
            sum %= 2;

            if (sum == 0) ans++;
            else {
                ans += 2;
                carry++;
            }
        }
        ans += carry;
        
        return ans;
    }
};
