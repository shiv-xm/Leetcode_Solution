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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    int checkHeight(TreeNode* node){
        if(!node) return 0;
        int lh = checkHeight(node->left);
        int rh = checkHeight(node->right);
        if(lh == -1 || rh == -1 || abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }
};