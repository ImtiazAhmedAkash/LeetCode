#include <bits/stdc++.h>
using namespace std;

/*
Problem: House Robber III
LeetCode Link: https://leetcode.com/problems/house-robber-iii/
Difficulty: 🟡 Medium
Tags: Tree, DP, DFS
Techniques: Tree DP (Take / Skip State)

Guiding Questions:
- If I rob a house, which houses become unavailable?
- How does a parent node affect its children in a tree?
- Can a single value per node fully describe the decision?

Main Idea / Approach:
- Each node (house) gives two possible states:
    1) Skip this node
    2) Rob this node
- Therefore, instead of storing one DP value per node,
  we store TWO values:
      skip → maximum money if we do NOT rob this node
      take → maximum money if we DO rob this node

Transitions:
- If we rob current node:
      we cannot rob its children
      take = root->val + left.skip + right.skip
- If we skip current node:
      children may be robbed or skipped
      skip = max(left.skip, left.take) + max(right.skip, right.take)

- Return both values as a pair for each node.

Final Answer:
- The root can either be robbed or skipped.
- Return max(skip, take).

Time Complexity: O(n) — each node visited once
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
    pair<int, int> findMaxProfit(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        pair<int, int> left = findMaxProfit(root->left);
        pair<int, int> right = findMaxProfit(root->right);

        int skip = max(left.first, left.second) + max(right.first, right.second);
        int take = root->val + left.first + right.first;

        return {skip, take};
    }

    int rob(TreeNode* root) {
        auto [skip, take] = findMaxProfit(root);
        return max(skip, take);
    }
};