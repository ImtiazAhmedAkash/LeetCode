#include <bits/stdc++.h>
using namespace std;

/*
Problem: Encode and Decode Strings
LeetCode Link: https://leetcode.com/problems/encode-and-decode-strings/
NeetCode Link: https://neetcode.io/problems/string-encode-and-decode
Difficulty: 🟡 Medium (Premium)
Tags: String, Design
Technique: Length Prefix Encoding

Guiding Questions:
- How can I encode multiple strings into one string unambiguously?
- How do I handle special characters like '#' inside the strings?
- How can decoding be done efficiently in a single pass?

Main Idea / Approach:
- Use length-prefix encoding for each string.
- For every string:
    - Append its length.
    - Append a delimiter '#'.
    - Append the string itself.
- This guarantees unambiguous decoding even if strings contain '#'.

Encoding:
- Convert each string to: "<length>#<string>"
- Concatenate all encoded parts into one result string.

Decoding:
- Traverse the encoded string.
- Read characters until '#' to get the length.
- Convert the length string to an integer.
- Extract the next 'length' characters as one decoded string.
- Repeat until the entire string is processed.

Time Complexity:
- Encoding: O(total characters)
- Decoding: O(total characters)

Space Complexity:
- O(total characters) for the encoded string and decoded output
*/

class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (int i = 0; i < strs.size(); i++) {
            result += to_string(strs[i].size());
            result += '#';
            result += strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = s.size();
        int i = 0;
        while (i < n) {
            string t;
            while (s[i] != '#') {
                t += s[i];
                i++;
            }
            i++;

            int len = stoi(t);
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};
