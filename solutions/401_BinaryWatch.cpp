#include <bits/stdc++.h>
using namespace std;

/*
Problem: Binary Watch
LeetCode Link: https://leetcode.com/problems/binary-watch/
Difficulty: 🟢 Easy
Tags: BitManipulation, Enumeration
Techniques: Brute Force Enumeration + Popcount

Guiding Questions:
- How are hours and minutes represented on a binary watch?
- Can we try every possible time and simply count the number of LEDs turned on?
- How can we efficiently count the number of set bits in a number?

Main Idea / Approach:
- A binary watch represents:
    - Hours: 0 to 11 (4 LEDs)
    - Minutes: 0 to 59 (6 LEDs)
- Instead of constructing combinations of LEDs, we iterate over every valid time.
- For each hour and minute:
    - Count the number of 1-bits (turned on LEDs) using __builtin_popcount().
    - If total bits (hour bits + minute bits) equals `turnedOn`, the time is valid.
- Format the time properly:
    - Minutes must always be two digits (e.g., 3 -> "03").
- Since total possible times are only 12 × 60 = 720, brute force is efficient.

Time Complexity: O(1) — at most 720 checks
Space Complexity: O(k) — storing valid times in result
*/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            int hourOneBit = __builtin_popcount(hour);

            for (int minute = 0; minute < 60; minute++) {
                int minuteOneBit = __builtin_popcount(minute);
                if (hourOneBit + minuteOneBit != turnedOn) continue;
                if (minute < 10) {
                    result.push_back(to_string(hour) + ":0" + to_string(minute));
                }
                else {
                    result.push_back(to_string(hour) + ":" + to_string(minute));
                }
            }
        }

        return result;
    }
};