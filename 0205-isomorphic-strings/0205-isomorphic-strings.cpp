class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int mapS[256] = {0}; 
        int mapT[256] = {0}; 
        
        for (int i = 0; i < s.length(); ++i) {
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};
