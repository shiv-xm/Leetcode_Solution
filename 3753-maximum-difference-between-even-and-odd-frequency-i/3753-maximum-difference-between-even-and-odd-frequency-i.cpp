class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        
        for (char c : s) {
            freq[c]++;
        }
        
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        
        for (auto &entry : freq) {
            if (entry.second % 2 != 0) {
                maxOdd = max(maxOdd, entry.second);
            } else {
                minEven = min(minEven, entry.second);
            }
        }

        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return 0;
        }

        return maxOdd - minEven;
    }
};
