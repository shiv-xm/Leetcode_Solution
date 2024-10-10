class Solution {
public:
   TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
      if (left > right) return nullptr;
       
        int mid = left + (right - left) / 2;
        
        // Create a new node with the middle element
        TreeNode* node = new TreeNode(nums[mid]);
        
        // Recursively build the left subtree using the left half of the array
        node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        
        // Recursively build the right subtree using the right half of the array
        node->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        
        // Return the node as the root of this subtree
        return node;
    }
    
    // Main function to convert sorted array to height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function with the full range of the array
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};