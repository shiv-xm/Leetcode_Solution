class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       unordered_map<string, int> freq;
        int result = 0;
        bool centerUsed = false;

        for (auto& w : words) {
            freq[w]++;
        }

        for (auto& [w, count] : freq) {
            string rev = string{w[1], w[0]};
            if (w == rev) { 
                result += (count / 2) * 4;
                if (!centerUsed && count % 2 == 1) {
                    result += 2;
                    centerUsed = true;
                }
            } else if (freq.count(rev) && w < rev) {
                result += 4 * min(count, freq[rev]);
            }
        }

        return result; 
    }
};