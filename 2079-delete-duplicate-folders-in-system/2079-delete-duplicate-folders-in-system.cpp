#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    string name;
    unordered_map<string, Node*> children;
    string signature;

    Node(string name) : name(name) {}
    ~Node() {
        for (auto& [_, child] : children) {
            delete child;
        }
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        
        for (const auto& path : paths) {
            Node* curr = root;
            for (const string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new Node(folder);
                }
                curr = curr->children[folder];
            }
        }

        unordered_map<string, int> signatureCount;
        generateSignatures(root, signatureCount);

        vector<vector<string>> result;
        vector<string> currentPath;

        for (const auto& [_, child] : root->children) {
            collectValidPaths(child, currentPath, result, signatureCount);
        }

        delete root;  
        return result;
    }

private:
    void generateSignatures(Node* node, unordered_map<string, int>& signatureCount) {
        if (node->children.empty()) {
            node->signature = "";
            return;
        }

        vector<string> childSignatures;
        for (auto& [name, child] : node->children) {
            generateSignatures(child, signatureCount);
            childSignatures.push_back(name + "(" + child->signature + ")");
        }

        sort(childSignatures.begin(), childSignatures.end());
        node->signature.clear();
        for (const string& sig : childSignatures) {
            node->signature += sig;
        }

        signatureCount[node->signature]++;
    }

    void collectValidPaths(Node* node, vector<string>& currentPath,
                           vector<vector<string>>& result,
                           unordered_map<string, int>& signatureCount) {
        if (!node->signature.empty() && signatureCount[node->signature] > 1) {
            return;
        }

        currentPath.push_back(node->name);
        result.push_back(currentPath);

        for (auto& [_, child] : node->children) {
            collectValidPaths(child, currentPath, result, signatureCount);
        }

        currentPath.pop_back();  
    }
};
