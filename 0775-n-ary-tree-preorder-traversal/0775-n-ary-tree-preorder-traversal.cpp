/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr)
            return;

        result.push_back(node->val); 
        for (Node* child : node->children)
            preorderHelper(child, result); 
    }
};
