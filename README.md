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
| 5 | Longest Palindromic Substring | 🟡 | [Link](https://leetcode.com/problems/longest-palindromic-substring/) | [C++](solutions/5_LongestPalindromicSubstring.cpp) | `String` `DP` `Memoization` | Palindrome DP on Substrings |
| 11 | Container With Most Water | 🟡 | [Link](https://leetcode.com/problems/container-with-most-water/) | [C++](solutions/11_ContainerWithMostWater.cpp) | `Array` `TwoPointers` | Two Pointers (Greedy Shrinking) |
| 15 | 3Sum | 🟡 | [Link](https://leetcode.com/problems/3sum/) | [C++](solutions/15_3Sum.cpp) | `Array` `TwoPointers` `Sorting` | Fixed Element + Two Pointers |
| 20 | Valid Parentheses | 🟢 | [Link](https://leetcode.com/problems/valid-parentheses/) | [C++](solutions/20_ValidParentheses.cpp) | `Stack` `String` | Stack (Bracket Matching) |
| 49 | Group Anagrams | 🟡 | [Link](https://leetcode.com/problems/group-anagrams/) | [C++](solutions/49_GroupAnagrams.cpp) | `Array` `HashTable` `String` `Sorting` | Canonical Representation |
| 53 | Maximum Subarray | 🟡 | [Link](https://leetcode.com/problems/maximum-subarray/) | [C++](solutions/53_MaximumSubarray.cpp) | `Array` `DP` | Kadane’s Algorithm |
| 55 | Jump Game | 🟡 | [Link](https://leetcode.com/problems/jump-game/) | [C++](solutions/55_JumpGame.cpp) | `Array` `Greedy` | Farthest Reach |
| 70 | Climbing Stairs | 🟢 | [Link](https://leetcode.com/problems/climbing-stairs/) | [C++](solutions/70_ClimbingStairs.cpp) | `DP` `Memoization` | Count Ways Recurrence |
| 76 | Minimum Window Substring | 🔴 | [Link](https://leetcode.com/problems/minimum-window-substring/) | [C++](solutions/76_MinimumWindowSubstring.cpp) | `SlidingWindow` `Hashing` | Sliding Window (Frequency Tracking) |
| 91 | Decode Ways | 🟡 | [Link](https://leetcode.com/problems/decode-ways/) | [C++](solutions/91_DecodeWays.cpp) | `DP` `String` `Recursion` | Memoization (1-step / 2-step transitions) |
| 110 | Balanced Binary Tree | 🟢 | [Link](https://leetcode.com/problems/balanced-binary-tree/) | [C++](solutions/110_BalancedBinaryTree.cpp) | `Tree` `DFS` | Height Checking During DFS |
| 121 | Best Time to Buy and Sell Stock | 🟢 | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](solutions/121_BestTimeToBuyAndSellStock.cpp) | `Array` `Greedy` | Single Pass (Track Min & Max) |
| 125 | Valid Palindrome | 🟢 | [Link](https://leetcode.com/problems/valid-palindrome/) | [C++](solutions/125_ValidPalindrome.cpp) | `String` `TwoPointers` | Filter + Two-Pointer Check |
| 128 | Longest Consecutive Sequence | 🟡 | [Link](https://leetcode.com/problems/longest-consecutive-sequence/) | [C++](solutions/128_LongestConsecutiveSequence.cpp) | `Array` `HashTable` | Hash Set + Sequence Start Detection |
| 198 | House Robber | 🟡 | [Link](https://leetcode.com/problems/house-robber/) | [C++](solutions/198_HouseRobber.cpp) | `DP` `Memoization` | Top-Down Recursion |
| 200 | Number of Islands | 🟡 | [Link](https://leetcode.com/problems/number-of-islands/) | [C++](solutions/200_NumberOfIslands.cpp) | `Matrix` `DFS` | DFS Flood Fill |
| 207 | Course Schedule | 🟡 | [Link](https://leetcode.com/problems/course-schedule/) | [C++](solutions/207_CourseSchedule.cpp) | `Graph` `BFS` `TopologicalSort` | Kahn’s Algorithm |
| 213 | House Robber II | 🟡 | [Link](https://leetcode.com/problems/house-robber-ii/) | [C++](solutions/213_HouseRobberII.cpp) | `DP` `Memoization` | Break Cycle into Two Linear DP |
| 217 | Contains Duplicate | 🟢 | [Link](https://leetcode.com/problems/contains-duplicate/) | [C++](solutions/217_ContainsDuplicate.cpp) | `Array` `HashTable` | Seen Before Check |
| 238 | Product of Array Except Self | 🟡 | [Link](https://leetcode.com/problems/product-of-array-except-self/) | [C++](solutions/238_ProductOfArrayExceptSelf.cpp) | `Array` `PrefixSum` | Prefix & Suffix Product |
| 242 | Valid Anagram | 🟢 | [Link](https://leetcode.com/problems/valid-anagram/) | [C++](solutions/242_ValidAnagram.cpp) | `Array` `String` | Frequency Counting |
| 261 | Graph Valid Tree | 🟡 | [LeetCode](https://leetcode.com/problems/graph-valid-tree/) [NeetCode](https://neetcode.io/problems/valid-tree) | [C++](solutions/261_GraphValidTree.cpp) | `Graph` `DFS` | DFS + Cycle Detection |
| 269 | Alien Dictionary | 🔴 | [LeetCode](https://leetcode.com/problems/alien-dictionary/) [NeetCode](https://neetcode.io/problems/foreign-dictionary) | [C++](solutions/269_AlienDictionary.cpp) | `Graph` `BFS` `TopologicalSort` | Kahn’s Algorithm |
| 271 | Encode and Decode Strings | 🟡 | [LeetCode](https://leetcode.com/problems/encode-and-decode-strings/) [NeetCode](https://neetcode.io/problems/string-encode-and-decode) | [C++](solutions/271_EncodeAndDecodeStrings.cpp) | `String` `Design` | Length Prefix Encoding |
| 295 | Find Median from Data Stream | 🔴 | [Link](https://leetcode.com/problems/find-median-from-data-stream/) | [C++](solutions/295_FindMedianFromDataStream.cpp) | `Heap` `DataStream` | Two Heaps (Balance Partition) |
| 322 | Coin Change | 🟡 | [Link](https://leetcode.com/problems/coin-change/) | [C++](solutions/322_CoinChange.cpp) | `DP` `Recursion` `Knapsack` | Unbounded Knapsack + Memoization |
| 323 | Number of Connected Components in an Undirected Graph | 🟡 | [LeetCode](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) [NeetCode](https://neetcode.io/problems/count-connected-components) | [C++](solutions/323_NumberOfConnectedComponents.cpp) | `Graph` `DSU` | Disjoint Set Union |
| 337 | House Robber III | 🟡 | [Link](https://leetcode.com/problems/house-robber-iii/) | [C++](solutions/337_HouseRobberIII.cpp) | `Tree` `DP` `DFS` | Tree DP (Take / Skip State) |
| 347 | Top K Frequent Elements | 🟡 | [Link](https://leetcode.com/problems/top-k-frequent-elements/) | [C++](solutions/347_TopKFrequentElements.cpp) | `Hashing` `Heap` | Hash Map + Max Heap |
| 417 | Pacific Atlantic Water Flow | 🟡 | [Link](https://leetcode.com/problems/pacific-atlantic-water-flow/) | [C++](solutions/417_PacificAtlanticWaterFlow.cpp) | `Matrix` `DFS` | Reverse DFS from Borders |
| 424 | Longest Repeating Character Replacement | 🟡 | [Link](https://leetcode.com/problems/longest-repeating-character-replacement/) | [C++](solutions/424_LongestRepeatingCharacterReplacement.cpp) | `SlidingWindow` `Hashing` | Sliding Window (Frequency Tracking) |
| 525 | Contiguous Array | 🟡 | [Link](https://leetcode.com/problems/contiguous-array/) | [C++](solutions/525_ContiguousArray.cpp) | `Array` `PrefixSum` `HashTable` | Prefix Sum Hashing |
| 647 | Palindromic Substrings | 🟡 | [Link](https://leetcode.com/problems/palindromic-substrings/) | [C++](solutions/647_PalindromicSubstrings.cpp) | `String` `DP` `Memoization` | Palindrome DP on Substrings |
| 799 | Champagne Tower | 🟡 | [Link](https://leetcode.com/problems/champagne-tower/) | [C++](solutions/799_ChampagneTower.cpp) | `DP` `Simulation` | Row-by-Row Flow Simulation |
| 930 | Binary Subarrays With Sum | 🟡 | [Link](https://leetcode.com/problems/binary-subarrays-with-sum/) | [C++](solutions/930_BinarySubarraysWithSum.cpp) | `Array` `PrefixSum` `HashTable` | Contribution Counting via Prefix Sum |
| 1382 | Balance a Binary Search Tree | 🟡 | [Link](https://leetcode.com/problems/balance-a-binary-search-tree/) | [C++](solutions/1382_BalanceABinarySearchTree.cpp) | `Tree` `BST` `DFS` `Divide & Conquer` | Inorder + Build from Sorted Array |
| 1513 | Number of Substrings With Only 1s | 🟡 | [Link](https://leetcode.com/problems/number-of-substrings-with-only-1s/) | [C++](solutions/1513_NumberOfSubstringsWithOnly1s.cpp) | `String` `Math` `Prefix Sum` | Consecutive Ones Contribution |
| 1524 | Number of Sub-arrays With Odd Sum | 🟡 | [Link](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/) | [C++](solutions/1524_NumberOfSubarraysWithOddSum.cpp) | `Prefix Sum` `Parity` `HashTable` | Prefix Parity Counting |
| 1653 | Minimum Deletions to Make String Balanced | 🟡 | [Link](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/) | [C++](solutions/1653_MinimumDeletionsToMakeStringBalanced.cpp) | `String` `PrefixSum` | Prefix-Suffix Cut Minimization |
| 2348 | Number of Zero-Filled Subarrays | 🟡 | [Link](https://leetcode.com/problems/number-of-zero-filled-subarrays/) | [C++](solutions/2348_NumberOfZeroFilledSubarrays.cpp) | `Array` `Math` `Counting` | Contribution Counting |
| 3379 | Transformed Array | 🟢 | [Link](https://leetcode.com/problems/transformed-array/) | [C++](solutions/3379_TransformedArray.cpp) | `Array` `Simulation` | Index Mapping with Modulo |
| 3634 | Minimum Removals to Balance Array | 🟡 | [Link](https://leetcode.com/problems/minimum-removals-to-balance-array/) | [C++](solutions/3634_MinimumRemovalsToBalanceArray.cpp) | `TwoPointers` `SlidingWindow` `Sorting` | Sliding Window on Sorted Array |
| 3713 | Longest Balanced Substring I | 🟡 | [Link](https://leetcode.com/problems/longest-balanced-substring-i/) | [C++](solutions/3713_LongestBalancedSubstringI.cpp) | `String` `Array` `Frequency` `BruteForce` | Equal Frequency Invariant (distinct × freq = length) |
| 3714 | Longest Balanced Substring II | 🟡 | [Link](https://leetcode.com/problems/longest-balanced-substring-ii/) | [C++](solutions/3714_LongestBalancedSubstringII.cpp) | `String` `PrefixSum` `HashTable` | Frequency Difference Prefix Hashing |
| 3719 | Longest Balanced Subarray I | 🟡 | [Link](https://leetcode.com/problems/longest-balanced-subarray-i/) | [C++](solutions/3719_LongestBalancedSubarrayI.cpp) | `Array` `HashTable` `BruteForce` | Distinct Even-Odd Frequency Matching |

---