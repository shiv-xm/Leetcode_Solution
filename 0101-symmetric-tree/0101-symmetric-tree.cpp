class Solution {
public:
    
    bool isMirror(TreeNode* leftTree, TreeNode* rightTree) {
        if (leftTree == nullptr && rightTree == nullptr) return true;
        if (leftTree == nullptr || rightTree == nullptr) return false;
        return (leftTree->val == rightTree->val) 
            && isMirror(leftTree->left, rightTree->right) 
            && isMirror(leftTree->right, rightTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
