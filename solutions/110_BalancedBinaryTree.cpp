#include <bits/stdc++.h>
using namespace std;

/*
Problem: Balanced Binary Tree
LeetCode Link: https://leetcode.com/problems/balanced-binary-tree/
Difficulty: 🟢 Easy
Tags: Tree, DFS
Techniques: Height Checking During DFS

Guiding Questions:
- How can I check whether every node satisfies the height balance condition?
- Do I need to recompute the height for each node separately?
- Can a recursive function communicate failure to its parent?

Main Idea / Approach:
- Perform a postorder DFS (left → right → node).
- For each node, compute the height of its left and right subtrees.
- If any subtree is already unbalanced, immediately propagate failure upward using a sentinel value (-1).
- If the difference between left and right subtree heights is greater than 1, mark the current node as unbalanced by returning -1.
- Otherwise return 1 + max(leftDepth, rightDepth).

Time Complexity: O(n) — each node is visited once
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
    int findDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftDepth = findDepth(node->left);
        if (leftDepth == -1) return -1;

        int rightDepth = findDepth(node->right);
        if (rightDepth == -1) return -1;
        
        if (abs(leftDepth - rightDepth) > 1) return -1;

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        return (findDepth(root) != -1);
    }
};