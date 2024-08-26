class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string, int> countMap;
        for (const string& str : arr) {
            countMap[str]++;
        }
        
        vector<string> distinctStrings;
        for (const string& str : arr) {
            if (countMap[str] == 1) {
                distinctStrings.push_back(str);
            }
        }
        
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        } 
    }
};