#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Balanced Substring II
LeetCode Link: https://leetcode.com/problems/longest-balanced-substring-ii/
Difficulty: 🟡 Medium
Tags: String, PrefixSum, HashTable
Techniques: Frequency Difference Prefix Hashing

Guiding Questions:
- How do we check equal frequency without checking every substring?
- Can equal counts be transformed into a prefix sum condition?
- How does the problem change depending on the number of distinct characters?

Main Idea / Approach:
A substring is balanced if all characters appearing in it occur the same number of times.
Since the string only contains 'a', 'b', and 'c', we solve the problem by cases.

--------------------------------------------------
Case 1: Only one distinct character
--------------------------------------------------
- A single character substring is always balanced.
- We simply find the longest consecutive run of identical characters.

--------------------------------------------------
Case 2: Exactly two distinct characters (x, y)
--------------------------------------------------
- For two characters, the substring is balanced if:
        count(x) == count(y)
- Convert this into a prefix sum problem:
        treat x as +1
        treat y as -1
- If two indices have the same prefix sum,
  the subarray between them has equal counts of x and y.
- We store the first occurrence of each prefix sum in a hashmap.
- When the same sum appears again,
  the segment between them is a valid balanced substring.
- Any character other than x or y breaks the substring,
  so we reset the map and continue.

--------------------------------------------------
Case 3: All three characters (a, b, c)
--------------------------------------------------
- Balanced condition:
        count(a) = count(b) = count(c)
- This can be rewritten as:
        count(a) - count(b) = 0
        count(a) - count(c) = 0
- We track prefix frequencies of a, b, c.
- At each index compute the pair:
        (count(a) - count(b), count(a) - count(c))
- If the same pair appears again,
  the substring between those indices has equal frequency of all three characters.
- Store the first occurrence of each pair in a map.
- When repeated, update the maximum length.

--------------------------------------------------
Final Answer:
Take the maximum length among:
    1 distinct
    2 distinct
    3 distinct

Time Complexity: O(n)
- Each case processes the string linearly.

Space Complexity: O(n)
- Hash maps store prefix states.
*/

class Solution {
public:
    int oneDistinct(string& s) {
        int maxLen = 1;
        int cnt = 1;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
                maxLen = max(maxLen, cnt);
            }
            else {
                cnt = 1;
            }
        }
        return maxLen;
    }

    int twoDistinct(char x, char y, string& s) {
        int maxLen = 0;
        int n = s.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != x && s[i] != y) {
                mp.clear();
                mp[0] = i;
                sum = 0;
                continue;
            }
            
            if (s[i] == x) sum++;
            else sum--;

            if (mp.count(sum)) {
                maxLen = max(maxLen, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return maxLen;
    }

    int threeDistinct(string& s) {
        int maxLen = 0;
        int n = s.size();
        map<pair<int, int>, int> pairMap;
        pairMap[{0, 0}] = -1;
        vector<int> freq(3, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            pair<int, int> p = {freq[0] - freq[1], freq[0] - freq[2]};
            if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0 && pairMap.count(p)) {
                maxLen = max(maxLen, i - pairMap[p]);
            }
            else {
                pairMap[p] = i;
            }
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        int caseOne = oneDistinct(s);
        int caseTwo = max({twoDistinct('a', 'b', s), twoDistinct('b', 'c', s), twoDistinct('c', 'a', s)});
        int caseThree = threeDistinct(s);

        return max({caseOne, caseTwo, caseThree});
    }
};