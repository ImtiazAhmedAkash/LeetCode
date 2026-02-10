#include <bits/stdc++.h>
using namespace std;

/*
Problem: Balance a Binary Search Tree
LeetCode Link: https://leetcode.com/problems/balance-a-binary-search-tree/
Difficulty: 🟡 Medium
Tags: Tree, BST, DFS, Divide & Conquer
Techniques: Inorder Traversal + Build Balanced BST from Sorted Array

Guiding Questions:
- What property of a BST can I exploit to simplify the problem?
- How can I extract all values in sorted order from a BST efficiently?
- Once I have a sorted array, how do I construct a height-balanced BST?

Main Idea / Approach:
- Perform an inorder traversal of the BST and store values in a vector.
  (Inorder traversal of a BST produces a sorted array.)
- Construct a balanced BST from the sorted array:
  - Choose the middle element as the root.
  - Recursively build the left subtree from the left half of the array.
  - Recursively build the right subtree from the right half of the array.
- Return the constructed tree as the new balanced BST.

Time Complexity: O(n) — each node is visited once in traversal and once in construction
Space Complexity: O(n) — vector to store inorder values + recursion stack
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
    void inOrderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;

        inOrderTraversal(root->left, values);
        values.push_back(root->val);
        inOrderTraversal(root->right, values);
    }

    TreeNode* buildBalancedBST(int left, int right, vector<int>& values) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = buildBalancedBST(left, mid - 1, values);
        root->right = buildBalancedBST(mid + 1, right, values);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inOrderTraversal(root, values);

        int n = values.size();
        return buildBalancedBST(0, n - 1, values);
    }
};