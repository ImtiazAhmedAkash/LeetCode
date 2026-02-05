# LeetCode Problem Solutions (C++)

This repository contains my **C++ solutions to LeetCode problems**.  
The main focus is on **problem solving, understanding patterns, and building strong DSA skills**.

---

## How to use this repository

- Each problem is listed in the table below.
- Click the **LeetCode link** to view the problem.  
- Click the **Solution link** to view the C++ solution.  
- Use **Ctrl + F** to quickly find problems by:  
  - Problem ID  
  - Problem name  
  - Tags (patterns or secondary topics)  

---

## Repository structure

- `README.md` → Main problem list (this file)
- `solutions/` → All C++ solution files  
  - Each solution file contains:  
    - Problem link  
    - Main idea / approach (as comments)  
    - Time and space complexity  

---

## Difficulty Legend

| Difficulty | Icon |
|------------|------|
|    Easy    | 🟢 |
|   Medium   | 🟡 |
|    Hard    | 🔴 | 

---

## Problem Solutions Table

<!-- 
| 1 | Two Sum | 🟢 | [Link](https://leetcode.com/problems/two-sum/) | [C++](solutions/1_TwoSum.cpp) | `Array` `HashMap` |  |
                                                    -->

|  ID  | Problem Name | Difficulty |  LeetCode  |  Solution  |  Tags  |  Techniques  |
|:----:|:-------------|:----------:|:----------:|:----------:|:------:|:------------:|
| 1 | Two Sum | 🟢 | [Link](https://leetcode.com/problems/two-sum/) | [C++](solutions/1_TwoSum.cpp) | `Array` `HashTable` | Complement Lookup |
| 3 | Longest Substring Without Repeating Characters | 🟡 | [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](solutions/3_LongestSubstringWithoutRepeatingCharacters.cpp) | `SlidingWindow` `Hashing` | Sliding Window (Frequency Tracking) |
| 11 | Container With Most Water | 🟡 | [Link](https://leetcode.com/problems/container-with-most-water/) | [C++](solutions/11_ContainerWithMostWater.cpp) | `Array` `TwoPointers` | Two Pointers (Greedy Shrinking) |
| 15 | 3Sum | 🟡 | [Link](https://leetcode.com/problems/3sum/) | [C++](solutions/15_3Sum.cpp) | `Array` `TwoPointers` `Sorting` | Fixed Element + Two Pointers |
| 20 | Valid Parentheses | 🟢 | [Link](https://leetcode.com/problems/valid-parentheses/) | [C++](solutions/20_ValidParentheses.cpp) | `Stack` `String` | Stack (Bracket Matching) |
| 49 | Group Anagrams | 🟡 | [Link](https://leetcode.com/problems/group-anagrams/) | [C++](solutions/49_GroupAnagrams.cpp) | `Array` `HashTable` `String` `Sorting` | Canonical Representation |
| 76 | Minimum Window Substring | 🔴 | [Link](https://leetcode.com/problems/minimum-window-substring/) | [C++](solutions/76_MinimumWindowSubstring.cpp) | `SlidingWindow` `Hashing` | Sliding Window (Frequency Tracking) |
| 121 | Best Time to Buy and Sell Stock | 🟢 | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](solutions/121_BestTimeToBuyAndSellStock.cpp) | `Array` `Greedy` | Single Pass (Track Min & Max) |
| 125 | Valid Palindrome | 🟢 | [Link](https://leetcode.com/problems/valid-palindrome/) | [C++](solutions/125_ValidPalindrome.cpp) | `String` `TwoPointers` | Filter + Two-Pointer Check |
| 128 | Longest Consecutive Sequence | 🟡 | [Link](https://leetcode.com/problems/longest-consecutive-sequence/) | [C++](solutions/128_LongestConsecutiveSequence.cpp) | `Array` `HashTable` | Hash Set + Sequence Start Detection |
| 200 | Number of Islands | 🟡 | [Link](https://leetcode.com/problems/number-of-islands/) | [C++](solutions/200_NumberOfIslands.cpp) | `Matrix` `DFS` | DFS Flood Fill |
| 207 | Course Schedule | 🟡 | [Link](https://leetcode.com/problems/course-schedule/) | [C++](solutions/207_CourseSchedule.cpp) | `Graph` `BFS` `TopologicalSort` | Kahn’s Algorithm |
| 217 | Contains Duplicate | 🟢 | [Link](https://leetcode.com/problems/contains-duplicate/) | [C++](solutions/217_ContainsDuplicate.cpp) | `Array` `HashTable` | Seen Before Check |
| 238 | Product of Array Except Self | 🟡 | [Link](https://leetcode.com/problems/product-of-array-except-self/) | [C++](solutions/238_ProductOfArrayExceptSelf.cpp) | `Array` `PrefixSum` | Prefix & Suffix Product |
| 242 | Valid Anagram | 🟢 | [Link](https://leetcode.com/problems/valid-anagram/) | [C++](solutions/242_ValidAnagram.cpp) | `Array` `String` | Frequency Counting |
| 261 | Graph Valid Tree | 🟡 | [LeetCode](https://leetcode.com/problems/graph-valid-tree/) [NeetCode](https://neetcode.io/problems/valid-tree) | [C++](solutions/261_GraphValidTree.cpp) | `Graph` `DFS` | DFS + Cycle Detection |
| 269 | Alien Dictionary | 🔴 | [LeetCode](https://leetcode.com/problems/alien-dictionary/) [NeetCode](https://neetcode.io/problems/foreign-dictionary) | [C++](solutions/269_AlienDictionary.cpp) | `Graph` `BFS` `TopologicalSort` | Kahn’s Algorithm |
| 271 | Encode and Decode Strings | 🟡 | [LeetCode](https://leetcode.com/problems/encode-and-decode-strings/) [NeetCode](https://neetcode.io/problems/string-encode-and-decode) | [C++](solutions/271_EncodeAndDecodeStrings.cpp) | `String` `Design` | Length Prefix Encoding |
| 323 | Number of Connected Components in an Undirected Graph | 🟡 | [LeetCode](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) [NeetCode](https://neetcode.io/problems/count-connected-components) | [C++](solutions/323_NumberOfConnectedComponents.cpp) | `Graph` `DSU` | Disjoint Set Union |
| 347 | Top K Frequent Elements | 🟡 | [Link](https://leetcode.com/problems/top-k-frequent-elements/) | [C++](solutions/347_TopKFrequentElements.cpp) | `Hashing` `Heap` | Hash Map + Max Heap |
| 417 | Pacific Atlantic Water Flow | 🟡 | [Link](https://leetcode.com/problems/pacific-atlantic-water-flow/) | [C++](solutions/417_PacificAtlanticWaterFlow.cpp) | `Matrix` `DFS` | Reverse DFS from Borders |
| 424 | Longest Repeating Character Replacement | 🟡 | [Link](https://leetcode.com/problems/longest-repeating-character-replacement/) | [C++](solutions/424_LongestRepeatingCharacterReplacement.cpp) | `SlidingWindow` `Hashing` | Sliding Window (Frequency Tracking) |
| 3379 | Transformed Array | 🟢 | [Link](https://leetcode.com/problems/transformed-array/) | [C++](solutions/3379_TransformedArray.cpp) | `Array` `Simulation` | Index Mapping with Modulo |

---