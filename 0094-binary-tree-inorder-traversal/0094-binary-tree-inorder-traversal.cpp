/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return; 
        inorder(root->left, result);  // Traverse left subtree
        result.push_back(root->val);   // Visit the current node
        inorder(root->right, result); // Traverse right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;          // Vector to store the result
        inorder(root, result);       // Start the recursive traversal
        return result;               // Return the final result
    }
};
