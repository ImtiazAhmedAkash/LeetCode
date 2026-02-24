#include <bits/stdc++.h>
using namespace std;

/*
Problem: Sum of Root To Leaf Binary Numbers
LeetCode Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
Difficulty: 🟢 Easy
Tags: Tree, DFS, BitManipulation
Techniques: Build Number During DFS

Guiding Questions:
- How do we interpret a root-to-leaf path as a binary number?
- How can we construct the number while traversing the tree?
- Can we avoid storing the entire path?

Main Idea / Approach:
- Each root-to-leaf path represents a binary number.
  Example:
      Path: 1 → 0 → 1
      Binary: 101₂ = 5

- While doing DFS, we carry a running value `curVal`:
      Moving to a child = shifting left (multiply by 2)
      Add node value (0 or 1)

      curVal = curVal * 2 + node->val

- When we reach a leaf node:
      The constructed value is a complete binary number.
      Add it to the total sum.

- Recursively compute sum from left and right subtrees.

Time Complexity: O(n) — visit each node once
Space Complexity: O(h) — recursion stack (tree height)
*/

//--------------------  Definition for a binary tree node. -------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//----------------------------------------------------------------------------------------

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int curVal = 0) {
        curVal = curVal * 2 + root->val;

        if (!root->left && !root->right) {
            return curVal;
        }
        
        int left = 0, right = 0;
        if (root->left)  left  = sumRootToLeaf(root->left, curVal);
        if (root->right) right = sumRootToLeaf(root->right, curVal);

        return left + right;
    }
};