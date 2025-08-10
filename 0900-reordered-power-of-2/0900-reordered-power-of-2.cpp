class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for (int k = 0; k < 31; k++) {
            long long x = 1LL << k; 
            string t = to_string(x);
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        return false;
    }
};
