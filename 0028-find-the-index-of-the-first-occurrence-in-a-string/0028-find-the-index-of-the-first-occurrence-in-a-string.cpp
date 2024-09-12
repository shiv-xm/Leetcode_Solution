class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: If needle is empty, return 0 
        if (needle.empty()) {
            return 0;
        }
        
        int n = haystack.size();
        int m = needle.size();
        
        // Sliding window: iterate through haystack and compare substrings
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;  // Found the first occurrence
            }
        }
        
        return -1;  // If needle is not found in haystack
    }
};
