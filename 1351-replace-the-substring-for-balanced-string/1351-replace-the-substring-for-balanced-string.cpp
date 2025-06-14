class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int k = n / 4;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        
        // If already balanced
        if (count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k)
            return 0;

        int res = n;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            count[s[right]]--;
            while (left < n && count['Q'] <= k && count['W'] <= k &&
                   count['E'] <= k && count['R'] <= k) {
                res = min(res, right - left + 1);
                count[s[left++]]+=1;
            }
        }
        return res;
    }
};