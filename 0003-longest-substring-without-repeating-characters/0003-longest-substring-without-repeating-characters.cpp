class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);  // Initialize all characters as not seen

        int l = 0, r = 0, maxlen = 0;
        while (r < s.size()) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;  // move left pointer to avoid repeat
            }
            maxlen = max(maxlen, r - l + 1);  // update max length
            hash[s[r]] = r; 
            r++;
        }
        return maxlen;
    }
};
